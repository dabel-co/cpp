#include "Cat.hpp"
#include <iostream>

// Constructors
Cat::Cat() :Animal()
{
	this->type = "Cat";
	this->brain = new Brain;
	std::cout << "Default Constructor called of Cat" << std::endl;
}

Cat::Cat(const Cat &copy) :Animal(copy)
{
	this->brain = new Brain(*copy.brain);
	std::cout << "\e[0;33mCopy Constructor called of Cat\e[0m" << std::endl;
}


// Destructor
Cat::~Cat()
{
	delete this->brain;
	std::cout << "Destructor called of Cat" << std::endl;
}


// Operators
Cat & Cat::operator=(const Cat &assign)
{
	Animal::operator=(assign);
	*this->brain = *assign.brain;
	return *this;
}

void	Cat::makeSound() const
{
	std::cout << "Miauuuu" << std::endl;
}
Brain*	Cat::get_brain()
{
	return (this->brain);
}