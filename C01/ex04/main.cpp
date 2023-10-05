#include <iostream>
#include <fstream>

void replaceAll(std::string& str, const std::string& from, const std::string& to)
{
    size_t startPos = 0;
    size_t foundPos;
    while ((foundPos = str.find(from, startPos)) != std::string::npos)
    {
        str = str.substr(0, foundPos) + to + str.substr(foundPos + from.length());
        startPos = foundPos + to.length();
    }
}
//change order and stuff
int main(int argc, char **argv)
{
    std::string inputname = argv[1];
    std::string s1 = argv[2];
    std::string s2 = argv[3];
    std::ifstream   inputfile(inputname);
    std::ofstream   output(inputname + ".replace");
    std::string     line;
    std::cout << inputname << std::endl;

    if (argc == 4)
    {
        while (std::getline(inputfile, line))
        {
            replaceAll(line, argv[2], argv[3]);
            output << line << '\n';
        }
        inputfile.close();
        output.close();
    }
    else
    {
         std::cout << "error, usage : replace <file> old_word new_word" << std::endl;
         return(1);
    }
    return(0);

}