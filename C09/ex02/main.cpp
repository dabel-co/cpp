
#include <iostream>
#include <list>
#include <array>
#include <unistd.h>
#include <sys/time.h>
int main(int argc, char **argv)
{
    if (argc < 2)
    {
        std::cout << "invalid argument" << std::endl;
        return (1);
    }
    std::list<int> x; //fill containers
    std::vector<int> y;
    for (int i = 1; i < argc; i++)
    {
        long aux = strtol(argv[i], NULL, 10);
        if(aux > 0 && aux < INT_MAX)
        {
            int value = (int)aux;
            x.push_back(value);
            y.push_back(value);
        }
        else //maybe add invalid input like letters check here
            std::cout << "Invalid number" << std::endl;
    }
    std::cout << "Before: ";    //print before
    for (std::vector<int>::iterator i = y.begin(); i != y.end(); i++)
        std::cout << *i << " ";
    std::cout << std::endl;

    struct timeval tp;
    gettimeofday(&tp, NULL);
    long int begin = tp.tv_sec * 1000 + tp.tv_usec / 1000;

    std::sort(y.begin(), y.end());

    gettimeofday(&tp, NULL);
    long int end = tp.tv_sec * 1000 + tp.tv_usec / 1000;
    std::cout << "after: ";
    for (std::vector<int>::iterator i = y.begin(); i != y.end(); i++)
        std::cout << *i << " ";
    std::cout << std::endl;
    std::cout << "Time to process a range of 3000 elements with... " << end - begin << std::endl;
}