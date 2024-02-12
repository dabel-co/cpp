#ifndef FORMA_HPP
# define FORMA_HPP

# include <iostream>
# include <string>
class Bureaucrat;
class FormA
{
	public:
		// Constructors
		FormA(std::string target, const int signed_grade, const int execute_grande);
		FormA(const FormA &copy);
		
		// Destructor
		virtual ~FormA();
		
		// Operators
		FormA & operator=(const FormA &assign);

		// Exceptions
		class GradeTooHighException : public std::exception {
			public : 
				virtual const char* what() const throw();
		};
		class GradeTooLowException : public std::exception {
			public :
				virtual const char* what() const throw();
		};
		class AlreadySignedException : public std::exception {
			public :
				virtual const char* what() const throw();
		};
		class NotSignedException : public std::exception {
			public :
				virtual const char* what() const throw();
		};

		std::string get_name() const;
		bool get_signed_status() const;
		int	required_sign_grade() const;
		int	required_execute_grade() const;
		void	beSigned(Bureaucrat &x);
		virtual void	execute(Bureaucrat & executor) const;
		
	private:
		const std::string target;
		bool	is_signed;
		const int signed_grade;
		const int execute_grade;
		
};
std::ostream & operator<<(std::ostream &stream, const FormA &object);
#endif