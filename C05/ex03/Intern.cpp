#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
// Constructors
Intern::Intern()
{
	std::cout << "\e[0;33mDefault Constructor called of Intern\e[0m" << std::endl;
}

Intern::Intern(const Intern &copy)
{
	(void) copy;
	std::cout << "\e[0;33mCopy Constructor called of Intern\e[0m" << std::endl;
}


// Destructor
Intern::~Intern()
{
	std::cout << "\e[0;31mDestructor called of Intern\e[0m" << std::endl;
}


// Operators
Intern & Intern::operator=(const Intern &assign)
{
	(void) assign;
	return *this;
}


FormA* Intern::makeForm(std::string name, std::string target)
{
	const std::string form_type[] ={"robotomy request", "shrubbery request", "presidential request", ""};
	FormA* (*function_type[]) (std::string) = {RobotomyRequestForm::createInstance, ShrubberyCreationForm::createInstance, PresidentialPardonForm::createInstance};
	
	for (int i = 0; form_type[i].size(); i++)
	{
		if (name == form_type[i])
			return((function_type[i])(target));
	}
	return (NULL);
}

