#include "ScalarConverter.hpp"
#include <limits>
#include <sstream>
#include <float.h>
// Constructors

void ScalarConverter::convert(const std::string & x)
{
	bool isanumber = true;
	if (x == "nan")
		isanumber = false;

	{	//char
		std::stringstream ss;
		ss << x;
		int aux = 0;
		ss >> aux;
		if (!isanumber || (aux < -128) || (aux > 127))
			std::cout << "char: impossible" << std::endl;
		else if ((aux < ' ') || (aux > '~'))
			std::cout << "char: Non displayable" << std::endl;
		else			
			std::cout << "char: " << (char)aux << std::endl;
	}
	{	//int
		std::stringstream ss;
		ss << x;
		long aux = 0;
		ss >> aux;
		if (!isanumber)
			std::cout << "int: impossible" << std::endl;
		else if ((aux < INT_MIN) || (aux > INT_MAX))
			std::cout << "int: impossible" << std::endl;
		else
			std::cout << "int: " << (int)aux << std::endl;
	}
	{	//float
		std::stringstream ss;
		ss << x;
		double aux = 0;
		ss >> aux;
		std::cout << "float: " << (float)aux << "f" << std::endl;
	}
	{	//double
		std::stringstream ss;
		ss << x;
		double aux = 0;
		ss >> aux;
		std::cout << "double: " << aux << std::endl;
	}
}