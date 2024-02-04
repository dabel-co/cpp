#include "Form.hpp"
#include "Bureaucrat.hpp"
// Constructors
Form::Form(std::string name, const int signed_grade, const int execute_grade) : name(name), signed_grade(signed_grade), execute_grade(execute_grade)
{
	this->is_signed = false;
	std::cout << "\e[0;33mDefault Constructor called of Form\e[0m" << std::endl;
}

Form::Form(const Form &copy) : name(copy.name), signed_grade(copy.signed_grade), execute_grade(copy.execute_grade)
{
	std::cout << "\e[0;33mCopy Constructor called of Form\e[0m" << std::endl;
} 


// Destructor
Form::~Form()
{
	std::cout << "\e[0;31mDestructor called of Form\e[0m" << std::endl;
}


// Operators
Form & Form::operator=(const Form &assign)
{
	(void) assign;
	return *this;
}

// Exceptions
const char * Form::GradeTooHighException::what() const throw()
{
	return "The grade is too high";
}
const char * Form::GradeTooLowException::what() const throw()
{
	return "The grade is too low";
}

std::string Form::get_name() const
{
	return (this->name);
}
bool Form::get_signed_status() const
{
	return (this->is_signed);
}
int	Form::required_sign_grade() const
{
	return (this->signed_grade);
}
int	Form::required_execute_grade() const
{
	return (this->execute_grade);
}

// Stream operators
std::ostream & operator<<(std::ostream &stream, const Form &object)
{
	stream << "Form " << object.get_name()  << " signed = " << object.get_signed_status() << " required signed grade " << object.required_sign_grade() << " required execute grade " << object.required_execute_grade();
	return stream;
}

void	Form::beSigned(Bureaucrat &x)
{
	if (this->signed_grade < x.get_grade())
	{
		std::cout << x.get_name() << " couldn't sign " << this->name << " because his grade is too low" << std::endl;
		throw GradeTooLowException();
	}
	this->is_signed = true;
	std::cout << x.get_name() << " signed " << this->name << std::endl;
}