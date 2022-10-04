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
#include <chrono>
#include <bits/stdc++.h>

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
    
    // Start the timer
    auto start = std::chrono::high_resolution_clock::now();

    // Unsync the I/O of C and C++
    std::ios_base::sync_with_stdio(false);

    // Call the function
    std::cout << "Fib fast of " << n << ": " << fib(n) << std::endl;
    n = 46;
    std::cout << "Fib fast of " << n << ": " << fib(n) << std::endl;
    n = 102;
    std::cout << "Fib fast of " << n << ": " << fib(n) << std::endl;
    auto end = std::chrono::high_resolution_clock::now();

    double time_taken = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();
    time_taken *= 1e-9;

    std::cout << "Time taken: " << std::fixed << time_taken << std::setprecision(9) << "s\n\n";

    /********************************************************************************/

    auto start2 = std::chrono::high_resolution_clock::now();
    // Unsync the I/O of C and C++
    std::ios_base::sync_with_stdio(false);

    // Call the function
    n = 5;
    std::cout << "Fib slow of " << n << ": " << fib_slow(n) << std::endl;
    n = 46;
    std::cout << "Fib slow of " << n << ": " << fib_slow(n) << std::endl;
    n = 102;
    std::cout << "Fib slow of " << n << ": " << fib_slow(n) << std::endl;
    auto end2 = std::chrono::high_resolution_clock::now();

    double time_taken2 = std::chrono::duration_cast<std::chrono::nanoseconds>(end2 - start2).count();
    time_taken2 *= 1e-9;

    std::cout << "Time taken: " << std::fixed << time_taken2 << std::setprecision(9) << "s\n\n";

    return 0;
}
