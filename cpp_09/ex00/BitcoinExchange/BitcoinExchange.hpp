#ifndef BITCOIN_EXCHANGE_HPP
# define BITCOIN_EXCHANGE_HPP

# include <fstream>
# include <iostream>

class BitcoinExchange
{
	private:

	std::ifstream	&_infile;
	std::ifstream	&_data;

	protected:
	

	public:

	/*===Canonical Form===*/
	BitcoinExchange(void);
	~BitcoinExchange(void);
	BitcoinExchange(const BitcoinExchange& to_copy);
	BitcoinExchange&operator=(const BitcoinExchange& src);
	BitcoinExchange(std::ifstream &data, std::ifstream &infile);

	/*===Getters & Setters===*/
	

	/*===Member Function===*/
	void	run(void);
};

#endif /*BITCOIN_EXCHANGE_HPP*/