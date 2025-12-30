#pragma once

#include <cstddef>
#include <iostream>

template <typename T>
void ft_iter(T *array, size_t size, void (*func)(T &))
{
    for (size_t i = 0; i < size; i++)
    {
        func(array[i]);
    }
}

template <typename T>
void printElement(T &element)
{
    std::cout << "array element: " << element << std::endl;
}
