# 📕 Lexique C++ — Partie 2 : Exceptions, Conversions, Templates & STL

> Suite de la [Partie 1 — Lexique de la POO](lexique_poo_cpp.md).
> La Partie 1 pose les **fondations** (classe, héritage, polymorphisme, abstraction). Cette Partie 2 couvre les **mécanismes** qu'on construit par-dessus : gestion d'erreurs, conversions de type, généricité, conteneurs.

**Classe d'exemple utilisée** : `Animal` — la même que dans la Partie 1, pour la continuité. Tu peux mentalement la remplacer par n'importe quelle classe. Les concepts sont **universels** ; les exercices 42 où ils apparaissent sont cités dans les encadrés 🚀.

**Convention typographique du document** (identique à la Partie 1) :

| Emoji | Sens |
|---|---|
| 📘 | Définition |
| 🎬 | Exemple complet |
| 🎨 | Métaphore |
| 🧠 | Mnémotechnique |
| ⚠️ | Piège classique |
| 🔍 | Règle pratique / tableau |
| 🚀 | Aperçu / lien avec un exercice 42 |

---

## 📑 Table des matières

**Gestion des erreurs — les exceptions**
1. [Le mécanisme d'exception (vue d'ensemble)](#-le-mécanisme-dexception-vue-densemble)
2. [`throw` — lever une exception](#-throw--lever-une-exception)
3. [`try` / `catch` — attraper une exception](#-try--catch--attraper-une-exception)
4. [`std::exception` et la méthode `what()`](#-stdexception-et-la-méthode-what)
5. [Créer ses propres exceptions](#-créer-ses-propres-exceptions)
6. [La spécification `throw()` (C++98)](#-la-spécification-throw-c98)
7. [Catch par référence et catch polymorphique](#-catch-par-référence-et-catch-polymorphique)
8. [Le déroulement de la pile (stack unwinding) et RAII](#-le-déroulement-de-la-pile-stack-unwinding-et-raii)
9. [Règle d'or : jamais d'exception hors d'un destructeur](#-règle-dor--jamais-dexception-hors-dun-destructeur)

**Outils de conception**
10. [Pointeurs de fonction](#-pointeurs-de-fonction)

**À venir**
- Conversions de type (`static_cast`, `dynamic_cast`, `reinterpret_cast`, `const_cast`)
- Généricité (templates de fonction et de classe)
- Conteneurs, itérateurs et algorithmes (la STL)

**Annexes**
- [Termes complémentaires](#-termes-complémentaires)
- [Quiz d'auto-évaluation](#-quiz-dauto-évaluation)

---

## 🎯 Le mécanisme d'exception (vue d'ensemble)

📘 Une **exception** est un mécanisme du C++ pour **signaler une erreur** à un endroit du code et la **traiter** ailleurs, sans polluer toutes les fonctions intermédiaires avec des codes de retour.

### 🤔 Le problème qu'on résout

En C, pour signaler une erreur, on renvoie un code (`-1`, `NULL`, `errno`...). Chaque appelant **doit** vérifier à la main, et l'information se perd vite.

```cpp
// Style C : on pollue tout le code de vérifications
int err = setAge(rex, -5);
if (err == -1) { /* gérer ici, et à CHAQUE appel... */ }
```

Avec les exceptions, on **sépare** le code normal du code de gestion d'erreur :

```cpp
try {
    Animal rex("Rex", -5);   // un âge négatif n'a pas de sens → throw
    // ... suite du code "heureux", lisible, sans if d'erreur partout
}
catch (std::exception& e) {
    std::cout << e.what() << std::endl;   // gestion centralisée
}
```

🎨 **Métaphore** : une exception, c'est une **alarme incendie**. Celui qui détecte le feu (le `throw`) ne sait pas qui réagira : il déclenche l'alarme. Le signal **remonte** les étages jusqu'à ce que quelqu'un d'équipé (le `catch`) s'en occupe. Entre les deux, tout le monde évacue proprement (les destructeurs sont appelés — voir [stack unwinding](#-le-déroulement-de-la-pile-stack-unwinding-et-raii)).

### 🧩 Les 3 mots-clés

| Mot-clé | Rôle | Phrase mentale |
|---|---|---|
| `throw` | **Lève** l'exception : « il y a un problème ! » | *« Je lance l'alarme »* |
| `try` | **Délimite** la zone surveillée | *« Je surveille ce bloc »* |
| `catch` | **Attrape** et traite l'exception | *« Je gère le problème »* |

🧠 **Mnémotechnique** : **« TTC »** comme une facture — **T**ry, **T**hrow, **C**atch.

🚀 **Où ça apparaît en 42** : le CPP05 (« Repetition and Exceptions ») est entièrement bâti là-dessus — un `Bureaucrat` ou un `Form` au grade invalide doit **throw**.

---

## 💥 `throw` — lever une exception

📘 `throw expr;` **interrompt immédiatement** l'exécution de la fonction courante et **remonte** jusqu'au premier `catch` capable de traiter le type de `expr`.

```cpp
Animal::Animal(std::string name, int age) : _name(name)
{
    if (age < 0)
        throw InvalidAgeException();   // ← interrompt le constructeur ICI
    _age = age;                         // jamais atteint si on a throw
}
```

### 🔑 Ce qu'il faut comprendre

- **`throw` arrête tout** : les lignes après le `throw` (dans la même fonction) **ne s'exécutent pas**.
- On peut lancer **n'importe quel type** (un `int`, une `std::string`...), mais la **bonne pratique** est de lancer un **objet dérivé de `std::exception`** (voir plus bas).
- `throw InvalidAgeException();` **construit** un objet exception temporaire et le lance.

### ⚠️ Piège : un `throw` dans un constructeur

Si un constructeur `throw`, l'objet **n'est jamais considéré comme construit** → son **destructeur ne sera PAS appelé**. En revanche, les attributs **déjà construits** avant le `throw` sont, eux, détruits proprement.

```cpp
Animal rex("Rex", -5);   // throw dans le ctor
// → rex n'existe PAS. ~Animal() n'est pas appelé pour rex.
//   (mais _name, déjà construit, est bien détruit)
```

🚀 **Contexte 42** : instancier un `Bureaucrat`/`Form` avec un grade hors bornes [1..150] doit **throw** — l'objet n'est donc pas créé.

---

## 🛡️ `try` / `catch` — attraper une exception

📘 Le bloc `try { ... }` délimite le code **surveillé**. Si une exception est levée dedans (directement ou dans une fonction appelée), le `catch` correspondant l'**intercepte**.

```cpp
try
{
    Animal rex("Rex", -5);          // throw InvalidAgeException
    std::cout << "jamais affiché" << std::endl;
}
catch (std::exception& e)           // attrape l'exception
{
    std::cout << "Erreur : " << e.what() << std::endl;
}
// le programme CONTINUE ici, normalement
```

### 🔑 Mécanisme détaillé

1. Le code dans `try` s'exécute normalement.
2. Dès qu'un `throw` survient, le reste du `try` est **abandonné**.
3. Le programme cherche un `catch` dont le **type correspond** à l'exception.
4. Le code du `catch` s'exécute, puis l'exécution **reprend après** le bloc `try/catch`.
5. Si **aucun** `catch` ne correspond nulle part → `std::terminate()` → le programme **crashe** (`abort`).

### 🔗 Plusieurs `catch` en cascade

On peut enchaîner plusieurs `catch` pour traiter différents types. Le **premier qui correspond** gagne.

```cpp
try {
    rex.setAge(value);
}
catch (Animal::InvalidAgeException& e) {   // cas spécifique d'abord
    std::cout << "Âge invalide : " << e.what() << std::endl;
}
catch (std::exception& e) {                 // cas général ensuite
    std::cout << "Autre erreur : " << e.what() << std::endl;
}
```

⚠️ **Ordre crucial** : mets le **plus spécifique en premier**, le **plus général en dernier**. Un `catch (std::exception&)` placé en premier attraperait **tout** (voir [catch polymorphique](#-catch-par-référence-et-catch-polymorphique)), rendant les `catch` suivants inaccessibles.

---

## 📛 `std::exception` et la méthode `what()`

📘 `std::exception` (header `<exception>`) est la **classe de base** de toute la hiérarchie d'exceptions standard. Elle expose **une** méthode virtuelle clé :

```cpp
virtual const char* what() const throw();
```

`what()` renvoie une **chaîne C** (`const char*`) qui **décrit** l'erreur. C'est le message qu'on affiche.

### 🎯 Pourquoi hériter de `std::exception` ?

Parce que ça permet d'attraper **toutes** tes exceptions (et celles de la STL) avec **un seul** `catch (std::exception& e)`. C'est la base du [catch polymorphique](#-catch-par-référence-et-catch-polymorphique).

```cpp
catch (std::exception& e) {        // attrape TOUT ce qui dérive de std::exception
    std::cout << e.what() << std::endl;
}
```

🔍 **Quelques exceptions standard** (culture générale) :

| Exception | Header | Levée quand... |
|---|---|---|
| `std::exception` | `<exception>` | base de toutes les autres |
| `std::bad_alloc` | `<new>` | `new` échoue (plus de mémoire) |
| `std::out_of_range` | `<stdexcept>` | accès `.at()` hors bornes |
| `std::logic_error` / `std::runtime_error` | `<stdexcept>` | familles d'erreurs prêtes à l'emploi |

---

## 🏗️ Créer ses propres exceptions

📘 Une exception personnalisée est simplement une **classe qui hérite de `std::exception`** et qui **redéfinit `what()`**. On la déclare souvent comme **classe imbriquée** (`nested class`) à l'intérieur de la classe concernée, quand elle n'a de sens que dans ce contexte.

```cpp
// Animal.hpp
class Animal {
public:
    // ... le reste de la classe ...

    class InvalidAgeException : public std::exception {
    public:
        virtual const char* what() const throw();
    };
};
```

```cpp
// Animal.cpp
const char* Animal::InvalidAgeException::what() const throw() {
    return "Animal age is invalid";
}
```

### 🔑 Pourquoi une classe *imbriquée* ?

- **Logique** : `InvalidAgeException` n'a de sens que **dans le contexte** d'un `Animal`. L'imbriquer exprime cette appartenance.
- **Nommage** : on l'utilise via `Animal::InvalidAgeException`, ce qui évite les collisions de noms avec d'autres exceptions du projet.

🎨 **Métaphore** : c'est comme un type de panne **propre à une marque**. « Erreur moteur Renault » a du sens écrit `Renault::ErreurMoteur` — on sait tout de suite de quoi on parle.

### ⚠️ L'exception N'A PAS besoin de la forme canonique (OCF)

C'est l'**unique** classe que les sujets 42 dispensent de l'[OCF](lexique_poo_cpp.md#-la-forme-canonique-orthodoxe-orthodox-canonical-form-ocf) (que la Partie 1 impose partout ailleurs) :

> *« exception classes do not have to be designed in Orthodox Canonical Form. »*

Une exception ne stocke (souvent) aucune donnée à copier proprement — pas besoin de constructeur de copie / `operator=` explicites.

🧠 **Mnémotechnique** : *« Une exception : juste `what()`, rien d'autre d'obligatoire. »*

🚀 **Contexte 42** : au CPP05, `Bureaucrat::GradeTooHighException` et `Bureaucrat::GradeTooLowException` suivent exactement ce patron.

---

## 📜 La spécification `throw()` (C++98)

📘 Le `throw()` à la **fin** d'une signature est une **spécification d'exception** (héritée du C++98). Elle annonce : *« cette fonction ne lèvera **aucune** exception. »*

```cpp
const char* what() const throw();
//                ↑       ↑
//          const méthode  ← "ne throw rien"
```

### 🔍 Ne pas confondre les deux usages de `throw`

| Forme | Où | Sens |
|---|---|---|
| `throw expr;` | dans le **corps** | **lève** une exception |
| `... ) const throw();` | **après** la signature | **promet** de ne rien lever |

C'est le même mot-clé, deux rôles **opposés** — exactement comme les deux `*` ou les deux `&` de la [Partie 1](lexique_poo_cpp.md#-les-symboles--et--en-c).

### 🎯 Pourquoi on le met sur `what()` ?

La signature de `std::exception::what()` est **exactement** `virtual const char* what() const throw();`. Pour **redéfinir** (override) correctement la méthode de base, ta signature doit **coïncider** — y compris le `throw()`.

🧠 **Mnémotechnique** : *« `what()` ne doit jamais elle-même planter → elle promet `throw()` (rien). »* Logique : on ne veut pas qu'afficher un message d'erreur déclenche une **nouvelle** erreur.

⚠️ **C++11+** : `throw()` est **déprécié** au profit de `noexcept`. Mais les sujets imposent `-std=c++98`, donc on écrit **`throw()`**. À connaître, à ne pas remplacer ici.

---

## 🎣 Catch par référence et catch polymorphique

### 1️⃣ Toujours attraper **par référence**

```cpp
catch (std::exception& e)   // ✅ par référence
catch (std::exception  e)   // ❌ par valeur → slicing !
```

**Pourquoi par référence ?** Attraper **par valeur** une exception de type dérivé via la base provoque un **slicing** (voir [Partie 1](lexique_poo_cpp.md#-le-piège-du-slicing-à-éviter)) : la partie spécifique est découpée, et `what()` ne renvoie plus le bon message (celui de la base, pas du type réel).

🧠 **Mnémotechnique** : *« Catch by reference, toujours. »* (la référence préserve le **vrai type** → bon `what()`.)

### 2️⃣ Le catch **polymorphique**

📘 Un `catch (Base& e)` attrape **aussi** toutes les exceptions des classes **dérivées** de `Base`. C'est du [polymorphisme](lexique_poo_cpp.md#-polymorphisme-de-sous-type) appliqué aux exceptions.

```cpp
try {
    rex.setAge(value);   // peut throw Animal::InvalidAgeException
}
catch (std::exception& e) {   // InvalidAgeException EST-UNE std::exception → attrapée
    std::cout << e.what() << std::endl;
}
```

Comme l'exception hérite de `std::exception`, un seul `catch (std::exception&)` suffit pour **tout** intercepter. Et grâce au `virtual` sur `what()`, c'est la **bonne version** du message qui s'affiche (liaison dynamique → [vtable](lexique_poo_cpp.md#️-comment-ça-marche-la-vtable)).

🔍 **Conséquence sur l'ordre des `catch`** :

| Ordre | Effet |
|---|---|
| Spécifique → général | ✅ chaque cas traité correctement |
| Général (`std::exception`) en premier | ⚠️ il attrape tout, les `catch` suivants sont **morts** |

---

## 🧹 Le déroulement de la pile (stack unwinding) et RAII

📘 Le **stack unwinding** (« déroulement de la pile ») est le processus par lequel, entre le `throw` et le `catch`, le C++ **détruit proprement tous les objets locaux** des scopes qu'il quitte.

```cpp
void process() {
    Animal rex("Rex", 3);       // objet local sur la pile
    riskyOperation();           // throw ici
    // ... pas atteint ...
}                               // pendant la remontée, ~Animal() de rex EST appelé
```

Quand `riskyOperation()` lève une exception, en remontant vers le `catch`, le destructeur de `rex` est **garanti** d'être appelé. C'est ce qui rend les exceptions **sûres** : pas de fuite de ressources allouées sur la pile.

🎨 **Métaphore** (suite de l'alarme incendie) : pendant que l'alarme remonte les étages, **chaque personne évacue en fermant sa porte derrière elle** (destructeur). Rien n'est laissé en plan.

### 🔗 Lien avec RAII

📘 **RAII** (*Resource Acquisition Is Initialization*) : un objet **acquiert** sa ressource dans son constructeur et la **libère** dans son destructeur. Comme le destructeur est appelé pendant le stack unwinding, **RAII + exceptions = pas de fuite**, même en cas d'erreur.

```cpp
// std::ifstream est un objet RAII : il ferme le fichier dans son destructeur
void readFile() {
    std::ifstream file("data.txt");   // ouvre
    parse(file);                       // si throw ici...
}                                      // ...file est quand même fermé (destructeur)
```

⚠️ **Piège du `new` brut** : un pointeur brut **n'est pas** RAII. Si tu fais `new` puis qu'un `throw` survient avant le `delete`, **tu fuis**.

```cpp
void leak() {
    Animal* a = new Animal();   // sur le tas
    riskyOperation();           // throw → 'a' n'est JAMAIS delete → fuite !
    delete a;                   // jamais atteint
}
```

🔍 **Solution sûre** : libère **avant** tout `throw` potentiel, ou encadre le `new`/`delete` dans un `try/catch` qui `delete` puis relance. (Hors 42 C++98, on utiliserait un *smart pointer*.)

🧠 **Mnémotechnique** : *« La pile se nettoie toute seule ; le tas, c'est à toi. »* (écho direct de [Stack vs Heap](lexique_poo_cpp.md#️-stack-vs-heap-pile-vs-tas).)

---

## 🚷 Règle d'or : jamais d'exception hors d'un destructeur

📘 Un destructeur ne doit **jamais laisser s'échapper** une exception.

**Pourquoi ?** Pendant un stack unwinding (déjà déclenché par une première exception), si un destructeur en lève une **deuxième**, le C++ ne sait pas laquelle traiter → il appelle directement `std::terminate()` → **crash immédiat**, sans recours.

```cpp
~Animal() {
    throw std::exception();   // ❌ TRÈS dangereux : peut tuer le programme
}
```

🧠 **Mnémotechnique** : *« On meurt en silence. »* Un destructeur gère ses erreurs en interne (try/catch local), il n'en propage jamais.

---

## 🔀 Pointeurs de fonction

📘 Un **pointeur de fonction** est une variable qui **stocke l'adresse d'une fonction**. On peut l'appeler comme la fonction elle-même. C'est l'outil idéal pour **remplacer une longue cascade de `if/else`** par une table de correspondance.

```cpp
void (*ptr)(int);   // ptr = pointeur vers une fonction qui prend un int et ne renvoie rien
ptr = &maFonction;  // on lui assigne l'adresse d'une fonction
ptr(42);            // on l'appelle comme une fonction normale
```

### 🎬 Le pattern « deux tableaux parallèles »

Au lieu de tester chaque cas à la main, on associe une **liste de clés** à une **liste de fabriques** et on boucle :

```cpp
// une fonction "fabrique" par type de Animal
static Animal* makeDog(std::string name)  { return new Dog(name); }
static Animal* makeCat(std::string name)  { return new Cat(name); }
static Animal* makeBird(std::string name) { return new Bird(name); }

Animal* makeAnimal(std::string type, std::string name)
{
    std::string keys[3]                  = {"Dog", "Cat", "Bird"};
    Animal* (*builders[3])(std::string)  = {&makeDog, &makeCat, &makeBird};

    for (int i = 0; i < 3; i++) {
        if (type == keys[i])
            return builders[i](name);   // appel via le pointeur de fonction
    }
    return NULL;   // type inconnu
}
```

### 🔑 Pourquoi c'est mieux qu'une cascade de `if`

- **Lisible et court** : ajouter un type = ajouter une ligne dans deux tableaux.
- **Pas de duplication** de logique (un seul `for`).
- **Évolutif (DRY)** — même esprit que la [délégation au parent](lexique_poo_cpp.md#-pourquoi-cette-approche-est-meilleure) de la Partie 1.

🧠 **Mnémotechnique** : *« Deux tableaux parallèles : les clés d'un côté, les fabriques de l'autre. »*

⚠️ **Attention mémoire** : la fabrique renvoie un objet alloué par `new`. C'est à **l'appelant** de le `delete` (relie ça au [RAII](#-le-déroulement-de-la-pile-stack-unwinding-et-raii)).

🚀 **Contexte 42** : c'est exactement la technique attendue pour `Intern::makeForm("...", "...")` au CPP05, où le sujet **interdit** la forêt de `if/else`. La fabrique renvoie un `AForm*` (pointeur sur la base abstraite) → [polymorphisme](lexique_poo_cpp.md#-polymorphisme-de-sous-type) pur.

---

## 📚 Termes complémentaires

| Terme | Définition rapide |
|---|---|
| **Exception** | Objet signalant une erreur, propagé du `throw` jusqu'au `catch` |
| **`throw`** | Lève une exception (corps) **ou** promet de ne rien lever (fin de signature) |
| **`try` / `catch`** | Délimite la zone surveillée / intercepte et traite l'exception |
| **`what()`** | Méthode virtuelle de `std::exception` renvoyant le message (`const char*`) |
| **Classe imbriquée** | Classe déclarée à l'intérieur d'une autre (`Animal::InvalidAgeException`) |
| **Spécification d'exception** | `throw()` en C++98 (≈ `noexcept` en C++11) : « ne lève rien » |
| **Catch polymorphique** | `catch (Base&)` attrape aussi toutes les classes dérivées |
| **Stack unwinding** | Destruction ordonnée des objets locaux entre `throw` et `catch` |
| **RAII** | Acquérir la ressource au constructeur, la libérer au destructeur |
| **`std::terminate`** | Fonction appelée si une exception n'est jamais attrapée → `abort` |
| **Pointeur de fonction** | Variable contenant l'adresse d'une fonction, appelable directement |

---

## 🎯 Quiz d'auto-évaluation

### Niveau 1 — Mécanisme

1. Quels sont les trois mots-clés du mécanisme d'exception et le rôle de chacun ?
2. Que se passe-t-il dans une fonction après l'exécution d'un `throw` ?
3. Que se passe-t-il si aucun `catch` ne correspond à une exception levée ?
4. De quelle classe doit hériter une exception personnalisée, et quelle méthode redéfinit-elle ?

### Niveau 2 — Subtilités

5. Que signifie le `throw()` à la **fin** de `const char* what() const throw();` ? En quoi diffère-t-il du `throw` dans le corps ?
6. Pourquoi attrape-t-on une exception **par référence** plutôt que par valeur ?
7. Dans quel ordre faut-il placer `catch (Animal::InvalidAgeException&)` et `catch (std::exception&)` ? Pourquoi ?
8. Une classe d'exception doit-elle respecter la forme canonique orthodoxe ?

### Niveau 3 — Mémoire et design

9. Qu'arrive-t-il aux objets locaux sur la pile entre un `throw` et son `catch` ?
10. Pourquoi un `new` sans `delete` est-il dangereux en présence d'exceptions, et comment s'en prémunir ?
11. Pourquoi ne faut-il jamais laisser une exception sortir d'un destructeur ?
12. Comment un tableau de pointeurs de fonction remplace-t-il une cascade de `if/else` ?

---

*Lexique C++ Partie 2 — section exceptions complète. Les chapitres conversions / templates / STL suivront. Bonne continuation, fducrot !* 🚀
