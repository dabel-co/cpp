#include "Animal.hpp"
#include <iostream>

// Constructors
Animal::Animal()
{
	std::cout << "Default Constructor called of Animal" << std::endl;
}

Animal::Animal(const Animal &copy)
{
	*this = copy;
	std::cout << "Copy Constructor called of Animal" << std::endl;
}


// Destructor
Animal::~Animal()
{
	std::cout << "Destructor called of Animal" << std::endl;
}


// Operators
Animal & Animal::operator=(const Animal &assign)
{
	(void) assign;
	return *this;
}

void	Animal::makeSound() const
{
	std::cout << "*cute animal noises*" << std::endl;
}

std::string Animal::getType() const
{
	return (this->type);
}
