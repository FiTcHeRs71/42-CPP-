#include "../include/bitcoin.hpp"
#include <algorithm>
#include <cstddef>
#include <string>

void	parse_infile(std::ifstream &infile)
{
	size_t	pos = 0;

	for (std::string line; std::getline(infile, line); )
	{
		if (line == "date | value")
			continue;
		pos = std::find()
	}
}