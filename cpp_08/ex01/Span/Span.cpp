#include "./Span.hpp"
#include <algorithm>
#include <climits>
#include <cstddef>
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
	:tab_size(to_copy.tab_size)
{
	std::cout << "Span copy constructor called" << std::endl;
	for (size_t i = 0; i < to_copy.tab.size(); i++)
	{
		this->tab.push_back(to_copy.tab[i]);
	}
}

Span & Span::operator=(const Span& src)
{
	std::cout << "Span operator assignement(=) called" << std::endl;
	if (this != &src)
	{
		for (size_t i = 0; i < src.tab.size(); i++)
		{
			this->tab.push_back(src.tab[i]);
		}
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
	int					result;


	for(size_t i = 0; i < this->tab.size(); i++)
	{
		copytab.push_back(this->tab[i]);
	}
	std::sort(copytab.begin(), copytab.end());
		for (size_t i = 0; i < copytab.size(); i++)
	{
		std::cout << "apres sort : " << copytab[i] << std::endl;
	}
	std::adjacent_difference(copytab.begin(), copytab.end(), copytab.begin());
	for (size_t i = 0; i < copytab.size(); i++)
	{
		std::cout << "apres adjacent diference : " << copytab[i] << std::endl;
	}
	result = *std::min_element(copytab.begin(), copytab.end());
	std::cout << "result : " << result << std::endl;
	return (result);
}