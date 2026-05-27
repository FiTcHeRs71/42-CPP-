#ifndef SCALAR_CONVERTE_HPP
# define SCALAR_CONVERTE_HPP

#include <cstddef>
#include <string>
#include <iostream>

enum    e_type
{
	SPECIAL,
	CHAR,
	INT,
	FLOAT,
	DOUBLE,
	INVALID,
};

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

e_type  whichType(const std::string& str, size_t& len);
void	convertChar(std::string &str, size_t &len);

#endif /*SCALAR_CONVERTE_HPP*/