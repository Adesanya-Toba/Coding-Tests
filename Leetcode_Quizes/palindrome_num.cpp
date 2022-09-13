/**
 * @file    palindrome_num.cpp
 * @author  Toba Adesanya 
 * @brief   Given an integer x, return true if x is palindrome integer.
 *          An integer is a palindrome when it reads the same backward as forward.
 * 
 *          For example, 121 is a palindrome while 123 is not.
 * 
 * @version 0.1
 * @date 2022-09-02
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <iostream>
using namespace std;

class Solution {
public:
    /**
     * @brief If we don't want to use the convert to string approach which would take up non-constant
     *        space for creating the String, the other approach we could attempt is to reverse the integer
     *        and compare it to itself.
     * 
     *        However, to avoid going over int.MAX (if we were given a number that is not a palindrome), we could
     *        instead of reversing the entire int, we just reverse half cos if it's a palindrome, the first half would
     *        be equal to the reversed half. E.g. 1221, reversing the both half would give 12, which is equal to the top
     *        half.
     * 
     *        We know how to reverse an int by doing 1221 % 10 = 1, then 1221/10 = 122. From here, we can get the next digit
     *        122 % 10 = 2, then to reverse, we simply multiply the first digit by 10 and add the penultimate digit i.e.
     *        1 * 10 + 2 = 12; which is equal to the top half.
     * 
     *        Now the question is, how do we know that we've reached the half of the number?
     * 
     *        Since we divided the number by 10, and multiplied the reversed number by 10,
     *        when the original number is less than the reversed number, it means we've processed half of the number digits.
     * 
     * @param x 
     * @return true 
     * @return false 
     */
    bool isPalindrome(int x) 
    {
        // If x is negative return false or if the number ends in a zero, because only 0 is a palindrome that ends in 0
        if (x < 0 || (x % 10 == 0 && x != 0)) return false;

        int reversed_num = 0;

        while (x > reversed_num)
        {
            reversed_num = reversed_num * 10 + x % 10;
            x = x / 10;
        }

        // When the length is an odd number, we can get rid of the middle digit by revertedNumber/10
        // For example when the input is 12321, at the end of the while loop we get x = 12, revertedNumber = 123,
        // since the middle digit doesn't matter in palidrome(it will always equal to itself), we can simply get rid of it.

        return (x == reversed_num) || (x == reversed_num / 10);
    }
};

int main()
{
    Solution test1;

    cout << test1.isPalindrome(1) << endl;

    return 0;
}
