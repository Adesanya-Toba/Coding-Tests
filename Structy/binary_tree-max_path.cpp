/**
 * @file binary_tree-max_path.cpp
 * @author Toba Adesanya (adesanyatoba@gmail.com)
 * @brief Write a function, maxPathSum, that takes in a pointer to the root of 
 *        a binary tree that contains number values. The function should return 
 *        the maximum sum of any root to leaf path within the tree.
 *  
 *        You may assume that the input tree is non-empty.
 * @version 0.1
 * @date 2023-03-30
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include <iostream>
#include <queue>
#include <limits>
#include <algorithm>

class Node {
  public:
    int val;
    Node* left;
    Node* right;


    Node(int initialVal) {
      val = initialVal;
      left = nullptr;
      right = nullptr;
    }
};

/**
 * @brief Time complexity: O(n), it depends only the number of nodes in the tree
 *        Space complexity: O(n), also depends only on the number of nodes
 * 
 *        For Both solutions.
 * 
 */

int maxPathSum(Node* root)
{
    // Recursive functions are the goto for path finding problems
    // Base case
    if(root == nullptr) return std::numeric_limits<int>::min();

    // Another base case: If the tree has only one node
    if (root->left == nullptr && root->right == nullptr){
        return root->val;
    }

    return root->val + (std::max({maxPathSum(root->left), maxPathSum(root->right)}));
}

int main()
{
    Node a(3);
    Node b(11);
    Node c(4);
    Node d(4);
    Node e(-2);
    Node f(1);

    a.left = &b;
    a.right = &c;
    b.left = &d;
    b.right = &e;
    c.right = &f;

    // std::cout << std::max({2,5,9}) << std::endl;
    int result = maxPathSum(&a);
    std::cout << "Max path is: " << result << std::endl;
    return 0;
}