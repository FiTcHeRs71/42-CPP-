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

## 🛡️ Les deux `const` dans une signature de méthode

Une signature comme celle-ci contient **deux `const` indépendants** qui protègent **deux choses différentes** :

```cpp
bool Animal::operator<(Animal const & input) const
//                     ↑                    ↑
//                  const #1            const #2
```

### Const #1 : `const` sur le paramètre — protège l'opérande de droite

```cpp
Animal const & input    // équivalent à : const Animal& input
```

Ce `const` dit : *"`input` est une référence à un `Animal`, et je promets de **ne pas modifier** ce `Animal` à travers cette référence."*

**Pourquoi c'est nécessaire ?** Quand tu écris `a < b`, l'opérande de droite (`b`) est passé en paramètre sous le nom `input`. Tu ne veux pas que comparer modifie `b` — sinon ce serait absurde !

C'est aussi un **contrat** : tu garantis aux utilisateurs que la comparaison ne modifie pas leur objet.

**Note de syntaxe** : `Animal const&` et `const Animal&` sont **strictement équivalents**. Question de style.

### Const #2 : `const` à la fin — protège l'opérande de gauche (`this`)

```cpp
bool Animal::operator<(Animal const & input) const
//                                          ↑
//                                    ce const-ci
```

Ce `const`, qu'on appelle **"const de méthode"** ou **"trailing const"**, dit : *"cette méthode promet de **ne pas modifier** l'objet sur lequel elle est appelée (c'est-à-dire `*this`)."*

**Pourquoi c'est crucial ?** Sans ce `const`, ta méthode **ne peut pas être appelée sur un objet `const`** :

```cpp
Animal const rex("Rex", 5);
Animal milo("Milo", 3);
if (milo < rex) { ... }   // ❌ ERREUR si operator< n'a pas le const final
                          //    (rex est const, le compilateur refuse)
```

Le compilateur refuse d'appeler une méthode non-const sur un objet const, parce qu'il ne peut pas garantir qu'elle ne modifierait pas l'objet.

### Récapitulatif des deux const

```cpp
bool Animal::operator<(Animal const & input) const
//                     └────┬───────┘        └─┬─┘
//                          │                  │
//                  const sur le param    const de méthode
//                          │                  │
//                  protège l'opérande     protège l'opérande
//                  de DROITE (input)      de GAUCHE (this)
```

| Const | Protège | Empêche | Permet de... |
|---|---|---|---|
| `const` sur le paramètre | L'opérande de droite (`input`) | De modifier `input` dans le corps | Accepter des arguments const |
| `const` à la fin | L'opérande de gauche (`this`) | De modifier `this` dans le corps | Appeler la méthode sur un objet const |

### 🧠 Métaphore pour mémoriser

Imagine que tu compares deux livres pour savoir lequel est le plus épais.

- **Const sur le paramètre** : *"Je promets de ne pas écorner le livre que tu me passes en main droite."*
- **Const de méthode** : *"Je promets de ne pas écorner le livre que je tiens dans ma main gauche (`this`) non plus."*

Les deux mains sont protégées. Tu peux donc comparer même des **livres précieux** (des objets `const`) sans que la bibliothécaire t'arrête.

### 🔍 Règle pratique : quand mettre le `const` final ?

| Type de méthode | `const` final ? | Exemples |
|---|---|---|
| **Getters / lecture seule** | ✅ Oui | `getName() const`, `toFloat() const` |
| **Comparaisons** | ✅ Oui | `operator< const`, `operator== const` |
| **Opérateurs arithmétiques** | ✅ Oui | `operator+ const`, `operator- const` (créent un nouvel objet, ne modifient pas) |
| **Méthodes d'affichage** | ✅ Oui | `print() const`, `display() const` |
| **Setters** | ❌ Non | `setName(string)`, `setAge(int)` |
| **Opérateurs modifiants** | ❌ Non | `operator++`, `operator+=`, `operator=` |
| **Constructeurs / Destructeur** | ❌ Non | (créent ou détruisent l'objet) |

**Règle simple** : si la méthode **ne modifie pas** l'état de l'objet, mets `const`. Sinon, ne le mets pas.

### ⚠️ Le piège classique des opérateurs arithmétiques

Pour bien fixer la nuance :

```cpp
// Opérateur d'addition : crée un NOUVEL objet, ne modifie ni a ni b
Animal Animal::operator+(const Animal& other) const;   // ← const à la fin

// Opérateur d'incrément : modifie this (l'incrémente)
Animal& Animal::operator++(void);                       // ← PAS de const à la fin
```

`a + b` ne modifie **ni `a` ni `b`** — il retourne un troisième objet qui est leur somme. Donc `const` final.

`++a` modifie **`a`**. Donc pas de `const` final.

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

## 🎯 Liste d'initialisation (*member initializer list*)

La **liste d'initialisation** est la syntaxe avec `:` après la signature du constructeur, qui permet d'**initialiser directement** les attributs au lieu de les **assigner** dans le corps.

```cpp
// Avec liste d'initialisation (recommandé)
Animal::Animal(std::string name, int age) : _name(name), _age(age)
{
    std::cout << "Animal constructor called" << std::endl;
}

// Sans liste d'initialisation (sub-optimal)
Animal::Animal(std::string name, int age)
{
    this->_name = name;   // assignation, pas initialisation
    this->_age = age;
    std::cout << "Animal constructor called" << std::endl;
}
```

### 🔬 Différence fondamentale : initialisation vs assignation

Les deux versions semblent équivalentes, mais le mécanisme sous-jacent est **différent** :

#### Sans liste d'init (assignation dans le corps)
1. **Étape 1** : tous les attributs sont d'abord initialisés avec leur **constructeur par défaut** (ou laissés avec une valeur indéterminée pour les types primitifs comme `int`).
2. **Étape 2** : dans le corps `{ ... }`, l'opérateur d'**assignation** (`operator=`) écrase la valeur initiale.

→ **Deux étapes**, donc plus coûteux.

#### Avec liste d'init (initialisation directe)
1. **Étape unique** : les attributs sont **directement initialisés** avec la valeur souhaitée, via leur **constructeur de copie** (ou de conversion).

→ **Une seule étape**, plus efficace.

### ⚠️ Cas où la liste d'init est OBLIGATOIRE

Pour certains types d'attributs, la liste d'initialisation n'est **pas un choix** — c'est la **seule façon** qui compile.

#### Cas 1 : Attributs `const`

```cpp
class Animal {
private:
    const std::string _species;   // const !
};

// ❌ ERREUR : on ne peut pas assigner à un const
Animal::Animal(std::string s) { this->_species = s; }

// ✅ OK : initialisation directe via la liste
Animal::Animal(std::string s) : _species(s) {}
```

Un `const` ne peut être fixé **qu'à sa naissance**. Une fois né, plus de modification possible. Donc seule l'initialisation directe fonctionne.

#### Cas 2 : Attributs de type référence

```cpp
class Animal {
private:
    Owner& _owner;   // référence !
};
```

Une référence **doit** être liée à sa cible dès sa naissance. Pas d'assignation possible.

#### Cas 3 : Attributs sans constructeur par défaut

Si un attribut est un objet d'une classe qui n'a **pas** de constructeur par défaut, il **ne peut pas** être initialisé par défaut à l'étape 1. Il **doit** être initialisé directement via la liste.

### 📊 Tableau comparatif

| | Assignation dans le corps | Liste d'initialisation |
|---|---|---|
| **Étapes** | 2 (init défaut + assignation) | 1 (init directe) |
| **Performance** | Plus lent (surtout pour objets complexes) | Plus rapide |
| **Pour les `int`** | Fonctionne mais sub-optimal | Idiomatique |
| **Pour les `const`** | ❌ Ne compile pas | ✅ Seule façon |
| **Pour les références** | ❌ Ne compile pas | ✅ Seule façon |
| **Pour les objets sans ctor par défaut** | ❌ Ne compile pas | ✅ Seule façon |

### 🎨 Bonne pratique de mise en forme

Pour plusieurs attributs, on les met sur des lignes séparées pour la lisibilité :

```cpp
Animal::Animal(std::string name, int age, std::string species)
    : _name(name)
    , _age(age)
    , _species(species)
{
    std::cout << "Animal constructor called" << std::endl;
}
```

Note les `,` en début de ligne — style qui rend l'ajout/suppression d'attributs plus simple sans casser la syntaxe.

### ⚠️ Subtilité importante : l'ordre d'initialisation

Dans la liste, **l'ordre d'initialisation est dicté par l'ordre de DÉCLARATION dans la classe**, pas par l'ordre dans la liste !

```cpp
class Animal {
private:
    int _age;        // déclaré en premier
    int _ageMonths;  // déclaré en second
public:
    Animal(int age) : _ageMonths(age * 12), _age(age) { }
    //                ↑                       ↑
    //                écrit en 1er            écrit en 2e
    //                MAIS initialisé en 2nd  MAIS initialisé en 1er
};
```

**Piège** : si tu utilises `_age` pour calculer `_ageMonths` (genre `_ageMonths(_age * 12)`), tu utiliserais un `_age` **non initialisé**, parce que `_ageMonths` est déclaré avant.

**Bonne pratique** : toujours mettre les attributs dans la liste d'init **dans le même ordre que dans la déclaration**, pour éviter les mauvaises surprises. Certains compilateurs (avec `-Wall`) te warning si tu ne respectes pas cet ordre.

### 🎯 La règle d'or

> **Préfère TOUJOURS la liste d'initialisation** pour initialiser tes attributs dans un constructeur. Réserve le corps `{ ... }` aux opérations qui ne sont pas des initialisations (afficher des messages, faire des vérifications, lancer des actions, etc.).

C'est l'une des **règles d'or** du C++ moderne, martelée dans tous les manuels professionnels (Effective C++, Modern C++, etc.).

### 🧠 Mnémotechnique

> **"Initialise, ne réassigne pas."**  
> Naître avec la bonne valeur > Naître avec une valeur poubelle puis se faire écraser.

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

### ⚠️ Piège #1 : `static` ne se met QUE dans la déclaration

`static` doit apparaître **uniquement dans le `.hpp`** (déclaration), **pas dans le `.cpp`** (définition).

```cpp
// Animal.hpp
class Animal {
public:
    static int getPopulationCount();   // ✅ static ici
};

// Animal.cpp
int Animal::getPopulationCount()       // ✅ PAS de static ici
{
    return _populationCount;
}

// ❌ ERREUR si tu écris :
static int Animal::getPopulationCount() { ... }   // erreur de compilation
```

C'est une bizarrerie historique : `static` dans le `.cpp` aurait un sens **complètement différent** (lié à la portée de fichier, héritage du C). Le compilateur t'arrête net.

### ⚠️ Piège #2 : Erreur "call to non-static member function without an object argument"

Si tu appelles une méthode avec `ClassName::method()` mais qu'elle n'est pas déclarée `static`, le compilateur te lance :

```
error: call to non-static member function without an object argument
```

**Diagnostic** : tu utilises la **syntaxe d'une méthode static** (`Animal::method()`) sur une **méthode normale**. Solution : ajouter `static` dans la déclaration en `.hpp`.

### 🔍 Quand utiliser `static` ?

| Situation | Static ? | Pourquoi |
|---|---|---|
| Compteur global de toutes les instances | ✅ | Appartient à la classe, pas à une instance |
| Constante de classe (ex: nombre de bits, max value) | ✅ | Partagée, ne change pas par instance |
| Méthode utilitaire qui ne dépend d'aucune instance (`min`, `max`, factory) | ✅ | Symétrie, pas d'objet "principal" |
| Getter/setter d'un attribut d'instance | ❌ | A besoin de `this` pour accéder à l'attribut |
| Méthode qui modifie l'état d'un objet | ❌ | A besoin de `this` |

### 🎯 Récapitulatif des règles `static`

| Aspect | Règle |
|---|---|
| **Où mettre `static`** | Uniquement dans la **déclaration** (`.hpp`) |
| **Comment l'appeler** | `ClassName::method(...)` (sans objet) |
| **Accès à `this`** | ❌ Aucun (pas d'objet appelant) |
| **Accès aux attributs d'instance** | ❌ Pas direct (mais via les paramètres oui) |
| **Accès aux membres static de la classe** | ✅ Oui |
| **Initialisation d'un attribut `static const`** | Dans le `.cpp`, hors de toute fonction : `const int Animal::_x = 8;` |

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

## 🧬 Héritage (*inheritance*)

L'**héritage** permet à une classe (**la fille**) de **récupérer** automatiquement tous les attributs et méthodes d'une autre classe (**la mère** ou **la parente**), et de les **étendre** ou **modifier**.

C'est le **2ème pilier** de la POO après l'encapsulation.

### 🎯 Le problème que ça résout

Sans héritage, modéliser plusieurs types similaires (Chien, Chat, Poisson) entraîne une **duplication massive** : mêmes attributs (`_name`, `_age`), mêmes méthodes (`eat()`, `sleep()`) répétés dans chaque classe. Difficile à maintenir, source de bugs.

Avec l'héritage, tu factorises le **code commun** dans une classe **parente**, et chaque classe fille **n'ajoute que ce qui lui est spécifique**.

### 📐 Syntaxe de base

```cpp
class Animal {                  // classe PARENTE (mère / base)
protected:
    std::string _name;
public:
    Animal(std::string name);
    void eat();
    void sleep();
};

class Dog : public Animal {     // Dog HÉRITE d'Animal
//          ↑↑↑↑↑↑↑↑↑↑↑↑
public:
    Dog(std::string name);
    void bark();                // méthode SPÉCIFIQUE à Dog
};
```

Maintenant `Dog` possède **automatiquement** `_name`, `eat()`, `sleep()` en plus de ses propres méthodes. Pas besoin de les réécrire.

```cpp
Dog rex("Rex");
rex.eat();    // méthode héritée d'Animal
rex.sleep();  // méthode héritée d'Animal
rex.bark();   // méthode propre à Dog
```

### 🔑 La relation **"est-un"** (*is-a*)

L'héritage modélise une relation **"est-un"** :

- Un `Dog` **est un** `Animal` ✅
- Un `Cat` **est un** `Animal` ✅
- Un `Pneu` **est-il un** `Voiture` ? ❌ Non, une `Voiture` **a un** `Pneu` → composition, pas héritage.

**Test mental** : si tu ne peux pas dire *"X est un Y"* avec un sens naturel, n'utilise PAS l'héritage. Utilise la **composition** à la place (un attribut de type Y dans la classe X).

### 🌳 La hiérarchie en arbre

L'héritage crée une hiérarchie :

```
                    Animal
                   /      \
                Dog        Cat
               /    \
        Bulldog    Poodle
```

Plus on **descend**, plus on est **spécifique** (spécialisation).  
Plus on **monte**, plus on est **général** (généralisation).

Par transitivité : un `Bulldog` est un `Dog`, qui est un `Animal`. Donc un `Bulldog` est aussi un `Animal`.

### 🛡️ `protected` prend tout son sens

Avec l'héritage, le mot-clé `protected` (qu'on avait mentionné) prend toute son utilité :

| Visibilité | Accès depuis la classe ? | Accès depuis une fille ? | Accès depuis l'extérieur ? |
|---|---|---|---|
| **`private`** | ✅ | ❌ | ❌ |
| **`protected`** | ✅ | ✅ | ❌ |
| **`public`** | ✅ | ✅ | ✅ |

**`protected`** = *"privé pour le monde extérieur, mais accessible pour ma descendance."*

**Règle pratique** :
- Si un attribut sera **manipulé par les classes filles** → `protected`
- Si un attribut est **strictement interne** à la classe parente → `private`

### 🎭 Les 3 modes d'héritage

Tu peux hériter de trois façons :

```cpp
class Dog : public Animal { };      // héritage public (le plus courant)
class Dog : protected Animal { };   // héritage protégé (rare)
class Dog : private Animal { };     // héritage privé (rare)
```

Effet du mode d'héritage sur les membres publics de la classe parente :

| Mode d'héritage | Les membres `public` deviennent... |
|---|---|
| `public` | `public` (inchangé) |
| `protected` | `protected` |
| `private` | `private` |

Le mode d'héritage **dégrade** la visibilité, jamais ne la rehausse.

**En pratique : utilise toujours `public`.** C'est ce que 99% des cas exigent et c'est ce que CPP03 attend.

### 🏗️ Constructeurs et héritage

Point **fondamental** : quand tu crées un `Dog`, **deux constructeurs** sont appelés, dans un ordre précis.

#### Ordre de construction

```cpp
Dog rex("Rex");
```

1. **D'abord** : le constructeur d'`Animal` (la partie parente)
2. **Ensuite** : le constructeur de `Dog` (la partie fille)

C'est logique : avant de pouvoir construire la partie "Dog" spécifique, il faut d'abord construire la partie "Animal" sous-jacente. On construit **du général au spécifique**.

#### Appeler explicitement le constructeur parent

Si le parent n'a pas de constructeur par défaut (par exemple, il prend des arguments obligatoires), tu **dois** appeler son constructeur explicitement dans la liste d'initialisation :

```cpp
Dog::Dog(std::string name) : Animal(name)
//                           ↑↑↑↑↑↑↑↑↑↑↑↑
//                  appel du constructeur parent
{
    std::cout << "Dog constructor called" << std::endl;
}
```

Si tu oublies, le compilateur essaie d'appeler le constructeur par défaut d'`Animal`. S'il n'existe pas → erreur de compilation.

### ⚰️ Destructeurs et héritage

Pareil mais **dans l'ordre INVERSE** :

```cpp
~Dog();
```

1. **D'abord** : le destructeur de `Dog` (la partie spécifique)
2. **Ensuite** : le destructeur d'`Animal` (la partie générale)

C'est comme démonter une poupée russe : on enlève d'abord la coque extérieure pour accéder à l'intérieur.

**Vue d'ensemble** :

```
Construction :  Animal → Dog        (général → spécifique)
Destruction  :  Dog → Animal        (spécifique → général)
```

### ⚠️ Règle d'or : destructeurs `virtual`

> **Si une classe est destinée à être héritée, son destructeur DOIT être `virtual`.**

```cpp
class Animal {
public:
    virtual ~Animal();   // ← virtual !
};
```

Sans `virtual`, lors d'une destruction polymorphique (via un pointeur `Animal*` vers un `Dog`), le destructeur de `Dog` **ne sera pas appelé** → fuite mémoire, ressources non libérées.

Le détail du pourquoi est dans le pilier **polymorphisme** (CPP04), mais retiens **dès maintenant** : destructeur de classe parente = toujours `virtual`.

### 🎬 Exemple complet

```cpp
// Animal.hpp
class Animal {
protected:
    std::string _name;
public:
    Animal(std::string name);
    virtual ~Animal();
    void eat();
};

// Animal.cpp
Animal::Animal(std::string name) : _name(name) {
    std::cout << "Animal constructor called" << std::endl;
}
Animal::~Animal() {
    std::cout << "Animal destructor called" << std::endl;
}
void Animal::eat() {
    std::cout << _name << " is eating." << std::endl;
}

// Dog.hpp
class Dog : public Animal {
public:
    Dog(std::string name);
    ~Dog();
    void bark();
};

// Dog.cpp
Dog::Dog(std::string name) : Animal(name) {
    std::cout << "Dog constructor called" << std::endl;
}
Dog::~Dog() {
    std::cout << "Dog destructor called" << std::endl;
}
void Dog::bark() {
    std::cout << _name << " says: Woof!" << std::endl;
}

// main.cpp
int main() {
    Dog rex("Rex");
    rex.eat();
    rex.bark();
    return 0;
}
```

**Sortie** :
```
Animal constructor called    ← parent d'abord
Dog constructor called       ← puis fille
Rex is eating.
Rex says: Woof!
Dog destructor called        ← fille d'abord
Animal destructor called     ← puis parent
```

### 🆚 Héritage vs Composition

Ne pas confondre :

| Héritage ("est-un") | Composition ("a-un") |
|---|---|
| `Dog` **est un** `Animal` | `Car` **a un** `Engine` |
| `class Dog : public Animal` | `class Car { Engine _engine; };` |
| Lien fort, dépendance forte | Lien faible, les classes restent indépendantes |
| Hérite de TOUT (attrs + méthodes) | Utilise juste un objet à l'intérieur |
| Visibilité contrôlée par `protected` | Pas d'impact sur la visibilité |

**Règle d'or moderne** : *"Préfère la composition à l'héritage quand tu as le choix."*

L'héritage est puissant mais crée des **couplages forts** entre classes. La composition reste plus flexible. Ne hérite que quand la relation **"est-un"** est claire et naturelle.

### 🚨 L'héritage en diamant

Cas particulier qu'on rencontre au CPP03 : une classe hérite de **deux classes parentes** qui héritent elles-mêmes d'une **classe commune** :

```
         Animal
         /    \
       Dog    Robot
         \    /
       RobotDog   ← double héritage !
```

Sans précaution, `RobotDog` contient **deux exemplaires** d'`Animal` (un via `Dog`, un via `Robot`). Ambigüité dangereuse !

**Solution** : le mot-clé `virtual` dans la déclaration d'héritage :

```cpp
class Dog : virtual public Animal { };     // ← virtual !
class Robot : virtual public Animal { };   // ← virtual !
class RobotDog : public Dog, public Robot { };
```

Le `virtual` ici n'a rien à voir avec celui des méthodes/destructeurs. Il dit : *"il n'existe qu'**un seul** `Animal` dans `RobotDog`, partagé entre `Dog` et `Robot`."* C'est ce qu'on appelle l'**héritage virtuel**.

C'est exactement le sujet de l'**ex03 du CPP03** (la classe `DiamondTrap`).

### 🎨 Métaphore pour mémoriser

Pense à l'héritage comme à un **héritage familial** :

- Tes **parents** te transmettent des caractéristiques (couleur des yeux, taille, certains traits).
- Tu en **hérites** automatiquement.
- Tu as aussi tes **propres caractéristiques** que tes parents n'avaient pas.
- Tu peux **redéfinir** certaines choses (musique préférée différente).
- Ton existence dépend de celle de tes parents : tu n'aurais pas pu exister sans eux.

C'est exactement la POO : la classe fille hérite, enrichit, peut redéfinir, mais reste fondamentalement liée à sa classe parente.

### 🎯 Aperçu de ce qui vient au CPP04 : le polymorphisme

L'héritage seul est utile, mais il révèle son plein potentiel avec le **polymorphisme** (CPP04). Spoiler :

```cpp
Animal* tab[3];
tab[0] = new Dog("Rex");
tab[1] = new Cat("Whiskers");
tab[2] = new Bird("Tweety");

for (int i = 0; i < 3; i++)
    tab[i]->makeSound();   // chaque animal fait SON propre son !
```

Un seul appel `makeSound()` produit des **comportements différents** selon le **vrai type** de l'objet. C'est la magie du polymorphisme, et c'est ce qu'on couvrira au CPP04.

### 🧠 Mnémotechniques pour l'héritage

- **"Est-un"** pour décider quand hériter
- **`protected`** pour partager avec les enfants
- **Constructeurs : parent → enfant** (du général au spécifique)
- **Destructeurs : enfant → parent** (l'inverse)
- **Destructeur parent toujours `virtual`** si la classe sera héritée
- **Préfère la composition à l'héritage** quand tu as le choix

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
