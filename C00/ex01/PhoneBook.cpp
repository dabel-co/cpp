#include <iostream>
#include "Contact.hpp"

std::string format_text(std::string input)
{
int i;
int len;
int aux = 0;
std::string result;
result.resize(10);
i = 0;
while(input[len])
    len++;
if (len > 10)
{
    while (i < 10)
    {
        result[i] = input[i];
        i++;
    }
    result[9] = '.';
}
else
{
    aux = 10 - len;
    while (i < aux)
    {
        result[i] = ' ';
        i++;
    }
    aux = 0;
    while (i < 10)
    {
    result[i] = input[aux];
    aux++;
    i++;
    }
}
return (result);

}

void search_contact(Contact entry[8], int contact_count)
{
    int i;
    i = 0;
    std::string aux;
    std::cout << "     index|first_name|  lastname|  nickname|" << std::endl;
    while (contact_count > i)
    {
        std::cout << "         " << i << "|";
        aux = entry[i].get_first_name();
        std::cout << format_text(aux) << "|";
        aux = entry[i].get_last_name();
        std::cout << format_text(aux) << "|";
         aux = entry[i].get_nickname();
        std::cout << format_text(aux) << "|" << std::endl;
        i++;
    }
    std::cout << "Select a contact : ";
    getline(std::cin, aux);
    i = atoi(aux.c_str());
    entry[i].print_contact();

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

int main()
{
    std::string command;
   
    int i = 0;
    PhoneBook book;
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
            book.entry[0] = add_contact();
            i++;
        }
        else if (command == "search")
            search_contact(book.entry, i);
        else if (command == "exit")
            break;
        else
            std::cout << "Invaled argument" << std::endl;
        if (i == 8)
            i = 0;
        std::cout << "Enter a command :";
        getline(std::cin, command);
    }
    std::cout << "Goodbye!" << std::endl;
    return (0);
}