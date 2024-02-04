#include "Dog.hpp"
#include <iostream>

// Constructors
Dog::Dog() :Animal()
{
	this->type = "Dog";
	this->brain = new Brain;
	std::cout << "Default Constructor called of Dog" << std::endl;
}

Dog::Dog(const Dog &copy) :Animal(copy)
{
	this->brain = new Brain(*copy.brain);
	std::cout << "\e[0;33mCopy Constructor called of Dog\e[0m" << std::endl;
}


// Destructor
Dog::~Dog()
{
	delete this->brain;
	std::cout << "Destructor called of Dog" << std::endl;
}


// Operators
Dog & Dog::operator=(const Dog &assign)
{
	Animal::operator=(assign);
	*this->brain = *assign.brain;
	return *this;
}

void	Dog::makeSound() const
{
	std::cout << "Woof" << std::endl;
}

Brain*	Dog::get_brain()
{
	return (this->brain);
}