#include "Bureaucrat.hpp"
#include "FormA.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
    try 
    {
        Bureaucrat pedro("Pedro de la cruz", 1);
        ShrubberyCreationForm formulario1("boring_form");
        RobotomyRequestForm formulario2("whatever");
        PresidentialPardonForm formulario3("Ramon");
        pedro.signForm(formulario1);
        pedro.signForm(formulario2);
        pedro.signForm(formulario3);
        pedro.executeForm(formulario1);
        pedro.executeForm(formulario2);
        pedro.executeForm(formulario3);
        //add all test
    }
    catch(std::exception & e)
    {
        std::cout << e.what() << std::endl;
    }
}