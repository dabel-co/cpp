#include "Bureaucrat.hpp"
#include "FormA.hpp"

// Constructors
Bureaucrat::Bureaucrat(std::string name, int grade) : name(name) ,grade(grade)
{
	if (grade < 1)
	{
		throw GradeTooHighException();
	}
	if (grade > 150)
	{
		throw GradeTooLowException();
	}
	std::cout << "\e[0;33mDefault Constructor called of Bureaucrat\e[0m" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &copy)
{
	(void) copy;
	std::cout << "\e[0;33mCopy Constructor called of Bureaucrat\e[0m" << std::endl;
}


// Destructor
Bureaucrat::~Bureaucrat()
{
	std::cout << "\e[0;31mDestructor called of Bureaucrat\e[0m" << std::endl;
}


// Operators
Bureaucrat & Bureaucrat::operator=(const Bureaucrat &assign)
{
	(void) assign;
	return *this;
}



// Exceptions
const char * Bureaucrat::GradeTooHighException::what() const throw()
{
	return "The grade is too high";
}
const char * Bureaucrat::GradeTooLowException::what() const throw()
{
	return "The grade is too low";
}


// Stream operators
std::ostream & operator<<(std::ostream &stream, const Bureaucrat &object)
{
	stream << object.get_name()  << " bureaucrat grade " << object.get_grade();
	return stream;
}

std::string Bureaucrat::get_name() const
{
	return (this->name);
}

int Bureaucrat::get_grade() const
{
	return (this->grade);
}

void Bureaucrat::operator+=(int i) //increment
{
	
	if ((grade - i) < 1)
	{
		throw GradeTooHighException();
	}
	if ((grade - i) > 150)
	{
		throw GradeTooLowException();
	}
	this->grade = this->grade - i;
}

void Bureaucrat::operator-=(int i) //decrement
{
	if ((grade + i) < 1)
	{
		throw GradeTooHighException();
	}
	if ((grade + i) > 150)
	{
		throw GradeTooLowException();
	}
	this->grade = this->grade + i;
}

void	Bureaucrat::signForm(FormA & x)
{
	x.beSigned(*this);
}

void	Bureaucrat::executeForm(FormA const & form)
{
	form.execute(*this);
	std::cout << this->get_name() << " execute " << form.get_name() << std::endl;
}