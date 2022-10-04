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
#include <sys/time.h>

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
    
    struct timeval start, end;
    // Start the timer
    gettimeofday(&start, NULL);

    // Unsync the I/O of C and C++
    std::ios_base::sync_with_stdio(false);

    // Call the function
    std::cout << "Fib fast of " << n << ": " << fib(n) << std::endl;
    n = 46;
    std::cout << "Fib fast of " << n << ": " << fib(n) << std::endl;
    n = 102;
    std::cout << "Fib fast of " << n << ": " << fib(n) << std::endl;
    // Stop the timer
    gettimeofday(&end, NULL);

    double time_taken;

    time_taken = (end.tv_sec - start.tv_sec) * 1e6;
    time_taken = (time_taken + (end.tv_usec - start.tv_usec)) * 1e-6;

    std::cout << "Time taken: " << std::fixed << time_taken << std::setprecision(9) << "s\n\n";

    /********************************************************************************/

    struct timeval start2, end2;
    // Start the timer
    gettimeofday(&start2, NULL);

    // Unsync the I/O of C and C++
    std::ios_base::sync_with_stdio(false);

    // Call the function
    n = 5;
    std::cout << "Fib slow of " << n << ": " << fib_slow(n) << std::endl;
    n = 46;
    std::cout << "Fib slow of " << n << ": " << fib_slow(n) << std::endl;
    n = 102;
    std::cout << "Fib slow of " << n << ": " << fib_slow(n) << std::endl;
    // Stop the timer
    gettimeofday(&end2, NULL);

    double time_taken2;

    time_taken2 = (end2.tv_sec - start2.tv_sec) * 1e6;
    time_taken2 = (time_taken2 + (end2.tv_usec - start2.tv_usec)) * 1e-6;

    std::cout << "Time taken: " << std::fixed << time_taken2 << std::setprecision(9) << "s\n\n";
    
    return 0;
}
