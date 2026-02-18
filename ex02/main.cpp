#include "Array.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

#define MAX_VAL 750

int main(int, char**)
{
    std::cout << "=== Testing default constructor ===" << std::endl;
    Array<int> empty;
    std::cout << "Empty array size: " << empty.size() << std::endl;
    
    std::cout << "=== Creating Array with size " << MAX_VAL << " ===" << std::endl;
    Array<int> numbers(MAX_VAL);

    std::cout << "=== Creating mirror array ===" << std::endl;
    int* mirror = new int[MAX_VAL];

    std::srand(std::time(NULL));

    std::cout << "=== Filling arrays with random values ===" << std::endl;
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = std::rand();
        numbers[i] = value;
        mirror[i] = value;
    }

    std::cout << "=== Testing copy constructor (deep copy) ===" << std::endl;
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
    }

    std::cout << "=== Testing assignment operator ===" << std::endl;
        Array<int> assigned;
        assigned = numbers;
    std::cout << "assigned[0] = " << assigned[0] << std::endl;

    std::cout << "Copy test scope ended successfully." << std::endl;

    std::cout << "=== Verifying saved values ===" << std::endl;
    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "Error: values do not match!" << std::endl;
            delete[] mirror;
            return 1;
        }
    }
    std::cout << "Values verified successfully." << std::endl;

    std::cout << "=== Testing valid index access ===" << std::endl;
    try
    {
        numbers[2] = 0;
        std::cout << "numbers[2] modified successfully." << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << "Unexpected exception: " << e.what() << '\n';
    }

    std::cout << "=== Testing out-of-bounds access ===" << std::endl;
    try
    {
        numbers[MAX_VAL] = 1;
        std::cout << "numbers[] modified successfully." << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cout << "Exception caught correctly: " << e.what() << std::endl;
    }

    std::cout << "=== Modifying array again ===" << std::endl;
    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = std::rand();
    }

    std::cout << "All tests completed successfully." << std::endl;

    delete [] mirror;
    return 0;
}
