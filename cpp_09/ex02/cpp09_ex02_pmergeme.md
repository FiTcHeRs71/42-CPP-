# CPP09 — Exercice 02 : PmergeMe (tri de Ford-Johnson)

> Cours de préparation : intuition, déroulé pas à pas, contraintes du module et
> questions de défense. Pas de solution clé en main — l'implémentation reste à toi
> (règle 42 sur l'IA).

---

## 1. Ce que demande le sujet

- Programme nommé `PmergeMe`, qui prend une suite d'**entiers positifs** en argument.
- Tri obligatoire par **merge-insertion sort**, c.-à-d. l'algorithme **Ford-Johnson**
  (réf. Knuth, *The Art of Computer Programming*, Vol. 3, p. 184).
- **Deux conteneurs différents** (seul exercice du module à en exiger deux), chacun
  capable de gérer **au moins 3000 entiers**.
- Affichage :
  1. la suite **avant** tri,
  2. la suite **après** tri,
  3. le **temps** de traitement du **1er** conteneur,
  4. le **temps** de traitement du **2e** conteneur.
- Précision du temps libre, mais suffisante pour **distinguer les deux conteneurs**.
- Toute erreur → message sur la **sortie d'erreur** (`stderr`).
- Le sujet **conseille d'implémenter l'algo séparément pour chaque conteneur**
  plutôt qu'une fonction générique.
- Gestion des **doublons** laissée à ta discrétion.
- Rappel : les conteneurs utilisés en ex00 (`std::map`) et ex01 sont **interdits** ici.

---

## 2. Le vrai problème : minimiser les comparaisons

Ford-Johnson n'optimise pas le nombre d'opérations (`O(n log n)`) mais le **nombre de
comparaisons** entre éléments, dans le pire des cas. Pour de petits `n`, il s'approche de
la borne théorique minimale `⌈log₂(n!)⌉`.

Idée centrale, contre-intuitive : on accepte **plus de déplacements de données** et une
structure plus compliquée, en échange de **moins de comparaisons**. C'est tout l'enjeu — et
la raison pour laquelle l'exercice est difficile.

---

## 3. Vue d'ensemble : les 5 phases

```
1 · Appariement              n/2 paires, 1 reste éventuel (straggler)
        │
2 · Comparaison interne      gagnant = grand, perdant = petit
        │
3 · Tri récursif des gagnants   (le cœur)   même algo sur la "main chain"
        │
4 · Insertion du 1er perdant   b1 < a1, va en tête SANS comparaison
        │
5 · Insertion des autres        (le cœur)   ordre de Jacobsthal + dichotomie
```

---

## 4. Déroulé pas à pas

Exemple fil rouge : `11 5 8 2 7 9`.

### Phase 1 — Appariement
On groupe deux par deux : `(11,5) (8,2) (7,9)`. Ici `n = 6` est pair → pas de reste.
Si `n` était impair, un élément resterait seul : le **straggler**, mis de côté pour la fin.

### Phase 2 — Comparaison interne
Dans chaque paire, le plus grand = **gagnant** `aᵢ`, le plus petit = **perdant** `bᵢ`,
en gardant le lien :

| paire    | gagnant | perdant |
|----------|---------|---------|
| (11, 5)  | 11      | 5       |
| (8, 2)   | 8       | 2       |
| (7, 9)   | 9       | 7       |

### Phase 3 — Tri récursif des gagnants
On trie les gagnants `[11, 8, 9]` **avec le même algorithme** (récursion) → `[8, 9, 11]`.
Crucial : **les perdants suivent leur gagnant** lors du réordonnancement.

Après tri (la **main chain** = chaîne triée des gagnants) :

- `a₁ = 8`  (perdant `b₁ = 2`)
- `a₂ = 9`  (perdant `b₂ = 7`)
- `a₃ = 11` (perdant `b₃ = 5`)

Les perdants restants forment la **pend** (en attente d'insertion).

### Phase 4 — Insertion du premier perdant
`b₁` est associé au plus petit gagnant `a₁`. Comme `b₁ < a₁` et que `a₁` est déjà le plus
petit de la chaîne, `b₁` est plus petit que tout le monde → insertion **en tête, sans
aucune comparaison**.

Chaîne : `[2, 8, 9, 11]`.

### Phase 5 — Insertion des perdants restants
Reste `b₂ = 7` et `b₃ = 5`. Deux propriétés rendent ça efficace :

1. Insertion par **recherche dichotomique** (binary search), pas linéaire.
2. On sait `bᵢ < aᵢ` → on **borne** la recherche au préfixe qui s'arrête à `aᵢ`.
   La borne est donc connue gratuitement.

L'ordre d'insertion suit la **suite de Jacobsthal** (voir §5).
Groupe 1 (borne 3) → insérer `b₃` puis `b₂` :

- `b₃ = 5`, `5 < a₃ = 11` → dichotomie → entre 2 et 8 → `[2, 5, 8, 9, 11]`
- `b₂ = 7`, `7 < a₂ = 9`  → dichotomie → entre 5 et 8 → `[2, 5, 7, 8, 9, 11]`

Résultat trié : `2 5 7 8 9 11`.

> S'il y avait un straggler, on l'insérerait **en tout dernier**, par une dichotomie sur la
> chaîne complète.

---

## 5. Les nombres de Jacobsthal — pourquoi un ordre « bizarre »

Pourquoi ne pas insérer `b₂, b₃, b₄, …` dans l'ordre naturel ? Parce que l'ordre change la
**taille de la zone de recherche dichotomique**, donc le nombre de comparaisons.

Une dichotomie dans une zone de taille `2ᵏ − 1` coûte exactement `k` comparaisons au pire.
On veut donc insérer les perdants de sorte qu'à chaque palier la zone reste juste **sous une
puissance de 2**. C'est ce que garantit la suite de Jacobsthal.

```
Suite : Jₙ = Jₙ₋₁ + 2·Jₙ₋₂
Valeurs : 0, 1, 1, 3, 5, 11, 21, 43, 85, …

Groupe 1  (borne J = 3)   → insérer  b₃, b₂              (indices décroissants)
Groupe 2  (borne J = 5)   → insérer  b₅, b₄
Groupe 3  (borne J = 11)  → insérer  b₁₁, b₁₀, b₉, b₈, b₇, b₆
…

Ordre global : b₁ (gratuit), puis b₃ b₂, puis b₅ b₄, puis b₁₁…b₆, etc.
```

**Pourquoi décroissant dans un groupe ?** Si tu insérais `b₂` avant `b₃`, la chaîne
grandirait d'un cran et la borne `aᵢ` du perdant suivant se décalerait : la zone de recherche
ne ferait plus exactement `2ᵏ − 1`, et tu perdrais l'optimalité. L'ordre décroissant garantit
que chaque insertion d'un groupe tombe sur une zone « puissance de 2 moins 1 ».

---

## 6. Spécificités du module 09

### Les deux conteneurs
But réel : **mesurer et comparer** les performances du même algorithme sur deux structures.
Interdits : ceux d'ex00 (`std::map`) et d'ex01. Choix classique : `std::vector` + `std::deque`
(ou `std::list`). Le sujet recommande d'écrire le tri **deux fois** (une version par conteneur)
plutôt qu'un template générique, pour une comparaison honnête.

### Le chronométrage
En C++98 : `std::clock()` (`<ctime>`) ou `gettimeofday()` (`<sys/time.h>`). Pas de `std::chrono`.
**Piège du sujet** : le temps affiché doit couvrir **le tri ET la gestion des données**
(parsing des arguments dans le conteneur), pas seulement l'appel au tri. Précision en
microsecondes recommandée.

### Erreurs et cas limites à tester
- 0 argument, 1 élément, 2 éléments.
- Nombre négatif (le sujet rejette `"-1"`).
- Entrée non numérique.
- Dépassement d'`INT_MAX`.
- 3000+ éléments : `./PmergeMe $(shuf -i 1-100000 -n 3000 | tr "\n" " ")`.
- Doublons : choix libre, mais **justifiable** (rejet ou tri quand même).

Tout message d'erreur → `stderr`.

---

## 7. Le vrai piège d'implémentation

La difficulté n°1 n'est ni la dichotomie ni Jacobsthal, mais **suivre l'association
gagnant↔perdant à travers la récursion**. Quand tu tries les gagnants, comment conserver le
lien vers leur perdant ?

Pistes possibles (à explorer toi-même) :
- trier des **paires** ou des **indices** au lieu de valeurs isolées ;
- raisonner par **blocs** d'éléments plutôt que par valeurs isolées.

C'est ce qui sépare une implémentation robuste d'une qui « marche par chance » sur les petits
cas. Réfléchis à cette structure **avant** d'écrire la moindre ligne.

### Contraintes C++98 à garder en tête
- Pas de lambdas → **pointeurs de fonction** ou **foncteurs** pour comparateurs / génération
  de Jacobsthal.
- `std::vector`, `std::deque`, `std::list` ont des coûts d'insertion au milieu et d'accès
  aléatoire très différents — c'est exactement ce que ton chrono révélera.
- La dichotomie aime l'accès aléatoire `O(1)` : `std::vector` sort souvent gagnant grâce à la
  localité mémoire.

---

## 8. Questions de défense (prépare une réponse claire)

1. Pourquoi Ford-Johnson plutôt qu'un autre tri ?
   → minimise le nombre de comparaisons, proche de `⌈log₂(n!)⌉`.
2. Pourquoi l'ordre de Jacobsthal, et pourquoi décroissant dans un groupe ?
   → garde la zone de recherche en `2ᵏ − 1`.
3. Pourquoi `bᵢ < aᵢ` permet de borner la dichotomie, et qu'est-ce que ça économise ?
4. Comment gères-tu le straggler (n impair) ?
5. Ton temps inclut-il bien le parsing ? → **oui**, exigé par le sujet.
6. Pourquoi deux conteneurs ? Lequel est le plus rapide chez toi, et pourquoi ?
7. Comment gères-tu les doublons / l'overflow `INT_MAX` ?

---

## 9. Mémo express

| Terme         | Sens                                                             |
|---------------|-----------------------------------------------------------------|
| gagnant `aᵢ`  | le plus grand d'une paire                                       |
| perdant `bᵢ`  | le plus petit d'une paire                                       |
| main chain    | chaîne triée des gagnants (où l'on insère)                      |
| pend          | perdants en attente d'insertion                                 |
| straggler     | élément seul si `n` est impair, inséré en dernier              |
| Jacobsthal    | `Jₙ = Jₙ₋₁ + 2·Jₙ₋₂` → ordre d'insertion optimal des perdants  |
