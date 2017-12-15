#include <iostream>
#include "parser.h"
#include "manager.h"
#include "io.h"

int main()
{
	manager* man = new manager;
	std::string temp_fn;
	std::cout << "Please enter a path to file with filename(example C:/1.txt): ";
	std::getline(std::cin, temp_fn);
	object *tt = man->load_file(temp_fn);
	man->set_pobject(tt);
	man->add_cobject(man->load_childen(tt));
	std::cout << "Please enter a path to save log(example C:/log.txt): ";
	std::getline(std::cin, temp_fn);
	man->check(temp_fn);
	man->clear_objects();
	man->print_report();
	delete man;
	std::cin.get();
	return 0;
}