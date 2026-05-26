#ifndef SCALAR_CONVERTE_HPP
# define SCALAR_CONVERTE_HPP

#include <string>
#include <iostream>

class ScalarConverte
{
	public:

	/*===Canonical Form===*/
	ScalarConverte(void);
	~ScalarConverte(void);
	ScalarConverte(const ScalarConverte& to_copy);
	ScalarConverte&operator=(const ScalarConverte& src);


	/*===Getters & Setters===*/


	/*===Member Function===*/
	static void	convert(const std::string str);
};

#endif/*SCALAR_CONVERTE_HPP*/