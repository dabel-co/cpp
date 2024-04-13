#include "Span.hpp"

// Constructors
Span::Span(unsigned int n): size(n)
{
	std::cout << "\e[0;33mDefault Constructor called of Span\e[0m" << std::endl;
}

Span::Span(const Span &copy)
{
	*this = copy;
	std::cout << "\e[0;33mCopy Constructor called of Span\e[0m" << std::endl;
}

// Destructor
Span::~Span()
{
	std::cout << "\e[0;31mDestructor called of Span\e[0m" << std::endl;
}


// Operators
Span & Span::operator=(const Span &assign)
{
	(void) assign;
	return *this;
}


// Exceptions
const char * Span::FullSpan::what() const throw()
{
	return "The Span is full";
}
const char * Span::EmptySpan::what() const throw()
{
	return "There is either zero or one items on the Span, can't perform operation";
}

// Member functions
void Span::addNumber(int n)
{
	if (v.size() >= size)
		throw FullSpan();
	else
		v.push_back(n);
}

int Span::shortestSpan()
{
	if (v.size() < 2)
		throw EmptySpan();
	int min = INT_MAX;
	for (int i = 0; i < (int)v.size(); i++)
	{
		for (int j = i + 1; j < (int)v.size(); j++)
		{
			int diff = abs(v[i] - v[j]);
			if (diff < min)
				min = diff;
		}
	}
	return min;
}

int Span::longestSpan()
{
	if (v.size() < 2)
		throw EmptySpan();
	int max = 0;
	for (int i = 0; i < (int)v.size(); i++)
	{
		for (int j = i + 1; j < (int)v.size(); j++)
		{
			int diff = abs(v[i] - v[j]);
			if (diff > max)
				max = diff;
		}
	}
	return max;
}

