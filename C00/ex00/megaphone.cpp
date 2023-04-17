#include <iostream>

char *ft_uppercase(char *x)
{
    int i;

    i = 0;
    while (x[i])
    {
    if (x[i] > 96 && x[i] < 123)
        x[i] = x[i] - 32;
        i++;
    }
    return (x);

}
int main(int argc, char **argv)
{
    int i = 1;
    char *aux;
    if (argc == 1)
    {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl; 
        return 0;
    }
    while (i < argc - 1)
    {
        aux = ft_uppercase(argv[i]);
        std::cout << aux << " ";
        i++;

    }
    aux = ft_uppercase(argv[i]);
    std::cout << aux << std::endl;
    return 0;
} 