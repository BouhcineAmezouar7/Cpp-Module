#include "iter.hpp"

template <typename T>
void printElement(T &element)
{
    std::cout << "array element: " << element << std::endl;
}

template <typename T>
void ft_increment(T &element)
{
    element += 1;
}

template <typename T>
void ft_increment(const T &element)
{
    (void)element; // To avoid unused parameter warning
}

int main()
{
    const unsigned int size = 5;
    int intArray[] = {1, 2, 3, 4, 5};
    std::string strArray[] = {"Hello", "World", "C++", "Templates", "!"};

    // Test with int array
    std::cout << "Iterating over int array:" << std::endl;
    ft_iter(intArray, size, printElement);

    // Test with string array
    std::cout << "\nIterating over string array:" << std::endl;
    ft_iter(strArray, size, printElement);

    // Test with incrementing int array
    std::cout << "\nIncrementing int array:" << std::endl;
    ft_iter(intArray, size, ft_increment);
    ft_iter(intArray, size, printElement);

    return 0;
}
