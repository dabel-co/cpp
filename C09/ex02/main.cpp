#include <iostream>
#include <array>
#include <deque>
#include "PmergeMe.cpp"
#include <ctime>

int main(int argc, char **argv)
{
    if (argc < 2)
        return (1);

    std::deque<int> x;
    std::vector<int> y;
    for (int i = 1; i < argc; i++) //checking for invalid input / filling both the vector and the list
    {
        long aux = strtol(argv[i], NULL, 10);
        //std::cout << "valor de aux " << aux << "longitud = " << strlen(argv[i]) << std::endl;
        if ( (aux == 0 && argv[i][0] != '0') || (strlen(argv[i]) != 1  && aux == 0) || aux < 0 || aux > INT_MAX)
        {
            std::cout << "Invalid input" << std::endl;
            return (1);
        }
        int value = (int)aux;
        x.push_back(value);
        y.push_back(value);
    }

    std::cout << "Before: ";
    for (std::vector<int>::iterator i = y.begin(); i != y.end(); i++)
        std::cout << *i << " ";
    std::cout << std::endl;

    clock_t vector_start = clock();
    ford_johnson(y);    //vector
    clock_t vector_end = clock();

    clock_t deque_start = clock();
    ford_johnson(x);    //deque
    clock_t deque_end = clock();
    
    std::cout << "after: ";
     for (std::vector<int>::iterator i = y.begin(); i != y.end(); i++)
        std::cout << *i << " ";
    std::cout << std::endl;
    //for (std::deque<int>::iterator i = x.begin(); i != x.end(); i++)
      //  std::cout << *i << " ";
    //std::cout << std::endl;
    
    double vector_duration = 1000.0 * (vector_end - vector_start) / CLOCKS_PER_SEC; //time in ms
    double deque = 1000.0 * (deque_end - deque_start) / CLOCKS_PER_SEC;       //time in ms
    std::cout << "Time to process with std::vector " << vector_duration << " ms" << std::endl;
    std::cout << "Time to process with std::deque " << deque << " ms" << std::endl;
    return (0);
}