#include "Bureaucrat.hpp"
#include "FormA.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"

int main()
{
    try 
    {
        Bureaucrat pedro("Pedro de la cruz", 100);
        ShrubberyCreationForm formulario("boring_form");
        RobotomyRequestForm robotform("robotic");
        pedro.signForm(robotform);
        pedro.executeForm(robotform);
    }
    catch(std::exception & e)
    {
        std::cout << e.what() << std::endl;
    }
}