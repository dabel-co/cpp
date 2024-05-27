#include <iostream>
#include <fstream>
#include "BitcoinExchange.hpp"
int main(int argc, char **argv)
{
    if (argc != 2) {
        std::cerr << "Error: invalid number of arguments." << std::endl;
        return (1);
    }
    else
    {
        try
        {
            BitcoinExchange btc;
            btc.main_routine(argv[1]);
        }
        catch(std::exception & e)
            {
                std::cout << e.what() << std::endl;
            }
    }

    return (0);
}
