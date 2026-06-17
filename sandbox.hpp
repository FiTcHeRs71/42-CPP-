#ifndef SANDBOX_HPP
# define SANDBOX_HPP

#include <iostream>
# include <vector>


class bigint
{
	private:

	std::vector<int> _array

	public:

	bigint();
	~bigint();
	bigint(const bigint &to_copy);
	bigint &oprator=(const bigint &src);
	
};





#endif