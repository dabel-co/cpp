#include "Serializer.hpp"

// Constructors
Serializer::Serializer()
{
	std::cout << "\e[0;33mDefault Constructor called of Serializer\e[0m" << std::endl;
}

Serializer::Serializer(const Serializer &copy)
{
	(void) copy;
	std::cout << "\e[0;33mCopy Constructor called of Serializer\e[0m" << std::endl;
}


// Destructor
Serializer::~Serializer()
{
	std::cout << "\e[0;31mDestructor called of Serializer\e[0m" << std::endl;
}


// Operators
Serializer & Serializer::operator=(const Serializer &assign)
{
	(void) assign;
	return *this;
}
//uintptr_t : an unsigned integer type with the property that any valid pointer to void can be converted to this type
//then converted back to pointer to void, and the result will compare equal to the original pointer
uintptr_t Serializer::serialize(Data* ptr)
{
	return (uintptr_t)ptr;
}

Data* Serializer::deserialize(uintptr_t raw)
{
	return (Data *) raw;
}
