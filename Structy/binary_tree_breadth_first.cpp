/**
 * @file binary_tree_breadth_first.cpp
 * @author Toba Adesanya (adesanyatoba@gmail.com)
 * @brief Implementing a binary tree using breadth first approach. This can be done by 
 *        using queues.
 *          
 *        Write a function, breadthFirstValues, that takes in a pointer to the root of a binary tree.
 *        The function should return a vector containing all values of the tree in breadth-first order.
 * 
 * @version 0.1
 * @date 2023-03-24
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include <iostream>
#include <vector>
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
 *        There is no recursive solution for Breadth-first order.
 * 
 * @param root 
 * @return std::vector<std::string> 
 */
std::vector<std::string> breadthFirstValues(Node *root)
{
    // Create our return values vector
    std::vector<std::string> values;

    // Create our queue
    std::queue<Node *> my_queue;

    // Check if the root Node is not empty and push into the queue
    if (root != nullptr)
    {
      my_queue.push(root);
    }

    // The algorithm runs by checking if the queue is empty
    while(my_queue.empty() != true)
    {
        // Remove the front item from the queue to evaluate it
        Node* current = my_queue.front();
        my_queue.pop();

        // Add the current node to the values vector
        values.push_back(current->val);

        // Check if the current node has children
        if(current->left != nullptr){
            my_queue.push(current->left);
        }
        if(current->right != nullptr){
            my_queue.push(current->right);
        }
    }

    return values;
}

int main()
{
    Node a("a");
    Node b("b");
    Node c("c");
    Node d("d");
    Node e("e");
    Node f("f");

    std::vector<std::string> my_array;
    a.left = &b;
    a.right = &c;
    b.left = &d;
    b.right = &e;
    c.right = &f;

    my_array = breadthFirstValues(&a);

    for (const auto v : my_array)
    {
        std::cout << v << std::endl;
    }
}