#include "PmergeMe.hpp"

// * Comparison counter
int comparisons = 0;

// * Check if we have duplicate numbers
bool checkIfHasDuplicateNumber(std::vector<int> &vector)
{
    for (size_t i = 0; i < vector.size(); i++)
    {
        for (size_t j = i + 1; j < vector.size(); j++)
        {
            if (vector[i] == vector[j])
            {
                return true;
            }
        }
    }
    return false;
}

// * Generate Jacobsthal number
size_t GenerateJacobsthalNumber(size_t k)
{
    if (k == 0)
        return 0;
    if (k == 1)
        return 1;
    size_t prev2 = 0, prev1 = 1;
    for (size_t i = 2; i <= k; i++)
    {
        size_t result = prev1 + 2 * prev2;
        prev2 = prev1;
        prev1 = result;
    }
    return prev1;
}

// * Print container status
template <typename T>
void PrintStatusContainer(T &Container, clock_t duration)
{
    std::cout.precision(6);
    double seconds = (double)duration / CLOCKS_PER_SEC; // convert clock ticks to seconds
    double microseconds = seconds * 1000000;            // convert seconds to microseconds
    std::cout << "Time to process a range of " << Container.size() << " elements with std::[...] : " << std::fixed << microseconds << " us" << std::endl;
}

// * Insertion Phase template
template <typename T>
void InsertionPhase(T &container, int pair_level)
{
    typedef typename T::iterator iter;
    typedef typename std::vector<iter>::iterator iter_chain;
    int pair_units_nbr = container.size() / pair_level;
    if (pair_units_nbr < 2)
        return;

    bool is_odd = (pair_units_nbr % 2 == 1);
    std::vector<iter> main_chain;
    std::vector<iter> pend_chain;

    main_chain.push_back(container.begin() + pair_level - 1);
    main_chain.push_back(container.begin() + pair_level * 2 - 1);

    for (int i = 4; i <= pair_units_nbr; i += 2)
    {
        pend_chain.push_back(container.begin() + pair_level * (i - 1) - 1);
        main_chain.push_back(container.begin() + pair_level * i - 1);
    }
    if (is_odd)
    {
        pend_chain.push_back(container.begin() + (pair_level * pair_units_nbr) - 1);
    }

    int prev_jac = 1;
    int inserted = 0;

    for (int k = 2; true; k++)
    {
        int curr_jac = GenerateJacobsthalNumber(k);
        int jac_diff = curr_jac - prev_jac;

        if (jac_diff > (int)pend_chain.size())
            break;

        for (int i = jac_diff - 1; i >= 0 && !pend_chain.empty(); i--)
        {
            iter_chain pend_it = pend_chain.begin() + i;
            iter_chain bound_it = main_chain.begin() + std::min((int)main_chain.size(), curr_jac + inserted);
            iter_chain pos = std::upper_bound(main_chain.begin(), bound_it, *pend_it, _comp<iter>);
            main_chain.insert(pos, *pend_it);
            pend_chain.erase(pend_it);
        }
        prev_jac = curr_jac;
        inserted += jac_diff;
    }

    while (!pend_chain.empty())
    {
        iter_chain pend_it = pend_chain.end() - 1;
        iter_chain pos = std::upper_bound(main_chain.begin(), main_chain.end(), *pend_it, _comp<iter>);

        main_chain.insert(pos, *pend_it);
        pend_chain.pop_back();
    }

    std::vector<int> result;
    // result.reserve(7) => [?, ?, ?, ?, ?, ?, ?]
    result.reserve(container.size());
    for (iter_chain it = main_chain.begin(); it != main_chain.end(); it++)
    {
        iter base = *it;
        for (int i = 0; i < pair_level; i++)
        {
            iter pair_start = base - pair_level + 1 + i;
            result.push_back(*pair_start);
        }
    }
    for (size_t i = 0; i < result.size(); i++)
        container[i] = result[i];
}

