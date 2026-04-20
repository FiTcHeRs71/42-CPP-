
#include <cstddef>
#include <fstream>
#include <iostream>
#include <ostream>
#include <string>

static void	ft_error(std::string error_msg)
{
	std::cout << error_msg << std::endl;
	exit (1);
}

static std::string	copy_file(std::ifstream & infile)
{
	std::string file_content;
	std::string	temp;
	while (std::getline(infile, temp))
	{
		file_content += temp;
		file_content.push_back('\n');
	}
	return (file_content);
}

static std::string	filter(std::string search, std::string replace, std::string file_content)
{
	std::string	replace_content;
	size_t		pos = 0;
	size_t		found;

	while ((found = file_content.find(search, pos)) != std::string::npos)
	{
		replace_content += file_content.substr(pos, found - pos);
		replace_content += replace;
		pos = found + search.size();
	}
	replace_content += file_content.substr(pos); 
	return (replace_content);
}

static void	sed(std::ifstream & infile, std::ofstream & outfile, std::string search, std::string replace)
{
	std::string file_content = copy_file(infile);
	std::string replace_content;

	if (search.empty())
		ft_error("Search pattern can't be empty");
	replace_content = filter(search,replace, file_content);
	outfile << replace_content;
}

int main(int argc, char **argv)
{
	if (argc != 4)
	{
		ft_error("Error\nUsage : ./sed <filename> <search> <replace>");
		return (1);
	}
	std::ifstream infile(argv[1]);
	if (!infile.is_open())
	{
		ft_error("Error: Cannot open file");
		return (1);
	}
	std::string outname = std::string(argv[1]) + ".replace";
	std::ofstream outfile(outname.c_str());
	sed(infile, outfile, argv[2], argv[3]);
	return (0);
}
