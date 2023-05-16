#include <iostream>
int main ()
{
    std::string command;
    std::cout << "Welcome to the PhoneBook! Please select one of the following options" << std::endl;
    std::cout << "add : add a contact" << std::endl;
    std::cout << "search : search for a contact" << std::endl;
    std::cout << "exit : quit PhoneBook" << std::endl;
    std::cout << "Enter a command :";
    getline(std::cin, command);
    while (command != "exit")
    {
        if (command == "add")
            std::cout << " add thingy" << std::endl;
        else if (command == "search")
            std::cout << " search thingy" << std::endl;
        else if (command == "exit")
            break;
        else
            std::cout << "Invaled argument" << std::endl;
        std::cout << "Enter a command :";
        getline(std::cin, command);
    }
    std::cout << " exit thingy" << std::endl;
    return (0);
}