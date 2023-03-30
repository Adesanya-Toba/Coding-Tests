/**
 * @file binary_tree-tree_min_value.cpp
 * @author Toba Adesanya (adesanyatoba@gmail.com)
 * @brief Write a function, treeMinValue, that takes in a pointer
 *        to the root of a binary tree that contains number values. 
 *        The function should return the minimum value within the tree
 * 
 *        You may assume that the input tree is non-empty.
 * @version 0.1
 * @date 2023-03-30
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include <iostream>
#include <limits>
#include <algorithm>

class Node
{
public:
    int val;
    Node *left;
    Node *right;

    Node(int initialVal)
    {
        val = initialVal;
        left = nullptr;
        right = nullptr;
    }
};

void treeMinValue(Node *root, int& min_value)
{
    if(root == nullptr) return;

    if(root->val < min_value){
        min_value = root->val;
    }
    
    treeMinValue(root->left, min_value);
    treeMinValue(root->right, min_value);
}

int treeMinValue(Node *root)
{
    // This could work with depth first recursively because we want to evaluate all the nodes within the tree
    
    // You can store the greatest int
    int min_value = std::numeric_limits<int>::max();
    // Call a helper function to evaluate and collect minimum value
    treeMinValue(root, min_value);

    return min_value;
}

int treeMinValueLessCode(Node *root)
{
    // If the node we are given is empty, we return the int value as a default
    if(root == nullptr) return std::numeric_limits<int>::max();

    // Get the minValue in the left subtree
    // treeMinValueLessCode(root->left);
    // Get the minimum in the right
    // treeMinValueLessCode(root->right);

    // Compare the root val, left val and right val and then return
    // Using min from the algorithm library
    return std::min({root->val,
                    treeMinValueLessCode(root->left),
                    treeMinValueLessCode(root->right)});

}

int main()
{
    Node a(-3);
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
    
    int min = treeMinValue(&a);
    std::cout <<"Minimum value in tree: " << min << std::endl;
    return 0;
}
