# cpp_04 — À corriger avant de rendre

Tout compile sans warning (`-Wall -Wextra -Werror -std=c++98`). 2 grosses erreurs en ex01/ex02, quelques fuites en ex03.

---

## 🔴 PRIORITÉ — ex01 et ex02 (Cat ET Dog : 4 fichiers)

Fichiers concernés :
- `ex01/Cat/Cat.cpp`
- `ex01/Dog/Dog.cpp`
- `ex02/Cat/Cat.cpp`
- `ex02/Dog/Dog.cpp`

### Erreur 1 — `operator=` : copie superficielle → double free
Actuellement (exemple Cat) :
```cpp
Cat & Cat::operator=(const Cat& src)
{
    if (this != &src)
    {
        if (this->_myBrain)
            delete this->_myBrain;
        for (int i = 0; i < 100; i++)
            this->_myBrain = src._myBrain;   // copie le POINTEUR -> double free + pas de deep copy
    }
    return(*this);
}
```
Corriger en :
```cpp
Cat & Cat::operator=(const Cat& src)
{
    std::cout << "Cat operator assignement called" << std::endl;
    if (this != &src)
    {
        Animal::operator=(src);              // recopie _type
        delete this->_myBrain;
        this->_myBrain = new Brain(*src._myBrain);
    }
    return (*this);
}
```
(idem Dog : remplacer `Cat` par `Dog`)

### Erreur 2 — copy constructor : `delete` d'un pointeur non initialisé
Actuellement (exemple Cat) :
```cpp
Cat::Cat(const Cat& to_copy)
    :Animal(to_copy)
{
    if (this->_myBrain)        // _myBrain pas encore initialise -> valeur garbage
        delete this->_myBrain; // delete garbage = comportement indefini
    this->_myBrain = new Brain(*(to_copy._myBrain));
    ...
}
```
Corriger en (supprimer le if/delete) :
```cpp
Cat::Cat(const Cat& to_copy)
    :Animal(to_copy)
{
    this->_myBrain = new Brain(*to_copy._myBrain);
    std::cout << "Cat copy constructor called" << std::endl;
}
```

---

## 🟠 ex03 — fuites mémoire (valgrind : 160 bytes, 4 blocs)

- `ICharacter/ICharacter.cpp` — `equip()` : si l'inventaire est plein, `m` n'est ni stocké ni libéré.
  -> ajouter `delete m;` avant le `return` du cas "inventory full".
- `AMateria/AMateria.cpp` — `learnMateria()` : si les 4 slots sont pleins, `m` est perdu.
  -> ajouter `delete m;` avant de sortir.
- `unequip()` qui ne delete pas = VOULU par le sujet, ne pas toucher.

---

## 🟢 Détail cosmétique (optionnel)
- `ex00/WrongAnimal/Wrong.cpp:36` : faute de frappe `"I'm a Wromg Animal"` -> `"Wrong"`.

---

## Vérif après correction
```bash
make -C ex01 re && make -C ex02 re && make -C ex03 re
valgrind --leak-check=full ./ex03/materia   # viser 0 "definitely lost" hors unequip
```
