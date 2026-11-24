
#include "easyfind.hpp"
#include <vector>
#include <queue>
#include <list>

int main()
{
    try
    {
        // * Vector
        std::vector<int> a;
        for (int i = 0; i < 1000; i++)
        {
            a.push_back(i);
        }

        std::vector<int>::const_iterator it = easyfind(a, 999);
        std::cout << *it << std::endl;

        // * Deque
        std::deque<int> b;
        for (int i = 0; i < 1000; i++)
        {
            b.push_front(i);
        }

        std::deque<int>::const_iterator it2 = easyfind(b, 888);
        std::cout << *it2 << std::endl;

        // * List
        std::list<int> c;
        for (int i = 0; i < 1000; i++)
        {
            c.push_back(i);
        }

        std::list<int>::const_iterator it3 = easyfind(c, 1777);
        std::cout << *it3 << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
}