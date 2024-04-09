#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>

template<typename X>
class Array
{
	public:
		Array() : content(NULL), len(0)
		{
			std::cout << "Default empty Array constructor called" << std::endl;
		}
		Array(unsigned int n) : len(n)
		{
			content = new X[n];
			for (size_t i = 0; i < n; i++)
				content[i] = 0;
			std::cout << "Default Array constructor called" << std::endl;
		}
		Array(const Array &copy)
		{
			len = copy.len;
			content = new X[len];
			for (size_t i = 0; i < len; i++)
				content[i] = copy.content[i];
			std::cout << "Copy Array constructor called" << std::endl;
		}
		const Array  &  operator=(const Array &copy)
		{
			if (this == &copy)
				return *this;
			if (content)
				delete[] content;
			len = copy.len;
			content = new X[len];
			for (size_t i = 0; i < len; i++)
				content[i] = copy.content[i];
			std::cout << "Assignation Array constructor called" << std::endl;
			return *this;
		}
		
		X  &  operator[](unsigned int index)
		{	
			if (index >= len)
				throw std::out_of_range("Out of range");
			return content[index];
		}
		X  &  operator[](unsigned int index) const 
		{	
			if (index >= len)
				throw std::out_of_range("Out of range");
			return content[index];
		}
		unsigned int  size() const
		{
			return len;
		}
		~Array()
		{
			if (len)
				delete [] this->content;
			std::cout << "Default Array destructor called" << std::endl;
		}	
		
		
	private:
		X*		content;
		size_t	len;
		
};

#endif