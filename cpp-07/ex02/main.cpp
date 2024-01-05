#include <iostream>
#include <cstdlib>
#include "Array.hpp"

#define MAX_VAL 750
int main()
{
	Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
	for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    //SCOPE
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
    }
    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
    try
    {
		numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
	    numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }
    delete [] mirror;//

	std::cout << " ====== MY TEST AFTER THIS LINE ======" << std::endl;

	Array<char> str(10);
	std::string s = "qwertyuiop";
	for (int i = 0; i < 10; i++)
	{
		str[i] = s[i];
	}
	for (int i = 0; i < 10; i++)
	{
		std::cout << str[i];
	}
	std::cout << std::endl;
	// test copy constructor
	Array<char> str2(str);
	for (int i = 0; i < 10; i++)
	{
		std::cout << str2[i];
	}
	std::cout << std::endl;
	// test assign new value to orginal array and compare with copy
	std::string s2 = "asdfghjklz";
	for (int i = 0; i < 10; i++)
	{
		str[i] = s2[i];
	}
	for (int i = 0; i < 10; i++)
	{
		std::cout << str[i] << " " << str2[i] << std::endl;
	}

    return 0;
}