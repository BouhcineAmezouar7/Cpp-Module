#pragma once

#include <string>
#include <iostream>

template <typename T>
void ft_swap(T &a, T &b)
{
    T temp = a;
    a = b;
    b = temp;
};

template <typename T>
T ft_min(T &a, T &b)
{
    if (a == b)
        return (b);
    if (a < b)
        return (a);
    else
        return (b);
}

template <typename T>
T ft_max(T &a, T &b)
{
    if (a == b)
        return (b);
    if (a > b)
        return (a);
    else
        return (b);
}
