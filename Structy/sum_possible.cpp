/**
 * @file sum_possible.cpp
 * @author Toba Adesanya (adesanyatoba@gmail.com)
 * @brief Write a function sumPossible that takes in an amount and
 *        a vector of positive numbers. The function should return a 
 *        boolean indicating whether or not it is possible to create 
 *        the amount by summing numbers of the vector.
 * 
 *        You may reuse numbers of the vector as many times as necessary.
 *        You may assume that the target amount is non-negative.
 * 
 * @version 0.1
 * @date 2022-10-05
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>

/******** Stucty's  solution ************/
// Time: O(a*n), Space: O(a)
// a = amount, n = length of numbers

bool sumPossible(int amount, std::vector<int> numbers, std::unordered_map<int, int> &memo) {
  if (memo.count(amount) > 0) {
    return memo[amount];
  }
  
  if (amount == 0) {
    return true;
  }
  if (amount < 0) {
    return false;
  }
  
  for (int num : numbers) {
    if (sumPossible(amount - num, numbers, memo)) {
      memo[amount] = true;
      return true;
    }
  }
  
  memo[amount] = false;
  return false;
}

bool sumPossible(int amount, std::vector<int> numbers) {
  std::unordered_map<int, int> memo;
  return sumPossible(amount, numbers, memo);
}


/******** My solution ****************/
// Time: O(n), Space: O(n)

bool sumPossible(int amount, std::vector<int> numbers) {
  // Loop through the vector once and check if the 
  // modulus of the amount is equal to zero or 
  // is a member of the vector (i.e. amount % numbers[i] == 0 || numbers[i])
  
  
  // Handle edge cases
  // If amount is 0, return true because you can get that sum by not taking any element in the vector
  if(amount == 0) return true;

  // If vector is empty
  if (numbers.empty() && amount != 0) return false;
  
  // Copy the vector elements into a map
  std::map<int, int> my_map;
  int i = 0;
  for(auto& v : numbers)
  {
    my_map[v] = i++;
  }
  
  // Now check if the modulus of each vector element against the amount is 
  // a member or 0
  int mod = 0;
  for(auto& v : numbers)
  {
    mod = amount % v;
    if(my_map.count(mod) > 0 || mod == 0){
      return true;
    }
  }
  return false;
}


int main()
{
    // this function behaves as `main()` for the 'run' command
    // you may sandbox in this function, but should not remove it
    std::vector<int> vec;
    vec.reserve(3);
    vec.assign({5,12,4});

    std::cout << sumPossible(8, vec) << std::endl;
    vec.clear();

    vec.assign({6,2,10,19});
    std::cout << sumPossible(15, vec) << std::endl;
    
    return 0;
}