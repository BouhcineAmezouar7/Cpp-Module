#pragma once

#include <iostream>
#include <algorithm>
#include <iterator>
#include <exception>

template <typename T>
// * Function template to find a value in a container
typename T::iterator easyfind(T &container, int value)
{
    typename T::iterator it = std::find(container.begin(), container.end(), value);
    if (it == container.end())
    {
        throw std::runtime_error("Value not found in container");
    }
    return it;
}
