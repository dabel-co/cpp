#include "RobotomyRequestForm.hpp"

// Constructors
RobotomyRequestForm::RobotomyRequestForm(std::string target): FormA(target, 72, 45)
{
	std::cout << "\e[0;33mDefault Constructor called of RobotomyRequestForm\e[0m" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &copy): FormA(copy)
{
	(void) copy;

	std::cout << "\e[0;33mCopy Constructor called of RobotomyRequestForm\e[0m" << std::endl;
}


// Destructor
RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "\e[0;31mDestructor called of RobotomyRequestForm\e[0m" << std::endl;
}


// Operators
RobotomyRequestForm & RobotomyRequestForm::operator=(const RobotomyRequestForm &assign)
{
	(void) assign;
	return *this;
}

void	RobotomyRequestForm::execute(Bureaucrat & executor) const
{
	FormA::execute(executor);
	std::cout << "Brrrrrrrrrr" << std::endl;
	srand(time(0)); 
	int v1 = rand() % 101;
	if (v1 % 2 == 0)
		std::cout << this->get_name() << " has been robotomized" << std::endl;
	else
		std::cout << this->get_name() << " hasn't been robotomized..." << std::endl;
}

FormA* RobotomyRequestForm::createInstance(std::string target)
{
	return (new RobotomyRequestForm(target));
}
