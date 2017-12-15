#include "parser.h"



parser::parser()
{
}


parser::~parser()
{
}

std::string parser::parse_str(std::string data)
{
	std::string temp = "";
	if (data.find('"') != std::string::npos)
	{
		data.erase(0, data.find('"') + 1);
	}
	else if (data.find('<') != std::string::npos)
	{
		data.erase(0, data.find('<') + 1);
	}
	data.erase(data.length() - 1, data.length());

	return data;
}