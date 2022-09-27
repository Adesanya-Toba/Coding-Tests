#include <iostream>
#include <vector>
#include <limits>

float maxValue(std::vector<float> numbers) {
  float max = -std::numeric_limits<float>::infinity();
  for(auto& i : numbers)
  {
    if (i > max) max = i;
  }
  return max;
}


int main() {
  // this function behaves as `main()` for the 'run' command
  // you may sandbox in this function, but should not remove it
  std::vector<float> my_vec = {1.2, 3, 6, 9, -2, 8};
  std::cout << "Max number is: " << maxValue(my_vec) << std::endl;

  return 0;
}
