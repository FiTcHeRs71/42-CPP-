# 📘 Lexique de la Programmation Orientée Objet en C++

> Référence personnelle universelle pour la POO en C++  
> Conçu pour servir tout au long du parcours C++ et au-delà.

> **Classe d'exemple utilisée** : `Animal` — choisie parce qu'elle parle naturellement à tout le monde.  
> Tu peux mentalement remplacer `Animal` par n'importe quelle classe (`Fixed`, `User`, `Car`, `Account`...) — les concepts sont **universels**.

---

## 🏛️ Classe (*class*)

Une **classe** est un **plan de construction**, un *modèle* qui décrit :
- quelles **données** un objet de ce type contiendra,
- quelles **opérations** on pourra faire dessus.

C'est un **type de données** que **toi**, le programmeur, tu inventes.

```cpp
class Animal {
    // description de ce qu'est un Animal :
    // ses attributs (nom, âge, espèce...)
    // ses méthodes (manger, dormir, faireDuBruit...)
};
```

**Métaphore** : la classe, c'est le **moule** à gâteaux. Le moule en lui-même n'est pas un gâteau — c'est juste la forme qui dit comment fabriquer un gâteau.

---

## 🍰 Objet / Instance (*object / instance*)

Un **objet** (ou **instance**) est une **réalisation concrète** d'une classe en mémoire. C'est un exemplaire vivant du moule.

```cpp
Animal rex;         // rex est UN OBJET, UNE INSTANCE de la classe Animal
Animal whiskers;    // whiskers est UN AUTRE OBJET, UNE AUTRE INSTANCE
```

`rex` et `whiskers` sont **deux instances distinctes** de la même classe `Animal`. Elles partagent la même structure (mêmes attributs, mêmes méthodes), mais elles ont leurs **propres valeurs**.

**Métaphore** : si la classe `Animal` est le moule, alors `rex` et `whiskers` sont **deux gâteaux** différents sortis du même moule. Ils ont la même forme, mais l'un peut être au chocolat et l'autre à la vanille.

⚠️ Attention au vocabulaire : "objet" et "instance" sont **synonymes** dans 99 % des cas. Certains puristes font une nuance, mais en pratique tu peux utiliser indifféremment les deux.

---

## 🌱 Instancier (*to instantiate*)

**Instancier**, c'est l'action de **créer une instance** d'une classe. Le verbe vient directement du nom.

```cpp
Animal rex;                 // ← j'instancie Animal (sur la pile / stack)
Animal* dog = new Animal;   // ← j'instancie Animal (sur le tas / heap)
```

Quand tu écris `Animal rex;`, tu **instancies** la classe `Animal`. Tu fabriques un animal à partir du plan.

**Vocabulaire associé** : on dit aussi *"créer un objet"*, *"construire un objet"*. Le **constructeur** est d'ailleurs la fonction spéciale qui est appelée automatiquement lors de l'instanciation.

---

## 📦 Attribut / Membre de donnée (*attribute / data member / field*)

Un **attribut** est une **variable qui appartient à un objet**. C'est une donnée stockée à l'intérieur de l'instance.

```cpp
class Animal {
private:
    std::string _name;              // ← attribut
    int         _age;               // ← attribut
    static int  _populationCount;   // ← attribut (static, partagé par toute la classe)
};
```

Chaque instance possède **sa propre copie** des attributs (sauf les attributs `static`).

