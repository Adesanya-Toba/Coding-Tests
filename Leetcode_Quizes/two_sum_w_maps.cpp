/**
 * @file two_sum_w_maps.cpp
 * @author Toba Adesanya (adesanyatoba@gmail.com)
 * @brief Reducing time complexity to O(n) and increase space complexity to
 *        O(n)
 * 
 * @version 0.1
 * @date 2022-09-27
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
       // Save the vector in a map, using the value as the map keys
        // and the vector index as the map's values
        map<int, int> my_map;
        for (int i = 0; i < nums.size(); i++)
        {
            // my_map.insert(pair<int, int>(nums[i], i));
            // Or
            my_map[nums[i]] = i;
        }

        for (int i = 0; i < nums.size(); i++)
        {
            int complement = target - nums[i];
            // Check if the complement exists in the map
            if (my_map.find(complement) != my_map.end())
            {
                // Confirm that the compelement[value] is not the same as the index
                if (my_map.at(complement) != i){
                    vector<int> result;
                    result.push_back(i);
                    result.push_back(my_map.at(complement));
                    cout << "[" << result[0] << "," << result[1] << "]" << endl;
                    return result;
                }
            }
        }
        return vector<int>();
    }

    vector<int> twoSum_onePass(vector<int>& nums, int target)
    {
        map<int, int> my_map;
        for (int i = 0; i < nums.size(); i++)
        {
            int complement = target - nums[i];
            // Check if complement exists in map
            if(my_map.find(complement) != my_map.end())
            {
                vector<int> result;
                result.push_back(i);
                result.push_back(my_map.at(complement));
                cout << "[" << result[0] << "," << result[1] << "]" << endl;
                return result;
            }
            // If it doesn't, put it in the map
            my_map[nums[i]] = i;
        }
        return vector<int>();
    }
};

int main()
{
    Solution test1;
    vector<int> nums = {3,3};
    int target = 6;

    vector<int> nums2 = {2,7,11,15};
    int target2 = 18;

    test1.twoSum(nums, target);
    test1.twoSum_onePass(nums, target);
    cout << "\n";
    
    test1.twoSum(nums2, target2);
    test1.twoSum_onePass(nums2, target2);

    return 0;
}