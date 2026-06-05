#include "./Span.hpp"
#include <algorithm>
#include <climits>
#include <cstddef>
#include <ctime>
#include <iterator>
#include <numeric>
#include <vector>

/*===Canonical Form===*/
Span::Span(void)
	:tab_size(0)
{
	std::cout << "Span default constructor called" << std::endl;
}

Span::~Span(void)
{
	std::cout << "Span default destructor called" << std::endl;
}

Span::Span(const Span& to_copy)
	:tab(to_copy.tab)
	,tab_size(to_copy.tab_size)
{
	std::cout << "Span copy constructor called" << std::endl;
}

Span & Span::operator=(const Span& src)
{
	std::cout << "Span operator assignement(=) called" << std::endl;
	if (this != &src)
	{
		this->tab = src.tab;
	}
	return (*this);
}

Span::Span(unsigned int N)
	:tab_size(N)
{
	std::cout << "Span full constructor called" << std::endl;
}

/*===Getters & Setters===*/
unsigned int Span::getTabSize(void)const
{
	return (this->tab_size);
}

/*===Member Function===*/
void	Span::addNumber(int to_add)
{
	if (this->tab.size() < this->tab_size)
	{
		this->tab.push_back(to_add);
	}
	else
		throw SpanFullException();
}

template <typename It>
void	Span::addRange(It first, It last)
{
	if (this->tab.size() + std::distance(first, last) > this->tab_size)
		throw SpanSizeTooShort();
	this->tab.insert(this->tab.end(), first, last);
}

int		Span::longestSpan(void)const
{
	int	result;

	if (this->tab.size() <= 1)
		throw NoSpanException();
	result = *std::max_element(tab.begin(), tab.end()) - *std::min_element(tab.begin(), tab.end());

	return (result);
}
int		Span::shortestSpan(void)const
{
	std::vector<int>	copytab;

	if (this->tab.size() <= 1)
		throw NoSpanException();
	copytab = this->tab;
	std::sort(copytab.begin(), copytab.end());
	std::adjacent_difference(copytab.begin(), copytab.end(), copytab.begin());
	return (*std::min_element(copytab.begin() + 1, copytab.end()));
}