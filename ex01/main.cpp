#include "iter.hpp"
/*I use ::iter to explicitly call the function defined in the global scope.
    It means the function is not inside any class or namespace.*/
int main() {
    std::cout << "Printing integers: " << std::endl;
    int numbers[] = {1, 2, 3, 4, 5};
    size_t length = sizeof(numbers) / sizeof(numbers[0]);
    ::iter(numbers, length, printString<int>);

    std::string words[] = {"Hello", "World", "Template", "Functions"};
    size_t wordLength = sizeof(words) / sizeof(words[0]);
    std::cout << "Printing words: " << std::endl;
    ::iter(words, wordLength, printString<std::string>);

    double doublenumbers[] = {11.1, 22.2, 33.3, 44.4, 55.5};
    size_t doublelength = sizeof(doublenumbers) / sizeof(doublenumbers[0]);
    std::cout << "Printing doubles: " << std::endl;
    ::iter(doublenumbers, doublelength, printString<double>);
    return 0;
}
