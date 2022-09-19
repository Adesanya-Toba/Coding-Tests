/**
 * @file ocado_interview.cpp
 * @author Toba Adesanya (toba@shyftpower.com)
 * @brief Factorial with map
 *        Create a way to avoid calculating the factorial for a number that
 *        been calculated before.
 * 
 * @version 0.1
 * @date 2022-09-19
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <iostream>
#include <map>

class Fact
{
    std::map<int, int> factMap;
public:
    Fact(){}
    int factorial(int x)
    {
        int num = x;
        if (num == 0) return 0;
        if (num <= 1) return 1;
        int fact = 1;
        
        // Check if number has been entered before
        if (factMap.find(x) != factMap.end())
        {
            std::cout << "Sike! You called me before here's your factorial \n";
            return factMap.at(x);
        }

        for (int i = 0; num != 0; i++)
        {
            fact *= num;
            num--;
        }
        factMap[x] = {fact};
        return fact;
    }
};

int main()
{
    Fact myFact;

    std::cout << myFact.factorial(6) << "\n";
    std::cout << myFact.factorial(10) << "\n";
    std::cout << myFact.factorial(6) << "\n";
    std::cout << myFact.factorial(10) << "\n";

    return 0;
}