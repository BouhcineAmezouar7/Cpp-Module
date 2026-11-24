#pragma once

#include <stack>
#include <iostream>
#include <algorithm>
#include <iterator>

template <typename T>
class MutantStack : public std::stack<T>
{
public:
    typedef typename std::stack<T>::container_type container_type;
    typedef typename container_type::iterator iterator;
    typedef typename container_type::const_iterator const_iterator;

    iterator begin() { return this->c.begin(); } // * Return an iterator to the beginning of the stack
    iterator end() { return this->c.end(); }     // * Return an iterator to the end of the stack

    const_iterator begin() const { return this->c.begin(); }
    const_iterator end() const { return this->c.end(); }
};