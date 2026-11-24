#pragma once

#include <stdexcept>
#include <iostream>

template <typename T>
class Array
{
private:
    T *data;
    unsigned int array_size;

public:
    Array() : data(NULL), array_size(0) {}

    Array(unsigned int n) : data(NULL), array_size(n)
    {
        if (n > 0)
            data = new T[n];
    }

    Array(const Array &other) : data(NULL), array_size(other.array_size)
    {
        if (array_size > 0)
        {
            data = new T[array_size];
            for (unsigned int i = 0; i < array_size; i++)
                data[i] = other.data[i];
        }
    }

    Array &operator=(const Array &other)
    {
        if (this != &other)
        {
            delete[] data;
            array_size = other.array_size;
            data = (array_size > 0) ? new T[array_size] : NULL;
            for (unsigned int i = 0; i < array_size; i++)
                data[i] = other.data[i];
        }
        return *this;
    }

    ~Array()
    {
        delete[] data;
    }

    unsigned int size() const
    {
        return array_size;
    }

    T &operator[](unsigned int index)
    {
        if (index >= array_size)
            throw std::out_of_range("Index out of bounds");
        return data[index];
    }

    const T &operator[](unsigned int index) const
    {
        if (index >= array_size)
            throw std::out_of_range("Index out of bounds");
        return data[index];
    }
};
