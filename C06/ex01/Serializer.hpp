#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# include <iostream>
# include <string>
# include <stdint.h>

struct Data
{
	int value;
};

class Serializer
{
	public:
		// Constructors
		Serializer();
		Serializer(const Serializer &copy);
		
		// Destructor
		~Serializer();
		
		// Operators
		Serializer & operator=(const Serializer &assign);

		uintptr_t serialize(Data* ptr);
		Data* deserialize(uintptr_t raw);
		
	private:
		
};

#endif