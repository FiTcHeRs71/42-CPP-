#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <exception>
# include <vector>

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
	void	addNumbers(unsigned int how_many_value);
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
};

#endif /*SPAN_HPP*/