#include "RPN.hpp"
#include <iostream>
int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cout << "invalid input" << std::endl;
        return (1);
    }
    try {
    int result = rpn(argv[1]);
    std::cout << "Result = " << result << std::endl;
    }
    catch(std::exception &e) {
        std::cout << e.what() << std::endl;
        return (1);
    }
    return (0);
    
}