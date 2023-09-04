#include <iostream>
#include <string>
int main()
{
    std::string x = "HI THIS IS BRAIN";
    std::string* stringPTR = &x;
    std::string &stringREF = x;

    std::cout << "memory address of the string variable : "<< &x << std::endl;
    std::cout << "memory address held by stringPTR      : "<< &stringPTR << std::endl;
    std::cout << "memory address held by stringREF      : "<< &stringREF << std::endl;
    
    std::cout << "value of the string variable          : "<< x << std::endl;
    std::cout << "value of the stringPTR                : "<< *stringPTR << std::endl;
    std::cout << "value of the stringREF                : "<< stringREF << std::endl;
    return (0);
}