#include "whatever.hpp"

int main()
{
    int x = 3;
    int y = 8;
    ft_swap(x, y);
    std::cout << "y = " << y << "  x = " << x << std::endl;

    int min = ft_min(x, y);
    std::cout << "min is : " << min << std::endl;
    int max = ft_max(x, y);
    std::cout << "max is : " << max << std::endl;
}