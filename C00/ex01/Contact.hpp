#include <string>
#include <iostream>
#include <iomanip>

class Contact {
public :
    Contact();
    ~Contact();
    void add(void);
    void    print_contact(void) const;
    void    print(std::string text) const;

    std::string get_first_name(void) const;
    bool        set_first_name(std::string first_name);

    std::string get_last_name(void) const;
    bool set_last_name(std::string last_name);

    std::string get_nickname(void) const;
    bool set_nickname(std::string nickname);

    std::string get_phone_number(void) const;
    bool set_phone_number(std::string phone_number);

    std::string get_darkest_secret(void) const;
    bool set_darkest_secret(std::string darkest_secret);

private :
    std::string first_name;
    std::string last_name;
    std::string nickname;
    std::string phone_number;
    std::string darkest_secret;
};