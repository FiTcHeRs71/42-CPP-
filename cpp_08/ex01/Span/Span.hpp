#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <exception>
# include <vector>
# include <iterator>


class Span
{
	private:

	std::vector<int>		tab;
	const unsigned int		tab_size;

	public:

	/*===Canonical Form===*/
	Span(void);
	~Span(void);
	Span(const Span& to_copy);
	Span&operator=(const Span& src);

	Span(unsigned int N);

	/*===Getters & Setters===*/
	unsigned int getTabSize(void)const;

	/*===Member Function===*/
	void	addNumber(int to_add);
	int		shortestSpan(void)const;
	int		longestSpan(void)const; 

	class	SpanFullException : public std::exception
	{
		public:
			virtual const char *what() const throw()
			{
				return ("tab is already full.");
			}
	};

	class	NoSpanException : public std::exception
	{
		public:
			virtual const char *what() const throw()
			{
				return ("Tab is empty.");
			}
	};

		class	SpanSizeTooShort : public std::exception
	{
		public:
			virtual const char *what() const throw()
			{
				return ("Span size is too short.");
			}
	};

		template<typename It>
	void	addRange(It first, It last)
	{
		if (this->tab.size() + std::distance(first, last) > this->tab_size)
			throw SpanSizeTooShort();
		this->tab.insert(this->tab.end(), first, last);
	};
};


#endif /*SPAN_HPP*/