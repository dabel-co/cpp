#include "WrongCat.hpp"
#include <iostream>

// Constructors
WrongCat::WrongCat() :WrongAnimal()
{
	this->type = "WrongCat";
	std::cout << "Default Constructor called of WrongCat" << std::endl;
}

WrongCat::WrongCat(const WrongCat &copy) :WrongAnimal(copy)
{
	(void) copy;
	std::cout << "Copy Constructor called of WrongCat" << std::endl;
}


// Destructor
WrongCat::~WrongCat()
{
	std::cout << "Destructor called of WrongCat" << std::endl;
}


// Operators
WrongCat & WrongCat::operator=(const WrongCat &assign)
{
	WrongAnimal::operator=(assign);
	return *this;
}

void	WrongCat::makeSound() const
{
	std::cout << "WrongMiauuuu" << std::endl;
}