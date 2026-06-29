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
/*void	PmergeMe::sortVector(size_t blockSize)
{
	// On voit _vector comme une suite de "blocs" de taille blockSize.
	// La récursion remonte : blockSize = 1, puis 2, 4, 8...
	size_t nbBlocks = this->_vector.size() / blockSize;

	// Cas de base : moins de 2 blocs => rien à apparier ni à fusionner.
	if (nbBlocks < 2)
		return;

	// --- ÉTAPE 1 : appariement des blocs deux par deux ---
	// On compare le dernier élément (la "queue") de chaque bloc de la paire.
	// Si le bloc de gauche a la plus grande queue, on échange les deux blocs
	// entiers : ainsi, dans chaque paire, le bloc de droite est le "gagnant"
	// (plus grande queue) et celui de gauche le "perdant".
	for (size_t b = 0; b + 1 < nbBlocks; b += 2)
	{
		long last_a = this->_vector[b*blockSize + blockSize - 1];
		long last_b = this->_vector[(b+1)*blockSize + blockSize - 1];
		if (last_a > last_b)
			for (size_t k = 0; k < blockSize; k++)
				std::swap(this->_vector[b * blockSize + k], this->_vector[(b+1)*blockSize + k]);
	}

	// --- ÉTAPE 2 : récursion ---
	// On trie les gagnants entre eux en travaillant sur des blocs deux fois
	// plus grands. Au retour, les paires de blocs sont ordonnées par leur
	// queue (= la queue du gagnant). L'ordre interne perdant/gagnant de chaque
	// paire est préservé (les swaps déplacent des paires entières).
	sortVector(blockSize * 2);

	// --- ÉTAPE 3 : séparation en mainchain (gagnants) et pend (perdants) ---
	// Après la récursion, à chaque paire correspondent deux positions :
	// indice pair = perdant, indice impair = gagnant. On stocke les positions
	// de départ de chaque bloc. pend[f] et mainchain[f] sont partenaires.
	std::vector<size_t>	mainchain;
	std::vector<size_t>	pend;
	for (size_t p = 0; p < nbBlocks; p++)
	{
		size_t	start = p * blockSize;
		if (p % 2 == 0)
			pend.push_back(start);
		else
			mainchain.push_back(start);
	}

	// --- ÉTAPE 4 : chaîne de départ ---
	// result = [pend[0], mainchain[0], mainchain[1], ...] = [a1, b1, b2, ...].
	// On sait que a1 < b1, donc on peut placer a1 en tête sans le comparer.
	std::vector<size_t>	result;
	result.push_back(pend[0]);
	for (size_t i = 0; i < mainchain.size(); i++)
		result.push_back(mainchain[i]);

	// --- ÉTAPE 5 : ordre d'insertion de Jacobsthal ---
	// On insère les perdants restants par paquets bornés par les nombres de
	// Jacobsthal (3, 5, 11, 21... avec next = jac + 2*prev), en ordre
	// DÉCROISSANT dans chaque paquet. But : chaque recherche binaire tombe sur
	// un intervalle de taille 2^k - 1, ce qui minimise le nombre de comparaisons.
	// order contient les indices f (dans pend) dans l'ordre d'insertion voulu.
	std::vector<size_t>	order;
	size_t	prev = 1;          // a1 (= pend[0]) est déjà placé
	size_t	jac = 3;           // premier Jacobsthal utile
	while (prev < pend.size())
	{
		size_t hi = (jac < pend.size()) ? jac : pend.size();  // plafonné à pend.size()
		for (size_t i = hi; i > prev; i--)
			order.push_back(i - 1);                           // f = i - 1
		size_t	next = jac + 2 * prev;
		prev = jac;
		jac = next;
	}

	// --- ÉTAPE 6 : insertion par recherche binaire ---
	for(size_t o = 0; o < order.size(); o++)
	{
		size_t f = order[o];
		size_t low = 0;
		size_t high;

		// Bornage : pend[f] a pour partenaire mainchain[f], déjà placé, et on
		// sait que pend[f] < mainchain[f]. Inutile de chercher au-delà : on
		// limite high à la position du partenaire dans result.
		// (Cette recherche compare des indices de blocs, pas des valeurs :
		//  elle ne compte donc pas dans le budget de comparaisons.)
		if (f < mainchain.size())
		{
			high = 0;
			while (result[high] != mainchain[f])
				high ++;
		}
		else
			high = result.size();  // bloc isolé (nbBlocks impair) : pas de partenaire

		// Recherche binaire de la position d'insertion, en comparant les queues.
		long value = this->_vector[pend[f] + blockSize - 1];
		while (low < high)
		{
			size_t medium = (low + high) / 2;
			if (this->_vector[result[medium] + blockSize - 1] < value)
				low = medium + 1;
			else
				high = medium;
		}
		result.insert(result.begin() + low, pend[f]);
	}

	// --- ÉTAPE 7 : reconstruction de _vector dans le nouvel ordre ---
	// result donne l'ordre des blocs ; on recopie chaque bloc en entier.
	std::vector<long>	sorted;
	for (size_t i = 0; i < result.size(); i++)
	{
		for (size_t k = 0; k < blockSize; k++)
			sorted.push_back(this->_vector[result[i] + k]);
	}
	// Les éléments en trop (qui ne forment pas un bloc complet à ce niveau)
	// sont recopiés tels quels : ils seront réordonnés aux niveaux inférieurs.
	for (size_t i = nbBlocks * blockSize; i < this->_vector.size(); i++)
		sorted.push_back(this->_vector[i]);
	this->_vector = sorted;
	for (size_t i = 0; i < _vector.size(); i++)
		std::cout << _vector[i] << " ";
	std::cout << std::endl;
}*/