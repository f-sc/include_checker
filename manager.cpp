#include "manager.h"



manager::manager()
{
}


manager::~manager()
{
}


void manager::set_pobject(std::string name, std::vector<std::string> children)
{
	pobject = new object(name, children);
}

void manager::set_pobject(object* tobject)
{
	pobject = tobject;
}

void manager::add_cobject(object* tobject)
{
	cobject.push_back(tobject);
}

void manager::add_cobject(std::string name, std::vector<std::string> children)
{
	object* tobject = new object(name, children);
	cobject.push_back(tobject);

}

void manager::clear_objects()
{
	delete pobject;
	cobject.clear();
}

bool manager::check(std::string path)
{
	std::string temp_str = pobject->children[0];
	std::ofstream log(path);
	int counter = 0;
	for (auto tpobst : pobject->children)//UPDATE
	{
		if (tpobst == temp_str)
		{
			counter++;
		}

		if (counter > 1)
		{
			temp_str = tpobst;
			error* err = new error("Current file -", tpobst);
			counter = 1;
			errors.push_back(err);
		}
	}

	for (auto tpobs : pobject->children)
	{

		for (auto tcobsit : cobject)
		{
			for (auto tcobs : tcobsit->children)
			{
				if (tpobs == tcobs)
				{
					error* err = new error(tcobsit->name, tpobs);
					errors.push_back(err);

					//std::cout << "Error in " << tcobsit->name << " : " <<  tpobs << " - recursive include file loading" << std::endl;
				}
				else
				{
						log << "Dependency check in:" << tcobsit->name << "..." << tpobs << "---OK" << "\n";
				}
			}
		}
	}
	return false;
}

object* manager::load_file(std::string startup_file)
{
	io* main_io = new io;
	object* tpcobj = new object(startup_file, main_io->load_file(startup_file));
	return tpcobj;
}

std::vector<object*> manager::load_childen(object* tcpcobj)
{
	std::vector<object*> tobjv;
	for (auto temp : tcpcobj->children)
	{
		tobjv.push_back(load_file(temp));
	}
	return tobjv;
}

void manager::add_cobject(std::vector<object*> cobject)
{
	this->cobject = cobject;
}


void manager::print_report()
{
	for (auto temp : errors)
	{
		std::cout << "Error in " << temp->fname << " : " << temp->err_include << " - recursive include file loading" << std::endl;
	}
}