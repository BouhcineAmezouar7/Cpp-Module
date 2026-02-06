#pragma once

#include <cstddef>
#include <iostream>

template <typename T>
void ft_iter(T *array, const unsigned int &size, void (*func)(T &))
{
    if (!array || size <= 0)
        return;
    for (unsigned int i = 0; i < size; i++)
        func(array[i]);
}

template <typename T>
void ft_iter(const T *array, const unsigned int &size, void (*func)(const T &))
{
    if (!array || size <= 0)
        return;
    for (unsigned int i = 0; i < size; i++)
        func(array[i]);
}
