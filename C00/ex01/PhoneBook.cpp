#include <iostream>
#include "Contact.hpp"

void add_contact(Contact entry)
{
    entry.add();
    std::string test;
    test = entry.get_last_name();
    std::cout << "last name = " << test << std::endl;

}
int main ()
{
    std::string command;
    Contact entry[8];
    std::cout << "Welcome to the PhoneBook! Please select one of the following options" << std::endl;
    std::cout << "add : add a contact" << std::endl;
    std::cout << "search : search for a contact" << std::endl;
    std::cout << "exit : quit PhoneBook" << std::endl;
    std::cout << "Enter a command : ";
    getline(std::cin, command);
    while (command != "exit")
    {
        if (command == "add")
            add_contact(entry[0]);
        else if (command == "search")
            std::cout << "ADD SEARCH" << std::endl;
        else if (command == "exit")
            break;
        else
            std::cout << "Invaled argument" << std::endl;
        std::cout << "Enter a command :";
        getline(std::cin, command);
    }
    std::cout << "Goodbye!" << std::endl;
    return (0);
}