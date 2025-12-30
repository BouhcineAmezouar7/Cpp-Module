#include "iter.hpp"

int main()
{
    int arrayInt[] = {1, 2, 3, 4, 5};
    size_t sizeInt = sizeof(arrayInt) / sizeof(arrayInt[0]);
    std::cout << "Printing integer array elements:" << std::endl;
    ft_iter(arrayInt, sizeInt, printElement);

    std::string arrayStr[] = {"Hello", "World", "from", "ft_iter"};
    size_t sizeStr = sizeof(arrayStr) / sizeof(arrayStr[0]);
    std::cout << "Printing string array elements:" << std::endl;
    ft_iter(arrayStr, sizeStr, printElement);

    return 0;
}