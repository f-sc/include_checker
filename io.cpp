
#include "io.h"




io::io()
{
	parse = new parser;
}


io::~io()
{
	delete parse;
}


std::vector<std::string> io::load_file(std::string path)
{
	std::string temp;
	std::ifstream input(path);
	std::vector < std::string> children;
	if (input.is_open())
	{
		while (std::getline(input, temp))
		{
			try
			{
				//std::cout << temp;
				if (!temp.find("#include"))
				{
					//std::cout << parse->parse_str(temp) << std::endl;
					children.push_back(parse->parse_str(temp));
				}
			}
			catch (const std::exception&)
			{

			}
		}
	}
	return children;
}
