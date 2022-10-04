/**
 * @file tribonacci.cpp
 * @author Toba Adesanya (adesanyatoba@gmail.com)
 * @brief Write a function tribonacci that takes in a number argument, n,
 *        and returns the n-th number of the Tribonacci sequence.
 *        The 0-th and 1-st numbers of the sequence are both 0.
 *        The 2-nd number of the sequence is 1.
 *
 *        To generate further numbers of the sequence, calculate the sum of previous three numbers.
 *
 * @version 0.1
 * @date 2022-10-04
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <iostream>
#include <unordered_map>

int tribonacci(int n, std::unordered_map<int, int> &trib)
{
    if(trib.count(n) > 1){
        // Key exists. Return value
        return trib[n];
    }
    if (n < 0) return 0;
    if (n < 2) return 0;
    if (n == 2) return 1;

    trib[n] = tribonacci(n-1, trib) + tribonacci(n-2, trib) + tribonacci(n-3, trib);
    return trib[n];
}

int tribonacci(int n)
{
    std::unordered_map<int, int> trib;
    return tribonacci(n, trib);
}

int main()
{
    // this function behaves as `main()` for the 'run' command
    // you may sandbox in this function, but should not remove it
    int i = 5;
    std::cout << "Trib of " << i << ": " << tribonacci(i) << std::endl;
    return 0;
}
