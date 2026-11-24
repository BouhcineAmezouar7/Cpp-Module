#pragma once

#include <iostream>
#include <algorithm>
#include <iterator>
#include <exception>

template <typename T>
// * Function template to find a value in a container
typename T::const_iterator easyfind(const T &container, int value)
{
     // * we use const_iterator because we get const container and we don't need to edit the iterator just read it
    typename T::const_iterator it = std::find(container.begin(), container.end(), value);
    if (it == container.end())
    {
        throw std::runtime_error("Value not found in container");
    }
    return it;
}
