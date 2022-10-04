/**
 * @file fibonacci_w_maps.cpp
 * @author Toba Adesanya (adesanyatoba@gmail.com)
 * @brief
 * @version 0.1
 * @date 2022-10-04
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <iostream>
#include <map>
#include <utility>

std::map<int, int> fib_seq;

/**
 * @brief Fib faster with time comp: O(n) and space O(n)
 * 
 * @param n 
 * @return int 
 */
int fib(int n)
{
    // Insert the known fib numbers
    fib_seq.insert(std::pair<int, int>(0, 0));
    fib_seq.insert(std::pair<int, int>(1, 1));

    std::map<int, int>::iterator p = fib_seq.find(n);
    if (p != fib_seq.end())
    {
        // Key exists. Return value
        return p->second;
    }
    fib_seq.insert(std::make_pair(n, fib(n - 1) + fib(n - 2)));
    p = fib_seq.find(n);
    return p->second;
}

/**
 * @brief Fib normal or slow, with time comp: O(n^2) and space: O(1)
 * 
 * @param n 
 * @return int 
 */
int fib_slow(int n)
{
    if(n < 2) return n;

    return fib(n-1) + fib(n-2);
}

int main()
{
    int n = 5;
    std::cout << "Fib fast of " << n << ": " << fib(n) << std::endl;

    std::cout << "Fib slow of " << n << ": " << fib_slow(n) << std::endl;

    return 0;
}
