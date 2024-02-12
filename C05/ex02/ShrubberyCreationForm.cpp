#include "ShrubberyCreationForm.hpp"
#include <fstream>
// Constructors
ShrubberyCreationForm::ShrubberyCreationForm(std::string target): FormA(target, 145, 137)
{
	
	std::cout << "\e[0;33mDefault Constructor called of ShrubberyCreationForm\e[0m" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &copy): FormA(copy)
{
	(void) copy;

	std::cout << "\e[0;33mCopy Constructor called of ShrubberyCreationForm\e[0m" << std::endl;
}


// Destructor
ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "\e[0;31mDestructor called of ShrubberyCreationForm\e[0m" << std::endl;
}


// Operators
ShrubberyCreationForm & ShrubberyCreationForm::operator=(const ShrubberyCreationForm &assign)
{
	(void) assign;
	return *this;
}

void	ShrubberyCreationForm::execute(Bureaucrat & executor) const
{
	FormA::execute(executor);
	std::string filename = this->get_name() + "_shurubbery";
	std::fstream stream(filename, std::fstream::out);
	stream << TREE;
}