#include "MutantStack.hpp"

int main()
{
    MutantStack<int> mstack;

    mstack.push(5);
    mstack.push(17);

    std::cout << "Top: " << mstack.top() << std::endl; // * Output the top element of the stack

    mstack.pop(); // * Remove the top element

    std::cout << "Size: " << mstack.size() << std::endl; // * Output the size of the stack

    mstack.push(3);
    mstack.push(77);
    mstack.push(737);
    //[...]
    mstack.push(0);

    MutantStack<int>::iterator it = mstack.begin(); // * Create an iterator to the beginning of the stack
    MutantStack<int>::iterator ite = mstack.end();  // * Create an iterator to the end of the stack

    ++it; // * Increment the iterator
    --it; // * Decrement the iterator

    while (it != ite) // * Iterate through the stack and output each element
    {
        std::cout << "Element: " << *it << std::endl;
        ++it;
    }

    return 0;
}