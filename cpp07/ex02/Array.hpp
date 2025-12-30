#pragma once

#include <stdexcept>
#include <iostream>

template <typename T>
class Array
{
private:
    T *_data;
    unsigned int _size;

public:
    // Default constructor
    Array() : _data(NULL), _size(0) {}

    // Size constructor
    Array(unsigned int n) : _data(NULL), _size(n)
    {
        if (n > 0)
            _data = new T[n];
    }

    // Copy constructor
    Array(const Array &other) : _data(NULL), _size(other._size)
    {
        if (_size > 0)
        {
            _data = new T[_size];
            for (unsigned int i = 0; i < _size; i++)
                _data[i] = other._data[i];
        }
    }

    // Assignment operator
    Array &operator=(const Array &other)
    {
        if (this != &other)
        {
            delete[] _data;
            _size = other._size;
            _data = (_size > 0) ? new T[_size] : NULL;
            for (unsigned int i = 0; i < _size; i++)
                _data[i] = other._data[i];
        }
        return *this;
    }

    // Destructor
    ~Array()
    {
        delete[] _data;
    }

    // Size
    unsigned int size() const
    {
        return _size;
    }

    // Operator []
    T &operator[](unsigned int index)
    {
        if (index >= _size)
            throw std::out_of_range("Index out of bounds");
        return _data[index];
    }

    const T &operator[](unsigned int index) const
    {
        if (index >= _size)
            throw std::out_of_range("Index out of bounds");
        return _data[index];
    }
};