**Synonymes** : tu verras aussi **"champ"** (*field*), **"membre de donnée"** (*data member*), **"propriété"** (*property*, mais c'est plus du vocabulaire C# / JavaScript). En 42, on dit le plus souvent **attribut**.

**Métaphore** : si un objet `Animal` est un être vivant, ses attributs sont les **caractéristiques** stockées en lui (son nom, son âge, son poids...).

---

## 🛠️ Fonction membre / Méthode (*member function / method*)

Une **fonction membre** (ou **méthode**) est une **fonction qui appartient à une classe**. Elle peut accéder aux attributs des objets de cette classe et opère typiquement sur **un objet précis**.

```cpp
class Animal {
public:
    std::string getName(void) const;        // ← méthode (getter)
    void        setName(std::string name);  // ← méthode (setter)
    void        eat(void);                  // ← méthode (action)
    void        makeSound(void) const;      // ← méthode (action)
};
```

À l'utilisation, tu appelles une méthode **sur un objet** avec la notation point :

```cpp
Animal rex;
rex.setName("Rex");                     // appel de setName sur l'objet rex
std::string name = rex.getName();       // appel de getName sur l'objet rex
rex.makeSound();                        // appel de makeSound sur l'objet rex
```

**Synonymes** : "méthode" et "fonction membre" sont rigoureusement équivalents. Le terme **méthode** vient du monde Java/Python, **fonction membre** est le terme officiel C++. En 42, les deux sont compris.

**Métaphore** : si les attributs sont les caractéristiques de l'animal, les méthodes sont les **comportements** qu'il peut avoir : `manger()`, `dormir()`, `aboyer()`...

---

## 🔓 Public / 🔒 Private / 🛡️ Protected — La visibilité (*access specifiers*)

Ces mots-clés contrôlent **qui peut accéder à quoi** dans une classe. C'est le cœur de l'**encapsulation**.

```cpp
class Animal {
private:
    std::string _name;           // ← personne d'extérieur ne peut y toucher
    int         _age;
    
public:
    std::string getName() const; // ← tout le monde peut l'appeler
    void        eat();
    
protected:
    // accessible par les classes filles (utile en héritage)
    int _energy;
};
```

### 🔒 `private`

Membre **invisible et inaccessible depuis l'extérieur** de la classe. Seules les **méthodes de la classe elle-même** peuvent y toucher.

```cpp
Animal rex;
rex._name = "Rex";    // ❌ ERREUR : _name est private
rex.getName();        // ✅ OK : la méthode est publique, et elle a accès à _name depuis l'intérieur
```

Par défaut, dans une `class`, **tout est `private`** si tu ne précises rien.

### 🔓 `public`

Membre **accessible par tout le monde** (n'importe quel code qui possède une instance).

```cpp
Animal rex;
std::string name = rex.getName();  // ✅ OK
```

### 🛡️ `protected`

Membre accessible par la classe et ses **classes dérivées** (héritage). Tu en verras l'utilité dès que tu attaqueras l'héritage.

**Métaphore** : pense à une voiture.
- `public` : le volant, les pédales, le levier de vitesse → l'utilisateur les manipule directement.
- `private` : l'injection électronique, le calculateur moteur → cachés sous le capot, l'utilisateur n'y touche pas (et c'est mieux pour tout le monde).
- `protected` : les pièces accessibles seulement par les **mécaniciens d'usine** ou des **modèles dérivés** de la voiture.

---

## 🎯 Encapsulation (*encapsulation*)

L'**encapsulation** est le **principe fondamental de POO** qui consiste à :
1. **Cacher** les détails internes d'un objet (en les mettant `private`).
2. **Exposer** une interface publique propre pour interagir avec lui (méthodes `public`).

C'est pour ça qu'on met les attributs en `private` et qu'on fournit des **getters / setters** publics : tu contrôles **comment** le monde extérieur peut lire et modifier l'état de tes objets.

**Bénéfices** :
- Tu peux changer l'implémentation interne sans casser le code des utilisateurs.
- Tu peux **valider** ce qu'on essaie de faire à ton objet (refuser un âge négatif dans un setter, par exemple).
- Le code utilisateur est plus simple : il n'a pas à connaître les détails internes.

---

## 🏗️ Constructeur (*constructor*)

Une **fonction membre spéciale** qui est appelée **automatiquement** quand un objet est instancié. Son rôle : **initialiser** l'objet.

Caractéristiques :
- Porte **le même nom que la classe**.
- **Pas** de type de retour (même pas `void`).
- Plusieurs constructeurs peuvent coexister (surcharge), tant qu'ils ont des paramètres différents.

```cpp
class Animal {
public:
    Animal();                           // constructeur par défaut
    Animal(const Animal& other);        // constructeur de copie
    Animal(std::string name, int age);  // constructeur paramétré
};
```

---

## 🧬 Mnémotechnique du constructeur de copie : **CRC**

Pour ne jamais oublier la **signature** du constructeur de copie, retiens **CRC** :

- **C**lasse — il porte le nom de la classe
- **R**éférence — le paramètre est une référence (`&`)
- **C**onst — la référence est constante (`const`)

```cpp
Animal(const Animal& other);
//     └─C─┘ └─C─┘└R┘
```

**Pourquoi ces 3 contraintes ?**

- **Const** : tu ne dois pas modifier l'objet source (sinon, copier `rex` modifierait `rex`, ce serait absurde).
- **Référence** : sans `&`, tu passerais le paramètre **par valeur**, ce qui appellerait... le constructeur de copie. Récursion infinie, crash.
- **Classe** : c'est un constructeur, donc même nom que la classe.

**Phrase magique associée** : *« Je nais comme toi. »* Tu prends la perspective du nouvel objet : *"je viens de naître, et je veux ressembler à `other`."*

Cette phrase t'évite la confusion avec `operator=` (*"je change pour devenir comme toi"*) :

| Fonction | Phrase mentale |
|---|---|
| Constructeur de copie | *"Je **nais** comme toi"* |
| `operator=` | *"Je **change** pour devenir comme toi"* |

**Quand le constructeur de copie est-il appelé ?** Souviens-toi de **« I-P-R »** :

- **I**nitialisation : `Animal copy(rex);` ou `Animal copy = rex;`
- **P**aramètre passé par valeur : `void func(Animal a);`
- **R**etour par valeur : `Animal make() { return local; }`

---

## ⚰️ Destructeur (*destructor*)

Une **fonction membre spéciale** appelée **automatiquement** quand un objet meurt (sortie de scope, `delete`...). Son rôle : **nettoyer** ce que l'objet a alloué/ouvert (mémoire, fichiers, sockets).

Caractéristiques :
- Porte le nom de la classe **précédé d'un tilde `~`**.
- **Pas** de paramètres, **pas** de retour.
- Une classe a **un seul** destructeur.

```cpp
class Animal {
public:
    ~Animal();   // destructeur
};
```

---

## 🌍 Static (membre statique) (*static member*)

Un attribut ou une méthode marqué `static` **appartient à la classe**, pas aux instances. Il n'existe qu'**en une seule copie**, partagée par tous les objets.

```cpp
class Animal {
private:
    std::string _name;                   // un par instance
    static int  _populationCount;        // UN SEUL pour toute la classe
public:
    static int getPopulationCount();     // méthode static
};
```

**Méthode static** : elle peut être appelée **sans instance**, avec la notation `ClassName::method()` :

```cpp
int total = Animal::getPopulationCount();  // pas besoin d'avoir un Animal pour appeler ça
```

**Métaphore** : si chaque animal a son propre nom (attribut normal), un **compteur global** de la population (attribut static) est partagé et accessible à tous, sans qu'il appartienne à un animal en particulier.

---

## 🔗 `this` (le pointeur magique)

À l'intérieur d'une méthode, **`this`** est un **pointeur** vers l'objet sur lequel la méthode a été appelée.

```cpp
void Animal::setName(std::string name) {
    this->_name = name;   // this pointe vers l'objet courant
    // équivalent à : _name = name;
}
```

```cpp
Animal rex;
rex.setName("Rex");   // dans setName, this == &rex
```

**Pourquoi c'est utile ?**
- Distinguer un attribut d'un paramètre qui aurait le même nom.
- Retourner l'objet lui-même (utile pour `operator=` et le chaînage).

---

## 🎭 Surcharge (*overloading*)

Avoir **plusieurs fonctions du même nom**, mais avec des **paramètres différents**. Le compilateur choisit laquelle appeler selon les arguments fournis.

```cpp
class Animal {
public:
    Animal();                          // surcharge 1
    Animal(std::string name);          // surcharge 2
    Animal(std::string name, int age); // surcharge 3
};

Animal a;                  // appelle surcharge 1
Animal b("Rex");           // appelle surcharge 2
Animal c("Rex", 5);        // appelle surcharge 3
```

⚠️ **Ne pas confondre** avec la **surcharge d'opérateur**, qui est un cas particulier où on surcharge `operator+`, `operator==`, etc.

---

## 📋 La forme canonique orthodoxe (*Orthodox Canonical Form*, OCF)

C'est la **convention** qui dit qu'une classe "bien formée" en C++98 doit définir **les 4 fonctions membres spéciales** suivantes :

| # | Nom | Rôle |
|---|---|---|
| 1 | Constructeur par défaut | `Animal()` — créer un objet sans paramètres |
| 2 | Constructeur de copie | `Animal(const Animal& other)` — créer un objet à partir d'un autre |
| 3 | Opérateur d'assignation par copie | `Animal& operator=(const Animal& other)` — copier dans un objet existant |
| 4 | Destructeur | `~Animal()` — nettoyer à la mort de l'objet |

C'est **la règle non négociable** dans la plupart des projets C++ pédagogiques.

---

## 🗂️ Header (`.hpp`) vs Source (`.cpp`)

- **`.hpp`** (header) : contient la **déclaration** de la classe — le "à quoi ça ressemble". Quels attributs, quelles méthodes existent.
- **`.cpp`** (source) : contient l'**implémentation** des méthodes — "comment elles font leur travail".

```cpp
// Animal.hpp
class Animal {
public:
    std::string getName(void) const;  // déclaration
};

// Animal.cpp
std::string Animal::getName(void) const {  // implémentation
    return this->_name;
}
```

L'opérateur `::` s'appelle **opérateur de résolution de portée** (*scope resolution operator*). Il dit : *"cette méthode appartient à la classe Animal."*

---

## 🎯 Les symboles `&` et `*` en C++

Ces deux symboles sont **piégeux** parce qu'ils ont **plusieurs significations différentes** selon le contexte. C'est exactement ce qui crée la confusion.

### 📌 Le `*` — Trois rôles différents

#### Rôle 1 : Déclarer un **pointeur**

Un **pointeur** est une variable qui contient l'**adresse mémoire** d'une autre variable.

```cpp
int  x = 42;        // x est un int qui vaut 42
int* p;             // p est un pointeur vers un int (mais ne pointe vers rien encore)
p = &x;             // p contient maintenant l'adresse de x
```

Quand le `*` est dans une **déclaration**, il signifie : *"cette variable est un pointeur."*

```cpp
int*    p;   // pointeur vers int
char*   s;   // pointeur vers char (typiquement une string en C)
Animal* a;   // pointeur vers un objet Animal
```

#### Rôle 2 : **Déréférencer** un pointeur

Une fois que tu as un pointeur, mettre `*` **devant** te permet d'**accéder à la valeur pointée**.

```cpp
int  x = 42;
int* p = &x;     // p contient l'adresse de x

std::cout << p;   // affiche une adresse (genre 0x7ffd1234abcd)
std::cout << *p;  // affiche 42 — la valeur À l'adresse pointée
```

Le `*` ici signifie : *"va chercher ce qu'il y a À l'adresse contenue dans p."*

C'est le même symbole, mais le **contexte change tout** :
- Dans une **déclaration** (`int* p;`), c'est *"je suis un pointeur"*.
- Dans une **expression** (`*p`), c'est *"donne-moi la valeur pointée"*.

#### Rôle 3 : La multiplication

`a * b` reste la multiplication classique. Le contexte (entre deux variables, sans déclaration autour) le distingue facilement.

---

### 📌 Le `&` — Trois rôles différents

#### Rôle 1 : L'opérateur **"adresse de"**

Quand tu mets `&` **devant une variable**, tu obtiens son **adresse mémoire**.

```cpp
int x = 42;
int* p = &x;   // &x = "donne-moi l'adresse de x"
```

C'est l'**inverse** du déréférencement `*`. Tu peux les voir comme des opérations symétriques :
- `&` : variable → adresse
- `*` : adresse → variable

#### Rôle 2 : Déclarer une **référence**

Quand `&` apparaît dans une **déclaration de variable ou de paramètre**, ce n'est plus l'opérateur "adresse de", c'est un **alias**.

```cpp
int  x = 42;
int& r = x;   // r est UNE RÉFÉRENCE à x — un AUTRE NOM pour x
```

`r` n'est **pas** un pointeur. C'est **littéralement x**, mais avec un nom différent. Si tu modifies `r`, tu modifies `x`. Ils partagent la même case mémoire.

```cpp
int  x = 42;
int& r = x;
r = 100;
std::cout << x;  // affiche 100 ! Parce que r ET x désignent la même variable.
```

**Différences clés entre pointeur et référence** :

| | Pointeur (`int*`) | Référence (`int&`) |
|---|---|---|
| Peut être `NULL` | Oui | Non |
| Peut être réassigné | Oui (`p = &y`) | Non (lié à vie à sa cible) |
| Doit être initialisé | Non | **Oui, obligatoirement** à la déclaration |
| Syntaxe d'accès | `*p`, `p->method()` | Comme la variable elle-même |

#### Rôle 3 : Le ET binaire (rare en POO)

`a & b` fait un ET bit-à-bit. Tu n'en auras quasi jamais besoin en POO classique, sauf curiosité.

---

### 🎬 Exemple complet pour visualiser

```cpp
int x = 42;          // x est une variable (42 quelque part en mémoire)

int* p = &x;         // p est un pointeur (contient l'ADRESSE de x)
                     // & ici = "adresse de"

int& r = x;          // r est une RÉFÉRENCE (un alias pour x)
                     // & ici = "référence" (parce que dans une DÉCLARATION)

std::cout << x;      // 42  — accès direct
std::cout << *p;     // 42  — déréférencement (* = "valeur à l'adresse")
std::cout << r;      // 42  — accès via l'alias

x = 100;
std::cout << *p;     // 100 — p pointe toujours vers x, qui a changé
std::cout << r;      // 100 — r EST x, donc forcément
```

---

### 🔑 Règle d'or pour ne plus confondre

> Si le symbole apparaît **à droite d'un type** (`int*`, `int&`, `Animal&`...), c'est une **déclaration** :
> - `*` = je suis un pointeur
> - `&` = je suis une référence
>
> Si le symbole apparaît **devant une variable** dans du code normal (`*p`, `&x`), c'est un **opérateur** :
> - `*` = déréférencement (donne-moi la valeur)
> - `&` = adresse de (donne-moi l'adresse)

#### Exemples mis en parallèle

```cpp
// DÉCLARATIONS (à droite du type)
int*  p;        // p est un pointeur
int&  r = x;    // r est une référence

// OPÉRATEURS (devant une variable)
p = &x;         // & = "adresse de x"
int v = *p;     // * = "valeur pointée par p"
```

---

### 💡 Lien avec le constructeur de copie

Maintenant que tu comprends `&`, tu peux relire la signature du constructeur de copie avec un œil neuf :

```cpp
Animal(const Animal& other);
//                 └─┘
//          C'est une RÉFÉRENCE (parce qu'on est dans une déclaration)
//          → other est un ALIAS pour l'objet source
//          → pas de copie au passage de paramètre
//          → modifier other modifierait la source (mais const empêche ça)
```

C'est pour ça que **passer par référence évite la récursion infinie** : si tu écrivais `Animal(const Animal other)` (sans `&`), le compilateur devrait **copier** l'argument pour créer `other`, ce qui appellerait... le constructeur de copie. Boucle infinie.

---

### 🎨 Métaphore pour mémoriser

Imagine une maison.

- **Variable normale** (`int x`) : c'est la maison elle-même. Adresse "12 rue des Lilas".
- **Pointeur** (`int* p`) : c'est un **post-it** sur lequel tu as noté "12 rue des Lilas". Tu peux changer l'adresse écrite sur le post-it, ou le jeter (NULL).
- **Référence** (`int& r`) : c'est un **deuxième nom** officiel pour la maison ("Villa Bellevue"). Le facteur livre au même endroit, peu importe le nom utilisé. Tu ne peux pas changer le nom, et il pointe forcément vers une vraie maison.

Pour accéder au contenu :
- Avec la **variable** : tu rentres directement chez toi.
- Avec le **pointeur** : tu lis le post-it (`*p`), puis tu vas à l'adresse.
- Avec la **référence** : tu utilises le surnom, qui mène au même endroit.

---

### 🚀 Cas d'usage typiques en C++

| Situation | Ce qu'on utilise | Pourquoi |
|---|---|---|
| Passer un gros objet à une fonction sans le modifier | `const Type&` | Évite la copie, sécurité |
| Passer un objet à modifier | `Type&` | Modifications visibles à l'extérieur |
| Passer un objet à modifier (style C) | `Type*` | Idem mais avec syntaxe pointeur |
| Allocation dynamique | `Type*` avec `new`/`delete` | La référence ne peut pas être `NULL` |
| Constructeur de copie | `const Type&` | Obligatoire (récursion sinon) |
| `operator=` | `const Type&` en paramètre, `Type&` en retour | Idem + chaînage |

---

### ⚠️ Le piège classique avec `*` dans une déclaration

```cpp
int* a, b;   // ATTENTION : a est un int*, mais b est juste un int !
```

Le `*` ne s'applique **qu'à `a`**, pas à `b`. Pour avoir deux pointeurs :

```cpp
int *a, *b;   // les deux sont des pointeurs
// ou mieux :
int* a;
int* b;
```

C'est pour ça que beaucoup de gens préfèrent le style `int* a;` (collé au type) plutôt que `int *a;` (collé au nom) — visuellement, le `*` "appartient" au type. Mais les deux sont valides syntaxiquement.

---

## 🧠 Récap visuel

```
┌─────────────────────────────────────────────────────────┐
│                    CLASSE Animal                        │
│  (le plan / le moule)                                   │
│                                                         │
│  PRIVATE:                                               │
│    • _name (string)            ← ATTRIBUT               │
│    • _age  (int)               ← ATTRIBUT               │
│    • _populationCount (static) ← ATTRIBUT (static)      │
│                                                         │
│  PUBLIC:                                                │
│    • Animal()                  ← MÉTHODE (constructeur) │
│    • ~Animal()                 ← MÉTHODE (destructeur)  │
│    • getName()                 ← MÉTHODE (getter)       │
│    • setName()                 ← MÉTHODE (setter)       │
│    • eat(), makeSound()        ← MÉTHODES (actions)     │
└─────────────────────────────────────────────────────────┘
            │
            │ instanciation
            ▼
┌──────────────┐    ┌──────────────┐    ┌──────────────┐
│  OBJET rex   │    │  OBJET tom   │    │  OBJET kiwi  │
│  _name: Rex  │    │  _name: Tom  │    │  _name: Kiwi │
│  _age: 5     │    │  _age: 3     │    │  _age: 1     │
└──────────────┘    └──────────────┘    └──────────────┘
        chaque objet a sa PROPRE copie de _name et _age
        mais ils PARTAGENT _populationCount (static)
```

---

## 🎯 Quiz d'auto-évaluation

Pour vérifier que tu maîtrises le vocabulaire, réponds à ces questions :

1. Dans `Animal rex;`, comment on appelle l'action ?
2. Dans `class Animal { int _age; };`, `_age` est-il un attribut ou une méthode ?
3. La fonction `getName()` est-elle une fonction libre ou une fonction membre ?
4. Quelle est la différence entre `private` et `public` ?
5. Combien d'instances peuvent partager un attribut `static` ?
6. Quel symbole précède le nom du destructeur ?
7. À quoi sert le mot-clé `this` ?
8. Quelle est la différence entre constructeur de copie et `operator=` ?
9. Que signifie OCF et combien de fonctions ça impose ?
10. Dans quel fichier (`.hpp` ou `.cpp`) écrit-on l'implémentation des méthodes ?
11. Dans `int& r = x;`, le `&` représente-t-il une référence ou un opérateur "adresse de" ?
12. Que se passe-t-il si on passe un objet par valeur au constructeur de copie (sans `&`) ?

---

## 📚 Termes complémentaires à connaître

| Terme | Définition rapide |
|---|---|
| **Membre** | Terme générique qui regroupe attributs **et** méthodes |
| **Getter** | Méthode publique qui *retourne* la valeur d'un attribut privé |
| **Setter** | Méthode publique qui *modifie* la valeur d'un attribut privé |
| **Const member function** | Méthode qui ne modifie pas l'objet (`const` en fin de signature) |
| **Liste d'initialisation** | Syntaxe `: attr(val)` après la signature d'un constructeur |
| **Scope** | Portée d'une variable / d'un identifiant |
| **`::`** | Opérateur de résolution de portée |
| **Polymorphisme ad-hoc** | Nom savant pour la surcharge (même nom, comportements différents) |
| **Héritage** | Mécanisme où une classe (fille) hérite des membres d'une autre (mère) |
| **Polymorphisme** | Capacité d'un objet à se comporter selon plusieurs types (lié à l'héritage) |
| **Classe abstraite** | Classe contenant au moins une méthode virtuelle pure, qu'on ne peut pas instancier |
| **Méthode virtuelle** | Méthode pouvant être redéfinie dans une classe fille (mot-clé `virtual`) |

---

## 🎓 Les 4 piliers de la POO (vue d'ensemble)

Pour situer le vocabulaire dans un cadre plus large, la POO repose sur **4 piliers** :

1. **Encapsulation** — cacher les détails, exposer une interface propre (vu plus haut).
2. **Héritage** — créer des classes filles qui réutilisent et étendent une classe mère.
3. **Polymorphisme** — un objet peut se comporter selon plusieurs types (animal → chien, chat...).
4. **Abstraction** — modéliser des concepts sans s'embarrasser des détails d'implémentation.

Tu rencontreras les piliers 2, 3 et 4 progressivement dans les modules suivants.

---

*Lexique POO C++ — référence universelle. Bonne continuation !* 🚀