// * Pairing Phase template
template <typename T>
void PairingPhase(T &container, int pair_level)
{
    // like std::vector<int>::iterator or std::deque<int>::iterator
    typedef typename T::iterator Iterator;
    // * if we have less than 2 pairs, we don't need to do anything
    int pair_units_nbr = container.size() / pair_level;
    if (pair_units_nbr < 2)
        return;

    bool is_odd = ((pair_units_nbr % 2) == 1);

    Iterator start = container.begin();                                     // index 0 (value 1)
    Iterator last = next(container.begin(), pair_level * (pair_units_nbr)); // if odd = index 7 (one past end, no value), else index 6 (value 99)
    Iterator end = next(last, -(is_odd * pair_level));                      // index 6 (value 99) if odd, else index 7 (one past end)

    int jump = 2 * pair_level;
    for (Iterator it = start; it != end; std::advance(it, jump))
    {
        Iterator this_pair = next(it, pair_level - 1);
        Iterator next_pair = next(it, pair_level * 2 - 1);
        if (_comp(next_pair, this_pair))
            _swap_pair(this_pair, pair_level);
    }

    PairingPhase(container, pair_level * 2);

    InsertionPhase(container, pair_level);
}

// * Main function - PARSING + SORTING
void mergeInsertionSort(int ac, char **av)
{
    // ? ********************* PARSING *********************

    // * Create a Vector and Deque to store all numbers
    std::vector<int> vector;
    std::deque<int> deque;

    char *end = NULL;
    const int base = 10;

    long number = 0;
    std::string str = "";

    for (int i = 1; i < ac; i++)
    {
        str = av[i];
        size_t pos = 0;
        std::string token;

        // * Split the argument by spaces and process each token
        while (pos < str.length())
        {
            // * Skip spaces in the front
            while (pos < str.length() && std::isspace(str[pos]))
                pos++;
            
            // * If we reached the end of the string, break the loop
            if (pos >= str.length())
                break;

            // * 
            size_t start = pos;
            while (pos < str.length() && !std::isspace(str[pos]))
                pos++;
            
            token = str.substr(start, pos - start);

            // * check if we have empty token
            if (token.empty())
                continue;

            // * convert string to number
            number = std::strtol(token.c_str(), &end, base);
            if (*end != '\0')
                throw std::runtime_error("Error: you have a non-numeric character in your input");

            // * check if the number is negative
            if (number < 0)
                throw std::runtime_error("Error: you have a negative number in your input");

            // * check if bigger than max int
            if (number > INT_MAX)
                throw std::runtime_error("Error: you have a number bigger than max int in your input");

            // * add the number to vector and deque
            vector.push_back((int)number);
            deque.push_back((int)number);
        }
    }

    // * check if have duplicated numbers
    if (checkIfHasDuplicateNumber(vector))
        throw std::runtime_error("Error: you have duplicated number in your input");

    // ? ********************* END OF PARSING *********************

    // ? ********************* SORTING *********************

    // * Print before
    std::cout << "Before: ";
    for (size_t i = 0; i < vector.size(); i++)
        std::cout << vector[i] << " ";
    std::cout << std::endl;

    // * Sort using vector
    clock_t startTimeVector, endTimeVector; // * to measure time taken by vector sorting
    startTimeVector = clock();              // * start time
    if (vector.size() > 1)
    { // * if we have more than 1 element, we need to sort
        PairingPhase(vector, 1);
    }
    endTimeVector = clock() - startTimeVector;

    // * Print after
    std::cout << "After: ";
    for (size_t i = 0; i < vector.size(); i++)
        std::cout << vector[i] << " ";
    std::cout << std::endl;

    PrintStatusContainer(vector, endTimeVector);

    // std::cout << "Number of comparisons made during vector sorting: " << comparisons << std::endl;
    // * Sort using deque
    clock_t startTimeDeque, endTimeDeque;
    startTimeDeque = clock();
    if (deque.size() > 1)
    {
        PairingPhase(deque, 1);
    }
    endTimeDeque = clock() - startTimeDeque;

    PrintStatusContainer(deque, endTimeDeque);

    // std::cout << "Number of comparisons made during deque sorting: " << comparisons / 2 << std::endl;

    // // * VECTOR Verification
    // bool vector_sorted = true;
    // for (size_t i = 1; i < vector.size(); i++)
    // {
    //     if (vector[i] < vector[i - 1])
    //     {
    //         vector_sorted = false;
    //         break;
    //     }
    // }

    // // * DEQUE Verification
    // bool deque_sorted = true;
    // for (size_t i = 1; i < deque.size(); i++)
    // {
    //     if (deque[i] < deque[i - 1])
    //     {
    //         deque_sorted = false;
    //         break;
    //     }
    // }

    // std::cout << "\nVerification: " << (vector_sorted && deque_sorted ? "✓ CORRECTLY SORTED" : "✗ NOT SORTED") << std::endl;
    // std::cout << "Total comparisons made: " << comparisons << std::endl;
}
