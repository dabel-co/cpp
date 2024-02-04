#include "Brain.hpp"
# include <iostream>
// Constructors
Brain::Brain()
{
	std::cout << "\e[0;33mDefault Constructor called of Brain\e[0m" << std::endl;
}

Brain::Brain(const Brain &copy)
{
	for (unsigned long i = 0; i < 100; i++)
		this->ideas[i] = copy.ideas[i];
	std::cout << "\e[0;33mCopy Constructor called of Brain\e[0m" << std::endl;
}


// Destructor
Brain::~Brain()
{
	std::cout << "\e[0;31mDestructor called of Brain\e[0m" << std::endl;
}


// Operators
Brain & Brain::operator=(const Brain &assign)
{
	(void) assign;
	return *this;
}

void	Brain::set_first_idea(std::string x)
{
	this->ideas[0] = x;
}
std::string	Brain::get_first_idea()
{
	return (ideas[0]);
}

