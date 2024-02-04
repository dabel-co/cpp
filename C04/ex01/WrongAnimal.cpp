#include "WrongAnimal.hpp"
#include <iostream>

// Constructors
WrongAnimal::WrongAnimal()
{
	std::cout << "Default Constructor called of WrongAnimal" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &copy)
{
	(void) copy;
	std::cout << "Copy Constructor called of WrongAnimal" << std::endl;
}


// Destructor
WrongAnimal::~WrongAnimal()
{
	std::cout << "Destructor called of WrongAnimal" << std::endl;
}


// Operators
WrongAnimal & WrongAnimal::operator=(const WrongAnimal &assign)
{
	(void) assign;
	return *this;
}

void	WrongAnimal::makeSound() const
{
	std::cout << "*wrong animal noises*" << std::endl;
}

std::string WrongAnimal::getType() const
{
	return (this->type);
}
