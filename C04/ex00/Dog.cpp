#include "Dog.hpp"
#include <iostream>

// Constructors
Dog::Dog() :Animal()
{
	this->type = "Dog";
	std::cout << "Default Constructor called of Dog" << std::endl;
}

Dog::Dog(const Dog &copy) :Animal(copy)
{
	std::cout << "\e[0;33mCopy Constructor called of Dog\e[0m" << std::endl;
}


// Destructor
Dog::~Dog()
{
	std::cout << "Destructor called of Dog" << std::endl;
}


// Operators
Dog & Dog::operator=(const Dog &assign)
{
	Animal::operator=(assign);
	return *this;
}

void	Dog::makeSound() const
{
	std::cout << "Woof" << std::endl;
}
