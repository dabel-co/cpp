#include "Contact.hpp"

void    Contact::print(std::string text) const
{
    std::string aux;
    aux = text;
    if (aux.length() > 10)
    {
        aux[9] = '.';
        aux[10] = '\0';
    }
    std::cout << aux << std::endl;
}

void    Contact::print_contact() const
{
    std::cout << "First name : ";
    Contact::print(first_name);
    std::cout << "Last name : ";
    Contact::print(last_name);
    std::cout << "Nickname : ";
    Contact::print(nickname);
    std::cout << "Phone number : ";
    Contact::print(phone_number);
    std::cout << "Darkest Secret : ";
    Contact::print(darkest_secret);
}

std::string Contact::get_first_name(void) const
{
    return (this->first_name);
}

bool Contact::set_first_name(std::string first_name)
{
    this->first_name = first_name;
    return(true);
}

std::string Contact::get_last_name(void) const
{
    return (this->last_name);
}

bool Contact::set_last_name(std::string last_name)
{
    this->last_name = last_name;
    return(true);
}

std::string Contact::get_nickname(void) const
{
    return (this->nickname);
}

bool Contact::set_nickname(std::string nickname)
{
    this->nickname = nickname;
    return(true);
}

std::string Contact::get_phone_number(void) const
{
    return (this->phone_number);
}

bool Contact::set_phone_number(std::string phone_number)
{
    this->phone_number = phone_number;
    return(true);
}

std::string Contact::get_darkest_secret(void) const
{
    return (this->darkest_secret);
}

bool Contact::set_darkest_secret(std::string darkest_secret)
{
    this->darkest_secret = darkest_secret;
    return(true);
}

Contact::Contact() //:name("pedro"),age(10)
{}

Contact::~Contact()
{}
