# 🎓 Cours CPP06 — Les conversions de type en C++ (*casts*)

> Cours conceptuel : comprendre **ce que demande** le CPP06 et **les outils** à maîtriser.
> ⚠️ Ce document explique les **concepts**, pas les solutions des exercices. Le code de tes exos, c'est à toi de l'écrire.
> Complément des lexiques [Partie 1](lexique_poo_cpp.md) et [Partie 2](lexique_poo_cpp_part2.md).

**Conventions** (mêmes que les lexiques) : 📘 définition · 🎬 exemple · 🎨 métaphore · 🧠 mnémo · ⚠️ piège · 🔍 règle pratique · 🚀 lien avec un exercice 42.

---

## 📑 Table des matières

**Le décor**
1. [De quoi parle le CPP06 ?](#-de-quoi-parle-le-cpp06-)
2. [Rappel : types scalaires et représentation mémoire](#-rappel--types-scalaires-et-représentation-mémoire)
3. [Conversion implicite vs explicite](#-conversion-implicite-vs-explicite)

**Les 4 casts du C++**
4. [Pourquoi 4 casts (et pas le cast à la C) ?](#-pourquoi-4-casts-et-pas-le-cast-à-la-c-)
5. [`static_cast`](#-static_cast)
6. [`dynamic_cast`](#-dynamic_cast)
7. [`reinterpret_cast`](#-reinterpret_cast)
8. [`const_cast`](#-const_cast)
9. [Tableau de décision : quel cast choisir ?](#-tableau-de-décision--quel-cast-choisir-)

**Les notions par thème d'exercice**
10. [Convertir des scalaires (esprit ex00)](#-convertir-des-scalaires-esprit-ex00)
11. [Sérialiser un pointeur (esprit ex01)](#-sérialiser-un-pointeur-esprit-ex01)
12. [Identifier le vrai type (esprit ex02)](#-identifier-le-vrai-type-esprit-ex02)

**Annexes**
13. [Pièges classiques](#-pièges-classiques)
14. [Quiz d'auto-évaluation](#-quiz-dauto-évaluation)

---

## 🧭 De quoi parle le CPP06 ?

📘 Le CPP06 a un seul grand thème : **convertir des données d'un type vers un autre**, proprement et en comprenant ce qui se passe vraiment en mémoire. C'est le module des **casts**.

Le C++ propose **4 opérateurs de conversion** (`static_cast`, `dynamic_cast`, `reinterpret_cast`, `const_cast`). Chacun a un rôle précis, et chaque exercice du module en met un à l'honneur :

| Thème de l'exercice | Question posée | Cast central |
|---|---|---|
| Conversion de scalaires | « Comment passer d'un `int` à un `float`, un `char`... ? » | `static_cast` |
| Sérialisation | « Comment transformer une adresse en nombre, et inversement ? » | `reinterpret_cast` |
| Identifier le vrai type | « Cet objet de base est en réalité de quel type dérivé ? » | `dynamic_cast` |

🎯 **L'objectif pédagogique** : arrêter le cast « à la C » (`(int)x`) qui fait tout et n'importe quoi, et apprendre à dire **précisément** quelle conversion tu veux — le compilateur t'aide alors à éviter les bêtises.

---

## 🔢 Rappel : types scalaires et représentation mémoire

📘 Un **type scalaire** est un type qui contient **une seule valeur** (par opposition à un objet/conteneur). Les principaux :

| Type | Contient | Taille typique |
|---|---|---|
| `char` | un caractère / un petit entier | 1 octet |
| `int` | un entier | 4 octets |
| `float` | un réel simple précision | 4 octets |
| `double` | un réel double précision | 8 octets |

🔑 **Idée clé** : ces types ne stockent pas tous l'information de la même façon. Un `float` et un `int` de même taille (4 octets) **interprètent leurs bits différemment**. Convertir, ce n'est donc pas « recopier les octets », c'est **réinterpréter du sens**.

🎨 **Métaphore** : le même mot « PAIN » écrit sur un papier veut dire « nourriture » en français et « douleur » en anglais. Mêmes lettres (mêmes octets), **sens différent selon le type/langue**. Une conversion bien faite traduit le **sens**, pas juste les lettres.

🔍 **Bornes et valeurs spéciales** (header `<limits>` et `<cmath>`) :
- `std::numeric_limits<int>::max()` / `::min()` → les bornes d'un type. Utile pour détecter un **dépassement** (*overflow*).
- Les `float`/`double` ont des valeurs **spéciales** : l'infini (`+inf`, `-inf`) et le « pas-un-nombre » (`nan`, *Not a Number*). Elles ne se comparent pas comme des nombres normaux (`nan != nan` est `true` !).

---

## 🔄 Conversion implicite vs explicite

### Implicite (le compilateur le fait tout seul)

```cpp
int   i = 65;
double d = i;      // conversion IMPLICITE int → double, automatique
char  c = i;       // implicite aussi : c devient 'A' (code ASCII 65)
```

Le compilateur convertit silencieusement quand il « sait » faire. Pratique, mais **dangereux** : une conversion `double → int` perd la partie décimale **sans prévenir**.

### Explicite (tu demandes la conversion)

```cpp
double d = 3.99;
int    i = static_cast<int>(d);   // explicite : tu ASSUMES la troncature (i == 3)
```

🧠 **Mnémotechnique** : *« Explicite = je signe pour la perte. »* Tu déclares au compilateur que tu **sais** ce que tu fais.

🚀 **Lien CPP06** : le sujet insiste sur le mot **« explicitly »** — tu dois convertir avec un cast visible, pas compter sur l'implicite. C'est tout l'esprit du module.

---

## 🧰 Pourquoi 4 casts (et pas le cast à la C) ?

📘 En C, il n'existe qu'**un seul** cast : `(type)valeur`. Il fait **tout** — conversions sûres, dangereuses, illégales — **sans distinction**. C'est précisément le problème.

```cpp
// Cast à la C : que veut dire ce code ? Impossible à savoir sans réfléchir longtemps
Animal* a = (Animal*)somePointer;   // conversion de type ? réinterprétation brutale ?
```

Le C++ **éclate** ce cast unique en **4 opérateurs nommés**, chacun avec une intention claire :

| Cast | Intention | Vérifié à... |
|---|---|---|
| `static_cast` | conversion « logique » et sûre entre types liés | la **compilation** |
| `dynamic_cast` | descendre dans une hiérarchie en **vérifiant** le vrai type | l'**exécution** |
| `reinterpret_cast` | réinterpréter les **bits** tels quels (bas niveau) | rien (à tes risques) |
| `const_cast` | ajouter/retirer le `const` (ou `volatile`) | la compilation |

**Avantages des casts nommés** :
1. **Lisibilité** : le lecteur voit immédiatement *quel genre* de conversion tu fais.
2. **Sécurité** : le compilateur **refuse** un `static_cast` absurde, alors que le cast C l'aurait laissé passer.
3. **Recherche** : tu peux `grep reinterpret_cast` pour auditer toutes les conversions dangereuses du projet.

🧠 **Mnémotechnique** : *« Static = sûr, Dynamic = vérifié, Reinterpret = brutal, Const = juste le const. »*

---

## ✅ `static_cast`

📘 La conversion **standard** entre types **logiquement liés** : entre numériques (`int`↔`float`↔`double`↔`char`), ou dans une hiérarchie de classes quand tu es **sûr** du type. Vérifié à la **compilation**.

```cpp
double pi  = 3.14159;
int    n   = static_cast<int>(pi);     // 3 (troncature assumée)
char   c   = static_cast<char>(65);    // 'A'
float  f   = static_cast<float>(n);    // 3.0f
```

**Ce qu'il sait faire** :
- Conversions numériques (avec perte éventuelle, mais **logique**).
- *Upcast* (fille → mère) : toujours sûr.
- *Downcast* (mère → fille) **sans vérification** : autorisé, mais c'est **à toi** de garantir que le type est bon (sinon → comportement indéfini). Pour un downcast **vérifié**, utilise `dynamic_cast`.

⚠️ **Ce qu'il refuse** : convertir entre types **sans rapport** (ex. `int*` → `float*`). Le compilateur t'arrête → c'est une **bonne** chose, ça t'évite une erreur.

🧠 **Mnémotechnique** : *« static_cast = la conversion que tu écrirais "à la main", mais propre et vérifiée. »*

🚀 **Lien CPP06** : c'est l'outil de base pour passer une valeur entre `char`/`int`/`float`/`double`.

---

## 🔎 `dynamic_cast`

📘 Sert à **descendre** dans une hiérarchie de classes (mère → fille) **en vérifiant à l'exécution** que la conversion est légitime. Ne fonctionne **que** sur des classes **polymorphes** (qui ont au moins une méthode `virtual` — typiquement un destructeur virtuel).

```cpp
Animal* a = getSomeAnimal();          // on a un Animal*, mais lequel vraiment ?

Dog* d = dynamic_cast<Dog*>(a);       // est-ce un Dog ?
if (d != NULL)
    std::cout << "C'était bien un Dog !" << std::endl;
else
    std::cout << "Non, ce n'était pas un Dog." << std::endl;
```

### 🔑 Comportement en cas d'échec : pointeur vs référence

C'est **LE** point à comprendre du module :

| Sur un... | Si la conversion échoue... |
|---|---|
| **pointeur** (`dynamic_cast<Dog*>`) | renvoie **`NULL`** → tu testes avec un `if` |
| **référence** (`dynamic_cast<Dog&>`) | **lève `std::bad_cast`** → tu testes avec un `try/catch` |

```cpp
// version référence : on ne peut pas renvoyer NULL (une référence n'est jamais nulle)
try {
    Dog& d = dynamic_cast<Dog&>(someAnimalRef);
    // ... c'est un Dog
}
catch (std::bad_cast& e) {
    // ... ce n'était pas un Dog
}
```

🎨 **Métaphore** : `dynamic_cast`, c'est un **contrôle d'identité**. Tu demandes « es-tu un Dog ? ». Avec un pointeur, on te répond « non » poliment (`NULL`). Avec une référence, comme tu **affirmais** que c'en était un, on lève une **alarme** (`bad_cast`).

🧠 **Mnémotechnique** : *« dynamic = je vérifie à l'exécution. Pointeur → NULL, référence → exception. »*

🚀 **Lien CPP06** : c'est l'outil pour identifier le **vrai type** d'un objet manipulé via sa classe de base — **sans** utiliser `typeid`/`<typeinfo>` (que le sujet interdit). Les deux comportements (NULL vs exception) sont exactement pourquoi le sujet demande une version « pointeur » et une version « référence ».

---

## ⚡ `reinterpret_cast`

📘 La conversion **bas niveau** : prendre un paquet de bits et le **réinterpréter** comme un autre type, **sans aucune vérification ni transformation**. Le plus **dangereux** des quatre.

```cpp
Animal*   a   = new Animal();
uintptr_t raw = reinterpret_cast<uintptr_t>(a);   // l'adresse vue comme un entier
Animal*   b   = reinterpret_cast<Animal*>(raw);   // l'entier re-vu comme une adresse
// ici, a == b : on a fait l'aller-retour sans rien casser
```

🔑 **L'idée** : une adresse mémoire **est** un nombre. `reinterpret_cast` te laisse passer de « pointeur » à « entier » et inversement. Tant que tu fais l'**aller-retour exact**, tu récupères le pointeur d'origine intact.

📘 **`uintptr_t`** (header `<stdint.h>`/`<cstdint>`) : un type entier **non signé** garanti assez grand pour contenir une adresse. C'est le « bon » type entier pour stocker un pointeur.

⚠️ **Pourquoi c'est dangereux** : `reinterpret_cast` ne **vérifie rien**. Si tu réinterprètes vers un mauvais type et que tu t'en sers, tu lis de la mémoire n'importe comment → crash ou bug silencieux. Il ne **change pas** les bits, il change seulement **comment on les lit**.

🎨 **Métaphore** : c'est regarder la **même photo** à travers des lunettes différentes. La photo (les bits) ne change pas ; ce que ton cerveau y voit, oui. Mets les mauvaises lunettes → tu vois n'importe quoi.

🧠 **Mnémotechnique** : *« reinterpret = mêmes bits, autre regard. Aucun filet de sécurité. »*

🚀 **Lien CPP06** : c'est le cœur de la **sérialisation** — transformer une adresse en nombre (et inversement) pour, par exemple, la stocker ou la transmettre. Le test classique : sérialiser puis désérialiser doit redonner **exactement** le pointeur de départ.

---

## 🔓 `const_cast`

📘 Le seul cast capable d'**ajouter ou retirer** le qualificatif `const` (ou `volatile`) d'une variable. Il ne change **pas** le type, juste la « constance ».

```cpp
void legacyPrint(char* s);          // vieille API qui ne prend pas const

void show(const char* msg) {
    legacyPrint(const_cast<char*>(msg));   // on retire le const pour appeler l'API
}
```

⚠️ **Danger** : retirer le `const` puis **modifier réellement** une variable qui était vraiment `const` à l'origine = **comportement indéfini**. `const_cast` ne sert légitimement qu'à **s'interfacer** avec du code mal foutu (souvent du vieux C) qui oublie le `const`, pas à tricher.

🧠 **Mnémotechnique** : *« const_cast = j'enlève juste le panneau "interdit", à mes risques. »*

🚀 **Lien CPP06** : moins central que les autres dans ce module, mais il **complète le quatuor** des casts qu'il faut connaître. À comprendre pour la culture et la défense.

---

## 🧮 Tableau de décision : quel cast choisir ?

| Ta situation | Cast à utiliser |
|---|---|
| Convertir un `int` en `double`, un `double` en `char`... | `static_cast` |
| Monter dans la hiérarchie (fille → mère) | `static_cast` (ou implicite) |
| Descendre (mère → fille) en **vérifiant** le vrai type | `dynamic_cast` |
| Savoir « cet objet de base est-il de tel type dérivé ? » | `dynamic_cast` |
| Transformer un pointeur en entier (ou l'inverse) | `reinterpret_cast` |
| Ajouter / retirer un `const` | `const_cast` |
| Tu hésites entre deux casts | tu n'as probablement pas le bon **design** — réfléchis avant de caster |

🔍 **Règle d'or** : commence **toujours** par te demander si `static_cast` suffit. Les trois autres sont des outils de cas particuliers (héritage vérifié, bas niveau, const). Un projet rempli de `reinterpret_cast` est presque toujours un projet mal conçu.

---

## 🔡 Convertir des scalaires (esprit ex00)

> Concepts seulement — la logique de détection et la classe, c'est ton travail.

Le défi conceptuel : on te donne **du texte** (une `std::string` comme `"42.0f"`) et tu dois retrouver **quel type** ça représente, puis afficher la valeur dans les 4 types scalaires.

Les notions à maîtriser :

1. **Détecter le type d'un littéral** est un problème d'**analyse de chaîne** (parsing), pas un problème de cast. Un `char` est un seul caractère non numérique, un `int` n'a pas de point, un `float` finit par `f`, un `double` a un point... C'est de la **logique**, à toi de la concevoir.

2. **Une fois la valeur dans son vrai type**, les conversions vers les 3 autres se font avec `static_cast` (la partie « cast » du module).

3. **Les valeurs spéciales** des flottants (`nan`, `+inf`, `-inf` et leurs versions `f`) ne sont **pas** des nombres ordinaires. Tu dois les reconnaître et les traiter à part. Header utile : `<cmath>`.

4. **Les conversions impossibles ou qui débordent** doivent être signalées (« impossible »). D'où l'usage de `<limits>` (`std::numeric_limits`) pour savoir si une valeur **rentre** dans le type cible.

5. **Un `char` non affichable** (code de contrôle) ne doit pas être imprimé tel quel → message informatif. Notion : tous les `int` valides ne correspondent pas à un caractère imprimable (voir `isprint`).

6. **Classe non instanciable** : la classe ne stocke rien → elle ne doit **exister** que pour héberger une méthode `static`. Concept à creuser : comment **empêcher** la création d'objets d'une classe (indice : la visibilité du constructeur — déjà vue en [Partie 1](lexique_poo_cpp.md#--public--private---protected---la-visibilité-access-specifiers)).

🧠 **À retenir** : *« Parser pour trouver le type, `static_cast` pour le reste, `<limits>`/`<cmath>` pour les cas limites. »*

---

## 📦 Sérialiser un pointeur (esprit ex01)

> Concepts seulement.

📘 **Sérialiser**, au sens large, c'est transformer une donnée en une **représentation transportable/stockable**, puis pouvoir la **reconstruire** à l'identique (désérialiser).

Ici, la donnée est un **pointeur** (une adresse), et la représentation est un **entier** (`uintptr_t`). Les notions :

1. **Une adresse est un nombre** : c'est l'intuition de fond. `reinterpret_cast` matérialise cette équivalence.

2. **L'aller-retour doit être parfait** : `pointeur → entier → pointeur` doit redonner **exactement** le pointeur de départ. C'est la propriété que tu dois **vérifier** dans ton programme de test (comparer le pointeur reconstruit à l'original).

3. **`uintptr_t`** est le type entier **fait pour ça** : assez large pour contenir n'importe quelle adresse de la machine. Utiliser un `int` ordinaire risquerait de **tronquer** l'adresse.

4. **Classe non instanciable** (même idée que l'ex00) : la classe n'est qu'un porteur de méthodes `static`.

🎨 **Métaphore** : tu notes l'adresse d'une maison sur un papier (sérialisation = pointeur → nombre). Plus tard, tu relis le papier et tu retrouves **la même maison** (désérialisation = nombre → pointeur). Le papier ne contient pas la maison, juste de quoi la **retrouver**.

🧠 **À retenir** : *« reinterpret_cast + uintptr_t = pointeur ⇄ entier, aller-retour exact. »*

---

## 🕵️ Identifier le vrai type (esprit ex02)

> Concepts seulement.

Le défi : tu as un pointeur (ou une référence) vers une **classe de base**, mais l'objet réel est d'une **classe dérivée** inconnue. Comment savoir laquelle **sans** `typeid` (interdit par le sujet) ?

Les notions :

1. **Le polymorphisme est requis** : `dynamic_cast` n'opère que sur des classes **polymorphes**. La base doit avoir au moins une méthode `virtual` — d'où le **destructeur virtuel** demandé. (Rappel [Partie 1](lexique_poo_cpp.md#-polymorphisme-de-sous-type).)

2. **La technique d'identification** : tenter un `dynamic_cast` vers chaque type dérivé possible. Celui qui **réussit** révèle le vrai type. C'est une idée simple ; à toi de l'appliquer à tes classes.

3. **Pointeur vs référence** (le point clé du module) :
   - Avec un **pointeur**, un `dynamic_cast` raté renvoie `NULL` → on teste par `if`.
   - Avec une **référence**, il **lève `std::bad_cast`** → on teste par `try/catch`.
   
   C'est **exactement** pourquoi le sujet demande deux fonctions (une version pointeur, une version référence) : pour te faire pratiquer **les deux mécanismes d'échec**.

4. **Génération aléatoire** : produire au hasard un objet d'un des types. Concept annexe (nombres pseudo-aléatoires) ; le cœur pédagogique reste le `dynamic_cast`.

🎨 **Métaphore** : un colis sans étiquette (`Base*`). Tu essaies plusieurs clés (`dynamic_cast<A*>`, `<B*>`, `<C*>`) ; celle qui ouvre la serrure t'indique le contenu réel.

🧠 **À retenir** : *« dynamic_cast = la sonde qui révèle le vrai type. NULL côté pointeur, exception côté référence. »*

---

## ⚠️ Pièges classiques

| Piège | Pourquoi c'est un problème |
|---|---|
| Utiliser un cast **à la C** `(int)x` | Cache l'intention, contourne les vérifications. Interdit dans l'esprit du module. |
| `dynamic_cast` sur une classe **non polymorphe** | Ne compile pas : il faut au moins une méthode `virtual` dans la base. |
| Oublier le `try/catch` sur un `dynamic_cast` de **référence** | Un échec lève `std::bad_cast` → crash non géré. |
| Tester un `dynamic_cast` de **pointeur** sans vérifier le `NULL` | Tu déréférences potentiellement `NULL` → segfault. |
| Stocker un pointeur dans un `int` au lieu de `uintptr_t` | Adresse **tronquée** sur les systèmes 64 bits → aller-retour cassé. |
| Modifier une vraie variable `const` après `const_cast` | Comportement indéfini. |
| Comparer `nan == nan` en pensant que c'est `true` | `nan` n'est égal à **rien**, pas même à lui-même. |
| Convertir `double → int` sans penser à l'**overflow** | La valeur peut ne pas rentrer → résultat invalide à signaler. |

---

## 🎯 Quiz d'auto-évaluation

### Niveau 1 — Les casts

1. Quels sont les 4 casts du C++ et l'intention de chacun ?
2. Pourquoi préfère-t-on les casts nommés du C++ au cast « à la C » ?
3. Quelle est la différence entre une conversion implicite et explicite ?
4. Quel cast utilises-tu pour passer d'un `double` à un `int` ?

### Niveau 2 — `dynamic_cast`

5. À quelle condition une classe peut-elle être la cible d'un `dynamic_cast` ?
6. Que renvoie un `dynamic_cast` **de pointeur** qui échoue ? Et un `dynamic_cast` **de référence** ?
7. Pourquoi le sujet demande-t-il une version « pointeur » **et** une version « référence » de l'identification ?
8. Comment identifier le vrai type d'un objet **sans** `typeid` ?

### Niveau 3 — Bas niveau et scalaires

9. Pourquoi une adresse mémoire peut-elle être stockée dans un `uintptr_t` ?
10. Que garantit l'aller-retour `reinterpret_cast` pointeur → entier → pointeur ?
11. Pourquoi `reinterpret_cast` est-il le plus dangereux des casts ?
12. À quoi servent `<limits>` et `<cmath>` quand on convertit des scalaires ?

---

*Cours CPP06 — concepts des casts. À toi de coder les exos ! Bonne continuation, fducrot !* 🚀
