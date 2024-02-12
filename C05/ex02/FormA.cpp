#include "FormA.hpp"
#include "Bureaucrat.hpp"
// Constructors
FormA::FormA(std::string target, const int signed_grade, const int execute_grade) : target(target), signed_grade(signed_grade), execute_grade(execute_grade)
{
	this->is_signed = false;
	std::cout << "\e[0;33mDefault Constructor called of FormA\e[0m" << std::endl;
}

FormA::FormA(const FormA &copy) : target(copy.target), signed_grade(copy.signed_grade), execute_grade(copy.execute_grade)
{
	std::cout << "\e[0;33mCopy Constructor called of FormA\e[0m" << std::endl;
} 

// Exceptions
const char * FormA::GradeTooHighException::what() const throw()
{
	return "The grade is too high";
}
const char * FormA::GradeTooLowException::what() const throw()
{
	return "The grade is too low";
}
const char * FormA::AlreadySignedException::what() const throw()
{
	return "Contract was already signed";
}
const char * FormA::NotSignedException::what() const throw()
{
	return "contract isn't signed";
}

// Destructor
FormA::~FormA()
{
	std::cout << "\e[0;31mDestructor called of FormA\e[0m" << std::endl;
}


// Operators
FormA & FormA::operator=(const FormA &assign)
{
	(void) assign;
	return *this;
}

std::string FormA::get_name() const
{
	return (this->target);
}
bool FormA::get_signed_status() const
{
	return (this->is_signed);
}
int	FormA::required_sign_grade() const
{
	return (this->signed_grade);
}
int	FormA::required_execute_grade() const
{
	return (this->execute_grade);
}

// Stream operators
std::ostream & operator<<(std::ostream &stream, const FormA &object)
{
	stream << "Form " << object.get_name()  << " signed = " << object.get_signed_status() << " required signed grade " << object.required_sign_grade() << " required execute grade " << object.required_execute_grade();
	return stream;
}

void	FormA::beSigned(Bureaucrat &x)
{
	if (this->is_signed)
	{
		std::cout << x.get_name() << " is already signed" << std::endl;
		throw AlreadySignedException();
	}
	if (this->signed_grade < x.get_grade())
	{
		std::cout << x.get_name() << " couldn't sign " << this->target << " because his grade is too low" << std::endl;
		throw GradeTooLowException();
	}
	this->is_signed = true;
	std::cout << x.get_name() << " signed " << this->target << std::endl;
}

void	FormA::execute(Bureaucrat & executor) const
{
	if (this->is_signed == false)
	{
		std::cout << this->get_name() << " is not signedddd " << std::endl;
		throw NotSignedException();
	}
	if (this->execute_grade < executor.get_grade())
	{
		std::cout << executor.get_name() << " grade isn't sufficient to execute" << std::endl;
		throw GradeTooLowException();
	}
}