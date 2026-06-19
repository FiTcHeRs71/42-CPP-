#ifndef BITCOIN_EXCHANGE_HPP
# define BITCOIN_EXCHANGE_HPP

# include <exception>
# include <fstream>
# include <iostream>
# include <map>
# include <string>

# define YEAR_MAX 9999
# define YEAR_MIN 1800

class BitcoinExchange
{
	private:

	std::map<std::string, double> _database;

	protected:


	public:

	/*===Canonical Form===*/
	BitcoinExchange(void);
	~BitcoinExchange(void);
	BitcoinExchange(const BitcoinExchange& to_copy);
	BitcoinExchange&operator=(const BitcoinExchange& src);

	/*===Getters & Setters===*/
	

	/*===Member Function===*/
	void	run(void);
	void	parse(const std::string &data, const std::string &infile);

	/*===Exception===*/
	class AccessInfile : public std::exception
	{
		public:
		virtual const char *what() const throw()
		{
			return ("Invalid or cannot open <infile.txt>");
		}
	};

	class AccessData : public std::exception
	{
		public:
		virtual const char *what() const throw()
		{
			return ("Invalid or cannot open <data.csv>");
		}
	};
};

void	strtrim(std::string &line);
bool	isValidDate(const std::string &line);
bool	isValidValue(std::string &line);
bool	isValidValueInput(std::string &line);

#endif /*BITCOIN_EXCHANGE_HPP*/