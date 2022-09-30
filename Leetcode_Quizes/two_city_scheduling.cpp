/**
 * @file two_city_scheduling.cpp
 * @author Toba Adesanya (adesanyatoba@gmail.com)
 * @brief Q1029 -Two City Scheduling  
 *        A company is planning to interview 2n people. Given the array costs 
 *        where costs[i] = [aCosti, bCosti], the cost of flying the ith person 
 *        to city a is aCosti, and the cost of flying the ith person to city b is bCosti.
 * 
 *        Return the minimum cost to fly every person to a city such that exactly n people arrive in each city.
 * 
 * @version 0.1
 * @date 2022-09-30
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <iostream>
#include <bits/stdc++.h>
#include <vector>

using namespace std;

bool compare(vector<int> &a, vector<int> &b)
{
    int diffA = *(a.begin()) - *(a.end() -1);
    int diffB = *(b.begin()) - *(b.end() -1);
    return abs(diffA) > abs(diffB);
}

class Solution {
public:
    /**
     * @brief Time complexity is O(NlogN) + O(N) - cos of the sorting looping through the array
     *        Space complexity is O(1) - I don't copy the vector and only return the sum
     */
    int twoCitySchedCost(vector<vector<int>>& costs)
    {
        // Sort the array in decreasing order of their differences, since we want to optimize for cost   
        std::sort(costs.begin(), costs.end(), compare);
        
        // Now that the vector is sorted, we want to start put people in cities
        int sum = 0, cnt_A, cnt_B, num; 
        cnt_A = cnt_B = 0;
        num = costs.size() / 2;
        
        for (const auto& v : costs)
        {
            if (cnt_A == num){
                // Send to city B
                sum += v[1];
                cnt_B++;
            }
            else if (cnt_B == num){
                // Send to city A
                sum += v[0];
                cnt_A++;
            }
            else if(v[0] < v[1]){
                // For city A
                sum += v[0];
                cnt_A++;
            }
            else{
                // For city B
                sum += v[1];
                cnt_B++;
            }
        }
        return sum;
    }
};

int main()
{
    Solution test1;
    vector<vector<int>> v = {{10,20},{30,200},{400,50},{30,20}};

    cout << "Affordable sum is: " << test1.twoCitySchedCost(v) << endl;

    return 1;
}