/**
 * @file    two_sum.cpp
 * @author  Toba Adesanya
 * @brief   Given an array of integers nums and an integer target,
 *          return indices of the two numbers such that they add up to target.
 * 
 *          Input: nums = [2,7,11,15], target = 9 
 *          Output: [0,1]
 *          Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].
 * 
 * @version 0.1
 * @date 2022-08-31
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> twoSumz(vector<int>& nums, int target) 
    {
        // Create a copy of vector and sort the contents
        vector <int> my_vec = nums;
        sort(my_vec.begin(), my_vec.end());

        vector<int> result(2);

        cout << "HELLO LEETCODE!"<< endl;

        for (int i = 0 ; i < my_vec.size(); i++)
        {
            // If my_vec[i] > target, return
            if(my_vec[i] > target) return (vector<int>)0;

            for(int j = 1; j < my_vec.size(); j++)
            {
                if ((my_vec[i] + my_vec[j]) == target)
                {
                    // Get the actual digits and find where they are in the original array.
                    vector<int>::iterator iter;

                    iter = find(nums.begin(), nums.end(), my_vec[i]);
                    result[0] = iter - nums.begin();

                    iter = find(nums.begin(), nums.end(), my_vec[j]);
                    result[1] = iter - nums.begin();

                    cout << "[" << result[0] << "," << result[1] << "]" << endl;
                    return result;
                }
            }
        }
        return result;  
    }


    vector<int> twoSum(vector<int>& nums, int target) 
    {
       /**
        * You should never an add an index to itself so that means all you
        * really need for a 4 element array, for example;
        * 1,2   1,3     1,4
        *       2,3     2,4
        *               3,4
        * The sum would definitely be among these, so all you need to do is 
        * check all of these.
        * 
        * Even though this runs through only half of the array, it still takes 
        * O(N^2) time and O(1) space.
        * 
        * After faster way O(n), which would use more space O(n) would be a hashmap, but
        * I haven't learnt that yet. The basic idea though is to save the array in 
        * hash map using the values as the key and the index as the value.
        *   key         : value
        *   array value : array index
        * Then you want to do "target - nums[i]" and check if that value exists in the hash map
        * if it does, just return i and the value's key.
        * 
        */
        for (int i = 0; i < nums.size(); i++)
        {
            for(int j = i+1; j < nums.size(); j++)
            {
                if (nums[i] + nums[j] == target)
                {
                    vector<int> result;
                    result.push_back(i);
                    result.push_back(j);
                    cout << "[" << result[0] << "," << result[1] << "]" << endl;
                    return result;
                }
            }
        }
        return vector<int>();
    }
};


int main()
{
    Solution test1;
    vector<int> nums = {3,3};
    int target = 6;

    test1.twoSum(nums, target);

    return 0;
}
