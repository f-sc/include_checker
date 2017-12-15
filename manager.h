#pragma once
#include <string>
#include <vector>
#include <iostream>
#include <Windows.h>

#include "io.h"

struct object
{
	std::string name;
	std::vector<std::string> children;
	object(std::string name, std::vector<std::string> children) :name(name), children(children) {}
};

struct error
{
	std::string fname;
	std::string err_include;
	error(std::string fname, std::string err_include) :fname(fname), err_include(err_include) {}
};

class manager
{
	object* pobject;
	std::vector<object*> cobject;
	std::vector<error*> errors;
public:
	object* load_file(std::string startup_file);
	void set_pobject(std::string name, std::vector<std::string> children);
	std::vector<object*> load_childen(object* tcpcobj);
	void set_pobject(object* tobject);
	void add_cobject(object* tobject);
	void add_cobject(std::vector<object*> cobject);
	void add_cobject(std::string name, std::vector<std::string> children);
	void clear_objects();
	bool check(std::string path);
	void print_report();
	manager();
	~manager();
};

