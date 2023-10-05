#include <iostream>
#include <fstream>

void replace(std::string& str, const std::string& from, const std::string& to)
{
    size_t startPos = 0;
    size_t foundPos;
    while ((foundPos = str.find(from, startPos)) != std::string::npos)
    {
        str = str.substr(0, foundPos) + to + str.substr(foundPos + from.length());
        startPos = foundPos + to.length();
    }
}

int main(int argc, char **argv)
{
    if (argc != 4 || !argv[1] || !argv[2] || !argv[3])
    {
        std::cout << "Error" << std::endl;
        return (1);
    }
    std::string inputname = argv[1];
    std::ifstream   inputfile(inputname);
    if (inputfile.fail())
    {
        std::cout << "Error, file not found" << std::endl;
        return (1);
    }
    std::ofstream   output(inputname + ".replace");
    std::string     line;
    
    while (std::getline(inputfile, line))
    {
        replace(line, argv[2], argv[3]);
        output << line << '\n';
    }
    inputfile.close();
    output.close();
    return(0);
}