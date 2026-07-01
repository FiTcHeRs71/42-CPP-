# C++ Modules — 42 Common Core

*[English](#english) · [Français](#français)*

---

## English

This repository gathers all the **CPP 00 → 09** modules of the 42 Common Core.
Each module is a themed pool that progressively introduces the concepts of
**object-oriented programming** and **modern C++ (C++98 standard)**.

The goal of the cursus is not to learn algorithms, but to **master the object
paradigm**: encapsulation, inheritance, polymorphism, memory management,
templates and STL containers.

### ⚙️ Standard constraint

Every module is compiled with:

```bash
c++ -Wall -Wextra -Werror -std=c++98
```

Rules imposed by the cursus:
- **C++98 only** (no `auto`, `nullptr`, `<thread>`, lambdas, etc.).
- C functions forbidden (`printf`, `malloc`, `free`, `*alloc`).
- Every class follows the **Coplien / Orthodox Canonical Form** from module 02
  onward (default constructor, copy constructor, assignment operator, destructor).
- No loose `using namespace`, one header per class, header guards everywhere.

### 🚀 Building

Each exercise has its own `Makefile` with the standard rules:

```bash
cd cpp_02/ex02
make        # build
make clean  # remove .o files
make fclean # remove .o + binary
make re     # rebuild everything
```

A root `Makefile` and the `fclean_all.sh` script clean all exercises at once:

```bash
make fclean-all   # fclean on every cpp_XX/exYY
make clean-all
```

### 📚 Module breakdown

#### CPP 00 — Basics, namespaces, classes, I/O
> First steps in C++ after C.

- `ex00` **Megaphone**: `std::string`, arguments, uppercasing, streams.
- `ex01` **PhoneBook**: first **class** (`Contact`, `PhoneBook`), static array of
  objects, private members, public methods, output formatting.
- `ex02` **Account**: reading an existing log, reconstructing a class from its
  behavior, **static members** (class variables).

**Key notions**: `std::cout` / `std::cin`, `std::string`, classes, encapsulation,
`static` members, `.hpp` / `.cpp` separation.

#### CPP 01 — Memory, references, pointers
> Dynamic allocation and stack vs heap.

- `ex00` **Zombie**: allocation on the **stack** vs the **heap** (`new`), destructors.
- `ex01` **ZombieHorde**: allocating an **array of objects** with `new[]`.
- `ex02` **HI THIS IS BRAIN**: **pointers vs references** on the same variable.
- `ex03` **Weapon**: when to use a pointer (`HumanB`) or a reference (`HumanA`)
  as a class member.
- `ex04` **Sed is for losers**: string replacement, `std::string` and files
  (`ifstream` / `ofstream`).
- `ex05` **Harl**: method call through a **pointer to member function**.
- `ex06` **Harl filter**: `switch` and filtering of log levels.

**Key notions**: `new` / `delete`, pointers, references, pointers to members,
file read/write, object lifetime.

#### CPP 02 — Ad-hoc polymorphism, operator overloading, Canonical Form
> Building a complete numeric class.

- `ex00` **Fixed**: **fixed-point number** class, setting up the **Orthodox
  Canonical Form**.
- `ex01` **Fixed**: int/float ↔ fixed conversions, `operator<<` overload.
- `ex02` **Fixed**: overloading **comparison, arithmetic, increment** operators,
  `min` / `max` methods.
- `ex03` **BSP**: concrete use of `Fixed` with `Point` to tell whether a point is
  inside a triangle.

**Key notions**: Coplien canonical form, operator overloading, fixed-point
representation, `const` correctness.

#### CPP 03 — Inheritance
> Reuse and specialization of classes.

- `ex00` **ClapTrap**: base class.
- `ex01` **ScavTrap**: single inheritance, construction / destruction order.
- `ex02` **FragTrap**: another specialization.
- `ex03` **DiamondTrap**: **diamond inheritance**, virtual inheritance.

**Key notions**: public inheritance, constructor/destructor chaining, multiple
inheritance, the diamond problem and `virtual`.

#### CPP 04 — Polymorphism, abstraction, interfaces
> The heart of OOP.

- `ex00` **Polymorphism**: `Animal` / `Dog` / `Cat`, **virtual functions**.
- `ex01` **Brain**: deep copy vs shallow copy with dynamic allocation.
- `ex02` **Abstract class**: making `Animal` **abstract** (pure virtual method).
- `ex03` **Interface & recap**: interfaces (`AMateria`, `ICharacter`,
  `IMateriaSource`), object inventory.

**Key notions**: `virtual`, pure virtual methods, abstract classes, interfaces,
virtual destructors, deep copy.

#### CPP 05 — Try / Catch, exceptions
> Object-level error handling.

- `ex00` **Bureaucrat**: class with invariants, throwing **exceptions**.
- `ex01` **Form**: custom exceptions inheriting from `std::exception`.
- `ex02` **Concrete forms**: form hierarchy, conditional execution.
- `ex03` **Intern**: creating objects through a **factory** (pointers to members).

**Key notions**: `throw` / `try` / `catch`, exception classes derived from
`std::exception`, `what()`, factory design.

#### CPP 06 — Type conversions & C++ casts
> The different casts and their usage.

- `ex00` **Scalar conversion**: explicit conversions between scalar types.
- `ex01` **Serialization**: `reinterpret_cast` (pointer ↔ integer).
- `ex02` **Real type**: identifying the real type via `dynamic_cast`.

**Key notions**: `static_cast`, `dynamic_cast`, `reinterpret_cast`, `const_cast`,
RTTI, serialization.

#### CPP 07 — Templates
> Generic programming.

- `ex00` **Whatever**: **function** templates (`swap`, `min`, `max`).
- `ex01` **Iter**: template applying a function to a generic array.
- `ex02` **Array**: container **class** template with memory management and a safe
  `operator[]` (out-of-bounds exception).

**Key notions**: `template<typename T>`, function and class templates, genericity,
implicit type constraints.

#### CPP 08 — Templated containers, iterators, algorithms
> The STL begins.

- `ex00` **Easyfind**: searching in a generic container, `std::find`.
- `ex01` **Span**: storing N integers, computing the smallest / largest span,
  filling from an iterator range.
- `ex02` **MutantStack**: making `std::stack` **iterable** through inheritance.

**Key notions**: STL containers (`vector`, `list`, `stack`), **iterators**,
standard algorithms (`<algorithm>`), container adaptation.

#### CPP 09 — The STL in practice
> Projects synthesizing containers and algorithms.

- `ex00` **Bitcoin Exchange**: CSV file parsing, `std::map`, date → value mapping,
  finding the closest date. *(see `input.csv`)*
- `ex01` **RPN**: reverse Polish notation calculator using `std::stack`.
- `ex02` **PmergeMe**: **Ford-Johnson** merge-insertion sort implemented on two
  containers (`std::vector` and `std::deque`) with runtime comparison.
  Includes a visualizer (`docs/pmerge_visualizer.html`) and notes
  (`cpp09_ex02_pmergeme.md`).

**Key notions**: `std::map`, `std::stack`, `std::vector`, choosing the right
container, robust parsing, Ford-Johnson sort algorithm, performance measurement.

### 🗂️ Typical exercise structure

```
cpp_XX/exYY/
├── Makefile
├── main.cpp
├── includes/        # headers (.hpp)
└── srcs/            # implementations (.cpp)
```

*(the exact layout varies by module: some keep everything at the root)*

### 📝 Personal notes

The repo also contains my OOP/C++ study sheets:

- `lexique_poo_cpp.md`
- `lexique_poo_cpp_part2.md`

Plus a sandbox (`sandbox.cpp` / `sandbox.hpp`) driven by the root `Makefile` for
quickly testing snippets.

---

## Français

Ce dépôt regroupe l'ensemble des modules **CPP 00 → 09** du tronc commun de 42.
Chaque module est une piscine thématique qui introduit progressivement les
concepts de la **programmation orientée objet** et du **C++ moderne (norme C++98)**.

L'objectif du cursus n'est pas d'apprendre des algorithmes, mais de **maîtriser
le paradigme objet** : encapsulation, héritage, polymorphisme, gestion mémoire,
templates et conteneurs de la STL.

### ⚙️ Contrainte de norme

Tous les modules sont compilés avec :

```bash
c++ -Wall -Wextra -Werror -std=c++98
```

Règles imposées par le cursus :
- **C++98 uniquement** (pas de `auto`, `nullptr`, `<thread>`, lambdas, etc.).
- Interdiction des fonctions C (`printf`, `malloc`, `free`, `*alloc`).
- Chaque classe respecte la **Coplien / Orthodox Canonical Form** dès le module 02
  (constructeur par défaut, constructeur par copie, opérateur d'affectation,
  destructeur).
- Pas de `using namespace` sauvage, un header par classe, header guards partout.

### 🚀 Compilation

Chaque exercice possède son propre `Makefile` avec les règles standard :

```bash
cd cpp_02/ex02
make        # compile
make clean  # supprime les .o
make fclean # supprime .o + binaire
make re     # recompile tout
```

Un `Makefile` racine et le script `fclean_all.sh` permettent de nettoyer tous
les exercices d'un coup :

```bash
make fclean-all   # fclean sur tous les cpp_XX/exYY
make clean-all
```

### 📚 Contenu par module

#### CPP 00 — Bases, namespaces, classes, I/O
> Premiers pas en C++ après le C.

- `ex00` **Megaphone** : `std::string`, arguments, mise en majuscules, streams.
- `ex01` **PhoneBook** : première **classe** (`Contact`, `PhoneBook`), tableau
  statique d'objets, membres privés, méthodes publiques, formatage de sortie.
- `ex02` **Account** : lecture d'un log existant, reconstitution d'une classe à
  partir de son comportement, **membres statiques** (variables de classe).

**Notions clés** : `std::cout` / `std::cin`, `std::string`, classes, encapsulation,
membres `static`, séparation `.hpp` / `.cpp`.

#### CPP 01 — Mémoire, références, pointeurs
> Allocation dynamique et différence pile / tas.

- `ex00` **Zombie** : allocation sur la **pile** vs le **tas** (`new`), destructeurs.
- `ex01` **ZombieHorde** : allocation d'un **tableau d'objets** avec `new[]`.
- `ex02` **HI THIS IS BRAIN** : **pointeurs vs références** sur une même variable.
- `ex03` **Weapon** : quand utiliser un pointeur (`HumanB`) ou une référence
  (`HumanA`) comme membre de classe.
- `ex04` **Sed is for losers** : remplacement de chaîne, `std::string` et fichiers
  (`ifstream` / `ofstream`).
- `ex05` **Harl** : appel de méthode via **pointeur sur fonction membre**.
- `ex06` **Harl filter** : `switch` et filtrage des niveaux de log.

**Notions clés** : `new` / `delete`, pointeurs, références, pointeurs sur membres,
lecture/écriture de fichiers, durée de vie des objets.

#### CPP 02 — Ad-hoc polymorphism, surcharge d'opérateurs, Forme canonique
> Construction d'une classe numérique complète.

- `ex00` **Fixed** : classe de **nombres à virgule fixe**, mise en place de la
  **Orthodox Canonical Form**.
- `ex01` **Fixed** : conversions int/float ↔ fixed, surcharge de `operator<<`.
- `ex02` **Fixed** : surcharge des opérateurs de **comparaison, arithmétiques,
  incrémentation**, méthodes `min` / `max`.
- `ex03` **BSP** : utilisation concrète de la classe `Fixed` avec des `Point` pour
  déterminer si un point est dans un triangle.

**Notions clés** : forme canonique de Coplien, surcharge d'opérateurs,
représentation en virgule fixe, `const` correctness.

#### CPP 03 — Héritage
> Réutilisation et spécialisation de classes.

- `ex00` **ClapTrap** : classe de base.
- `ex01` **ScavTrap** : héritage simple, ordre construction / destruction.
- `ex02` **FragTrap** : nouvelle spécialisation.
- `ex03` **DiamondTrap** : **héritage en diamant**, héritage virtuel.

**Notions clés** : héritage public, chaînage des constructeurs/destructeurs,
héritage multiple, problème du diamant et `virtual`.

#### CPP 04 — Polymorphisme, abstraction, interfaces
> Le cœur de la POO.

- `ex00` **Polymorphism** : `Animal` / `Dog` / `Cat`, **fonctions virtuelles**.
- `ex01` **Brain** : deep copy vs shallow copy avec allocation dynamique.
- `ex02` **Abstract class** : rendre `Animal` **abstraite** (méthode virtuelle pure).
- `ex03` **Interface & recap** : interfaces (`AMateria`, `ICharacter`,
  `IMateriaSource`), inventaire d'objets.

**Notions clés** : `virtual`, méthodes virtuelles pures, classes abstraites,
interfaces, destructeurs virtuels, copie profonde.

#### CPP 05 — Try / Catch, exceptions
> Gestion des erreurs à l'objet.

- `ex00` **Bureaucrat** : classe avec invariants, lancement d'**exceptions**.
- `ex01` **Form** : exceptions personnalisées héritant de `std::exception`.
- `ex02` **Concrete forms** : hiérarchie de formulaires, exécution conditionnelle.
- `ex03` **Intern** : création d'objets via une **factory** (pointeurs sur membres).

**Notions clés** : `throw` / `try` / `catch`, classes d'exception dérivées de
`std::exception`, `what()`, design par factory.

#### CPP 06 — Conversions de type & casts C++
> Les différents casts et leur usage.

- `ex00` **Scalar conversion** : conversions explicites entre types scalaires.
- `ex01` **Serialization** : `reinterpret_cast` (pointeur ↔ entier).
- `ex02` **Real type** : identification du type réel via `dynamic_cast`.

**Notions clés** : `static_cast`, `dynamic_cast`, `reinterpret_cast`,
`const_cast`, RTTI, sérialisation.

#### CPP 07 — Templates
> Programmation générique.

- `ex00` **Whatever** : templates de **fonctions** (`swap`, `min`, `max`).
- `ex01` **Iter** : template appliquant une fonction à un tableau générique.
- `ex02` **Array** : template de **classe** conteneur avec gestion mémoire et
  `operator[]` sécurisé (exception hors limites).

**Notions clés** : `template<typename T>`, templates de fonction et de classe,
généricité, contraintes de type implicites.

#### CPP 08 — Templated containers, iterators, algorithms
> La STL commence.

- `ex00` **Easyfind** : recherche dans un conteneur générique, `std::find`.
- `ex01` **Span** : stockage de N entiers, calcul du plus petit / plus grand écart,
  remplissage par plage d'itérateurs.
- `ex02` **MutantStack** : rendre `std::stack` **itérable** par héritage.

**Notions clés** : conteneurs STL (`vector`, `list`, `stack`), **itérateurs**,
algorithmes standards (`<algorithm>`), adaptation de conteneurs.

#### CPP 09 — La STL en pratique
> Projets synthétisant conteneurs et algorithmes.

- `ex00` **Bitcoin Exchange** : parsing de fichiers CSV, `std::map`, association
  date → valeur, recherche de la date la plus proche. *(voir `input.csv`)*
- `ex01` **RPN** : calculatrice en **notation polonaise inverse** avec `std::stack`.
- `ex02` **PmergeMe** : tri par fusion-insertion **Ford-Johnson** implémenté sur
  deux conteneurs (`std::vector` et `std::deque`) avec comparaison des
  temps d'exécution. Contient un visualiseur (`docs/pmerge_visualizer.html`) et
  des notes (`cpp09_ex02_pmergeme.md`).

**Notions clés** : `std::map`, `std::stack`, `std::vector`, choix du bon conteneur,
parsing robuste, algorithme de tri Ford-Johnson, mesure de performance.

### 🗂️ Structure type d'un exercice

```
cpp_XX/exYY/
├── Makefile
├── main.cpp
├── includes/        # headers (.hpp)
└── srcs/            # implémentations (.cpp)
```

*(l'organisation exacte varie selon les modules : certains gardent tout à la racine)*

### 📝 Notes personnelles

Le dépôt contient également mes fiches de révision POO/C++ :

- `lexique_poo_cpp.md`
- `lexique_poo_cpp_part2.md`

Ainsi qu'un bac à sable (`sandbox.cpp` / `sandbox.hpp`) piloté par le `Makefile`
racine pour tester rapidement des bouts de code.

---

*C++ cursus — 42 Common Core.*
