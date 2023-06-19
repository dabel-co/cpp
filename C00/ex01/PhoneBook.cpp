#include <iostream>
#include "Contact.hpp"

void search_contact(Contact entry[7], int contact_count)
{
    int i;
    i = 0;
    while (contact_count > i)
    {

    }

   

   
}
Contact add_contact(void)
{
    Contact entry;
    std::string input;
    std::cout << "Set first name: ";
    getline(std::cin, input);
    entry.set_first_name(input);
    std::cout << "Set last name: ";
    getline(std::cin, input);
    entry.set_last_name(input);
    std::cout << "Set nickname: ";
    getline(std::cin, input);
    entry.set_nickname(input);
    std::cout << "Set phone number: ";
    getline(std::cin, input);
    entry.set_phone_number(input);
    std::cout << "Set darkest secret: ";
    getline(std::cin, input);
    entry.set_darkest_secret(input);
    return(entry);
}

int phonebook()
{
    std::string command;
    Contact entry[7];
    int i = 0;
    std::cout << "Welcome to the PhoneBook! Please select one of the following options" << std::endl;
    std::cout << "add : add a contact" << std::endl;
    std::cout << "search : search for a contact" << std::endl;
    std::cout << "exit : quit PhoneBook" << std::endl;
    std::cout << "Enter a command : ";
    getline(std::cin, command);
    while (command != "exit")
    {
        if (command == "add")
        {
            entry[i] = add_contact();
            i++;
        }
        else if (command == "search")
            search_contact(entry, i);
        else if (command == "exit")
            break;
        else
            std::cout << "Invaled argument" << std::endl;
        if (i == 7)
            i = 0;
        std::cout << "Enter a command :";
        getline(std::cin, command);
    }
    std::cout << "Goodbye!" << std::endl;
    return (0);
}

int main()
{
    phonebook();
}