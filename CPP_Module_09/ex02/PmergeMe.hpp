#ifndef PMERGEME_HPP
# define PMERGEME_HPP

// * Includes
#include <iostream>
#include <algorithm>
#include <climits>
#include <time.h>
#include <iomanip>
#include <vector>
#include <deque>
#include <stack>
#include <utility> // * for std::pair container
#include <sstream> // * for string stream
#include <cctype>

// * Typedefs
typedef std::vector<int>::iterator _it;
typedef std::deque<int>::iterator _itdeque;

// * External variables
extern int comparisons;

// * Function declarations
void mergeInsertionSort(int ac, char **av);
size_t GenerateJacobsthalNumber(size_t k);

// * Template functions
template <typename T>
T next(T it, int steps) {
	std::advance(it, steps);
	return it;
}

template <typename T>
bool _comp(T a, T b) {
	comparisons++;
	return *a < *b;
}

template <typename T>
void _swap_pair(T it, int pair_level) {
	T start = next(it, 1 - pair_level);
	T end = next(start, pair_level);
	while (start != end) {
		std::iter_swap(start, next(start, pair_level));
		start++;
	}
}

#endif