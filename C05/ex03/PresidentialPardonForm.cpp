#include "PresidentialPardonForm.hpp"

// Constructors
PresidentialPardonForm::PresidentialPardonForm(std::string target): FormA(target, 25, 5)
{
	std::cout << "\e[0;33mDefault Constructor called of PresidentialPardonForm\e[0m" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &copy): FormA(copy)
{
	(void) copy;

	std::cout << "\e[0;33mCopy Constructor called of PresidentialPardonForm\e[0m" << std::endl;
}


// Destructor
PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "\e[0;31mDestructor called of PresidentialPardonForm\e[0m" << std::endl;
}


// Operators
PresidentialPardonForm & PresidentialPardonForm::operator=(const PresidentialPardonForm &assign)
{
	(void) assign;
	return *this;
}

void	PresidentialPardonForm::execute(Bureaucrat & executor) const
{
	FormA::execute(executor);
	std::cout << this->get_name() << " has been pardoned by Zafod Beeblebrox" << std::endl;
}

FormA* PresidentialPardonForm::createInstance(std::string target)
{
	return (new PresidentialPardonForm(target));
}