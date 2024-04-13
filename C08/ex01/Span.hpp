#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <string>
# include <vector>
class Span
{
	public:
		// Constructors
		Span(unsigned int n);
		Span(const Span &copy);
		
		// Destructor
		~Span();
		
		// Operators
		Span & operator=(const Span &assign);
		
		// Exceptions
		class FullSpan : public std::exception {
			virtual const char* what() const throw();
		};
		class EmptySpan : public std::exception {
			virtual const char* what() const throw();
		};
		
		// Member functions
		void addNumber(int n);
		int shortestSpan();
		int longestSpan();
		
		template <typename InputIterator>
		void addNumbers(InputIterator begin, InputIterator end)
		{
			if (v.size() + std::distance(begin, end) > size)
				throw FullSpan();
			v.insert(v.end(), begin, end);
		}
	private:
		unsigned int size;
		std::vector<int> v;
		
};

#endif