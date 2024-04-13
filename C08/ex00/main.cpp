#include "easyfind.hpp"

int main()
{
	std::vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);
	try
	{
		easyfind(&v, 3);
	}
	catch (std::exception &e)
	{
		std::cout << "Needle not found in the haystack" << std::endl;
	}
	return 0;  
}