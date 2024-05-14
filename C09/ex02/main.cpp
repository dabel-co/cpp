
#include <iostream>
#include <list>
#include <array>
#include <unistd.h>
#include <sys/time.h>
#include "PmergeMe.cpp"
#include <ctime>
int main(int argc, char **argv)
{
    if (argc < 2)
        return (1);

    std::list<int> x;
    std::vector<int> y;
    for (int i = 1; i < argc; i++)
    {
        long aux = strtol(argv[i], NULL, 10);
        if ((aux == 0 && argv[i][0] != '0') || aux < 0 || aux > INT_MAX)
        {
            std::cout << "Invalid input" << std::endl;
            return (1);
        }
        else if(aux >= 0 && aux <= INT_MAX)
        {
            int value = (int)aux;
            x.push_back(value);
            y.push_back(value);
        }
    }

    std::cout << "Before: ";
    for (std::vector<int>::iterator i = y.begin(); i != y.end(); i++)
        std::cout << *i << " ";
    std::cout << std::endl;

    clock_t vector_start = clock();
    ford_johnson(y);    //vector
    clock_t vector_end = clock();

    clock_t list_start = clock();
   // ford_johnson(x);
    clock_t list_end = clock();
    
    std::cout << "after: ";
    for (std::vector<int>::iterator i = y.begin(); i != y.end(); i++)
        std::cout << *i << " ";
    std::cout << std::endl;

    double vector_duration = 1000.0 * (vector_end - vector_start) / CLOCKS_PER_SEC; //time in ms
    double list_duration = 1000.0 * (list_end - list_start) / CLOCKS_PER_SEC;       //time in ms
    std::cout << "Time to process with std::vector " << vector_duration << " ms" << std::endl;
    std::cout << "Time to process with std::list " << list_duration << " ms" << std::endl;

    return (0);
}