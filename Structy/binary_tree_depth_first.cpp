#include <string>
#include <vector>
#include <iostream>

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
    // If the root given is null, then return
    if (root == nullptr) return;

    // Else, add the node value we just just encountered
    values.push_back(root->val);
    depthFirstValues(root->left, values);
    depthFirstValues(root->right, values);

}

std::vector<std::string> depthFirstValues(Node* root) {
  // This would work with recursion

  // I would need a place to store the values of the nodes I've visited
  std::vector<std::string> values;
  // Call the helper function
  depthFirstValues(root, values);
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
  for (const auto v: my_array){
    std::cout << v << std::endl;
  }
}