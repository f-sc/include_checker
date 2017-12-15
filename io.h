#pragma once
#include <ostream>
#include <fstream>
#include <vector>
#include <string>
#include <iostream>

#include "parser.h"

class io
{
	parser* parse;
public:
	std::vector<std::string> load_file(std::string path);
	io();
	~io();
};

