#include "PmergeMe.hpp"
#include <algorithm>
#include <climits>
#include <cstddef>
#include <cstdlib>
#include <cerrno>
#include <iostream>
#include <string>
#include <utility>
#include <vector>

/*===Canonical Form===*/
PmergeMe::PmergeMe(void)
{
	//std::cout << "PmergeMe default constructor called" << std::endl;
}
PmergeMe::~PmergeMe(void)
{
	//std::cout << "PmergeMe default destructor called" << std::endl;
}
PmergeMe::PmergeMe(const PmergeMe& to_copy)
	:_vector(to_copy._vector)
	,_deque(to_copy._deque)
{
	//std::cout << "PmergeMe copy constructor called" << std::endl;
}
PmergeMe & PmergeMe::operator=(const PmergeMe& src)
{
	//std::cout << "PmergeMe assignement operator(=) constructor called" << std::endl;
	if (this != &src)
	{
		this->_vector = src._vector;
		this->_deque = src._deque;
	}
		return (*this);
}

void	PmergeMe::solve(int argc, char **argv)
{
	for (int i = 1; i < argc; i++)
	{
		char* p_end = NULL;
		errno = 0;
		long value = std::strtol(argv[i], &p_end, 10);
		if (errno == ERANGE || *p_end != '\0' || value > INT_MAX || value < 0)
			throw InvalidArgs(std::string() + "Error : Invalid args -> " + argv[i]);
		this->_vector.push_back(value);
		this->_deque.push_back(value);
	}
	sortVector(1);
	for (size_t i = 0; i < _vector.size(); i++)
		std::cout << _vector[i] << " ";
	std::cout << std::endl;

}

void	PmergeMe::sortVector(size_t blockSize)
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
}
