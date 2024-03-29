/**
 * @file binary_tree_depth_first.cpp
 * @author Toba Adesanya (adesanyatoba@gmail.com)
 * @brief Implementing a Binary tree using depth first approach. This can be
 *        done by using a stack data structure or using the implicit recursive call stack.
 * 
 *        Write a function, depthFirstValues, that takes in a pointer to the root of a binary tree
 *        The function should return a vector containing all values of the tree in depth-first order.
 * @version 0.1
 * @date 2023-03-24
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include <string>
#include <vector>
#include <iostream>
#include <stack>

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

// Creating a recursive helper function
void depthFirstValues(Node* root, std::vector<std::string> &values)
{
    // If the root/node given is null, then return
    if (root == nullptr) return;

    // Else, add the node value we just just encountered to the vector
    values.push_back(root->val);
    depthFirstValues(root->left, values);
    depthFirstValues(root->right, values);

}

/**
 * @brief Time complexity: O(n), it depends only the number of nodes in the tree
 *        Space complexity: O(n), also depends only on the number of nodes
 * 
 * @param root 
 * @return std::vector<std::string> 
 */
std::vector<std::string> depthFirstValues(Node* root) {
  // This would work with recursion

  // I would need a place to store the values of the nodes I've visited
  std::vector<std::string> values;
  // Call the helper function
  depthFirstValues(root, values);
  return values;
}

std::vector<std::string> depthFirstValuesIterative(Node* root) {
  // Here we would be using a stack
  std::stack<Node*> my_stack;

  std::vector<std::string> values;

  if (root == nullptr) return values;

  // Add the root node to the stack
  my_stack.push(root);
  
  while(my_stack.size() > 0)
  {
    Node* current = my_stack.top(); // save the topmost element temporarily
    values.push_back(current->val); // push its value to the vector
    my_stack.pop(); // remove it from the stack

    if(current->right != nullptr) // check if it has any child nodes. If it does, put it on the stack
    {
      my_stack.push(current->right);
    }
    if(current->left != nullptr)
    {
      my_stack.push(current->left);
    }

    // Repeat until we get to leaf nodes (i.e. nodes without children), then stack gets empty and we can return
  }
  return values;
}



int main() {
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
  
  my_array = depthFirstValues(&a);

  my_array = depthFirstValuesIterative(&a);
  for (const auto v: my_array){
    std::cout << v << std::endl;
  }

  return 0;
}