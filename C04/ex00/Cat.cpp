#include "Cat.hpp"
#include <iostream>

// Constructors
Cat::Cat() :Animal()
{
	this->type = "Cat";
	std::cout << "Default Constructor called of Cat" << std::endl;
}

Cat::Cat(const Cat &copy) :Animal(copy)
{
	(void) copy;
	std::cout << "\e[0;33mCopy Constructor called of Cat\e[0m" << std::endl;
}


// Destructor
Cat::~Cat()
{
	std::cout << "Destructor called of Cat" << std::endl;
}


// Operators
Cat & Cat::operator=(const Cat &assign)
{
	Animal::operator=(assign);
	return *this;
}

void	Cat::makeSound() const
{
	std::cout << "Miauuuu" << std::endl;
}