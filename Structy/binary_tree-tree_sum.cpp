/**
 * @file binary_tree-tree_sum.cpp
 * @author Toba Adesanya (adesanyatoba@gmail.com)
 * @brief Write a function, treeSum, that takes in a pointer to the root 
 *        of a binary tree that contains number values. The function should
 *        return the total sum of all values in the tree.
 * @version 0.1
 * @date 2023-03-24
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include <iostream>
#include <queue>

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

/**
 * @brief Time complexity: O(n), it depends only the number of nodes in the tree
 *        Space complexity: O(n), also depends only on the number of nodes
 * 
 *        For Both solutions.
 * 
 */



/**
 * @brief Using Breadth first
 * 
 * @param root 
 * @param result 
 */
int treeSumBreadthFirst(Node* root)
{
    int result = 0;
    std::queue<Node*> my_queue;

    // The algorithm runs when the queue is not empty
    if (root != nullptr){
        my_queue.push(root);
    }
    
    while(my_queue.size() > 0)
    {
        Node* current = my_queue.front();
        my_queue.pop();

        result += current->val;
        if (current->left != nullptr){
            my_queue.push(current->left);
        }
        if (current->right != nullptr){
            my_queue.push(current->right);
        }
    }
    return result;
}


// The recursive helper function
void treeSumDepthFirst(Node* root, int& result)
{
    // Implement the depth first algorithm
    if(root == nullptr) return;

    result += root->val;

    treeSumDepthFirst(root->left, result);
    treeSumDepthFirst(root->right, result);
}

int treeSumDepthFirst(Node *root)
{
    // I would like to use recursion (i.e. Depth first) to solve this

    // Create the result variable
    int result = 0;

    // Call the recursive helper function
    treeSumDepthFirst(root, result);
    return result;
}

int treeSumDepthFirstLessCode(Node* root)
{
    if(root == nullptr){
        return 0;
    }
    return root->val + treeSumDepthFirstLessCode(root->left) + treeSumDepthFirstLessCode(root->right);
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

    int result = treeSumDepthFirstLessCode(&a);
    std::cout << "Sum of the binary tree using depth first: " << result << std::endl;

    result = treeSumBreadthFirst(&a);
    std::cout << "Sum of the binary tree using breadth first: " << result << std::endl;
    return 0;
}