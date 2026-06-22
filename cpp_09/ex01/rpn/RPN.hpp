#ifndef RNP_HPP
# define RNP_HPP

#include <exception>
#include <iostream>
#include <stack>

class RPN
{
	private:

	std::stack<double>	_list;

	protected:
	

	public:

	/*===Canonical Form===*/
	RPN(void);
	~RPN(void);
	RPN(const RPN& to_copy);
	RPN&operator=(const RPN& src);

	/*===Getters & Setters===*/
	

	/*===Member Function===*/
	void	run(std::string args);
	double	popVal(void);

	/*===Exception===*/
	class	InvalidToken : public std::exception
	{
		public:
		virtual const char *what() const throw()
		{
			return ("Invalid Token");
		}
	};
	class	DivisionByZero : public std::exception
	{
		public:
		virtual const char *what() const throw()
		{
			return ("Division by zero");
		}
	};
	class	InvalidStackSize : public std::exception
	{
		public:
		virtual const char *what() const throw()
		{
			return ("Invalid size");
		}
	};
	class	InvalidExpression : public std::exception
	{
		public:
		virtual const char *what() const throw()
		{
			return ("Invalid expression");
		}
	};
};

#endif /*RNP_HPP*/