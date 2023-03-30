/**
 * @file binary_tree-tree_includes.cpp
 * @author Toba Adesanya (adesanyatoba@gmail.com)
 * @brief Write a function, treeIncludes, that takes in
 *        a pointer to the root of a binary tree and a target value.
 *        The function should return a boolean indicating whether
 *        or not the value is contained in the tree.
 * @version 0.1
 * @date 2023-03-24
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include <iostream>
#include <string>
#include <queue>

class Node {
  public:
    std::string val;
    Node* left;
    Node* right;


    Node(std::string initialVal) {
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

bool treeIncludes(Node* root, std::string targetVal, bool& result)
{
    if (root == nullptr) return false;
    
    if (root->val == targetVal){
        result = true;
        return result;
    }

    treeIncludes(root->left, targetVal, result);
    treeIncludes(root->right, targetVal, result);
    return false;
}

bool treeIncludes(Node *root, std::string targetVal)
{
    // I want to try this recursively (using Depth first)
    bool result = false;
    treeIncludes(root, targetVal, result);

    return result;
}

// Using Breadth first (queues)
bool treeIncludesBreadthFirst(Node *root, std::string targetVal)
{
    std::queue<Node*> my_queue;

    if (root != nullptr){
        my_queue.push(root);
    }

    // Algo runs on while queue is not empty
    while (my_queue.size() > 0)
    {
        Node* current = my_queue.front(); // Get element at the top of the queue
        my_queue.pop();
        if (current->val == targetVal){
            // Evaluate and return if that's our target value
            return true;
        }

        if (current->left != nullptr){
            my_queue.push(current->left);
        }
        if (current->right != nullptr){
            my_queue.push(current->right);
        }
    }
    return false;

}

bool treeIncludesDFLessCode(Node *root, std::string targetVal)
{
    if (root == nullptr){
        return false;
    }

    if (root->val == targetVal){
        return true;
    }

    return treeIncludesDFLessCode(root->left, targetVal) || treeIncludesDFLessCode(root->right, targetVal);
}

int main()
{
    Node a("a");
    Node b("b");
    Node c("c");
    Node d("d");
    Node e("e");
    Node f("f");

    a.left = &b;
    a.right = &c;
    b.left = &d;
    b.right = &e;
    c.right = &f;

    std::cout << treeIncludesBreadthFirst(&a, "f");
    return 0;
}