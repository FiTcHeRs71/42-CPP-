#ifndef SCALAR_CONVERTE_HPP
# define SCALAR_CONVERTE_HPP

# include <cstddef>
# include <string>
# include <iostream>

# define FLOAT_MIN std::numeric_limits<float>::min()
# define FLOAT_MAX std::numeric_limits<float>::max()
# define DOUBLE_MIN std::numeric_limits<double>::min()
# define DOUBLE_MAX std::numeric_limits<double>::max()

enum	e_type
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

e_type	whichType(const std::string& str, size_t& len);
void	convertChar(const std::string& str, size_t& len);
void	convertInt(const std::string& str);
void	convertFloat(const std::string& str);
void	convertDouble(const std::string& str);
void	printSpecial(const std::string& str);

#endif /*SCALAR_CONVERTE_HPP*/