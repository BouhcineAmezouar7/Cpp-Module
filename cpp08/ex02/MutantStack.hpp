#pragma once

#include <stack>
#include <iostream>
#include <algorithm>
#include <iterator>

template <typename T>
class MutantStack : public std::stack<T>
{
public:
    typedef typename std::stack<T>::container_type container_type;  // * Define a type for the underlying container
    typedef typename container_type::iterator iterator;             // * Define an iterator type for the underlying container
    typedef typename container_type::const_iterator const_iterator; // * Define a const iterator type for the underlying container

    iterator begin() { return this->c.begin(); } // * Return an iterator to the beginning of the stack
    iterator end() { return this->c.end(); }     // * Return an iterator to the end of the stack

    const_iterator begin() const { return this->c.begin(); } // * Return a const iterator to the beginning of the stack
    const_iterator end() const { return this->c.end(); }     // * Return a const iterator to the end of the stack
};