#ifndef ITER_HPP
#define ITER_HPP
#include <iostream>
/*We are creating a generic function 
that takes a value of any type by const reference and prints it, 
as long as that type supports the output operator*/
template <typename T2>
void printString(const T2& print) {
    std::cout << print << std::endl;
}
/*T1 represents the type of the elements stored in the array.
F represents the type of the function that will be applied to each elemen
The iter function is a generic function that takes an array, 
its length, and another function, and applies that function to each element of the array.
We use two template parameters because 
the type of the array elements and the type of the functione independent and may be different.*/
template <typename T1, typename F>
void iter(T1 *arr, size_t length, F printString)
{
    for (size_t i = 0; i < length; i++)
        printString(arr[i]);
};

#endif