/**
 * @file three_sum.cpp
 * @author Toba Adesanya (adesanyatoba@gmail.com)
 * @brief Given an integer array nums, return all the triplets 
 *        [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, 
 *        and nums[i] + nums[j] + nums[k] == 0.
 * 
 *        Notice that the solution set must not contain duplicate triplets.
 * @version 0.1
 * @date 2022-10-06
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <bits/stdc++.h>
#include <iostream>

class Solution {
public:
    /**
     * @brief Time: O(N^2)
     *        Space: O(N)
     */
    std::vector<std::vector<int>> threeSum(std::vector<int>& nums) {
        
        // Create result vector
        std::vector<std::vector<int>> result;
        
        // First sort the array in ascending order
        sort(nums.begin(), nums.end());
        for (auto & v: nums) std::cout << v << " ";
        std::cout << "\n";
        
        // Create for loop
        for (int i = 0; i < nums.size(); i++)
        {
            if (i == 0 || (i > 0 && nums[i] != nums[i - 1])) // becuase we can't have dupicate triplets, 
            // i.e. nums[i] and nums[i-1] will give duplicate triplets
            {
                int lptr = i + 1;
                int rptr = nums.size() - 1;
                while (lptr < rptr)
                {
                    int sum = nums[i] + nums[lptr] + nums[rptr];
                    if (sum < 0) lptr++;
                    else if (sum > 0) rptr--;
                    else if (sum == 0)
                    {
                        std::vector<int> res;
                        // res.reserve(3);
                        res.push_back(nums[i]);
                        res.push_back(nums[lptr]);
                        res.push_back(nums[rptr]);

                        result.push_back(res);
                        lptr++;
                        rptr--;
                    }
                }
            }
        }
        return result;
    }
};

std::ostream& operator<<(std::ostream& out, std::vector<std::vector<int>> v)
{
    for(auto& m : v){
        out << "[";
        for(auto& j : m){
            out << j << ", ";
        }
        out << "]";
    }
    return out;
}

int main()
{
    Solution test1;

    std::vector<int> v {-1,0,1,2,-1,-4};

    std::cout << "Possible triplets are: " << test1.threeSum(v) << " ";
    std::cout << std::endl;


    // test1.threeSum(v);
    return 0;
}
