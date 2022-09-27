/**
 * @file is_prime.cpp
 * @author Toba Adesanya (adesanyatoba@gmail.com)
 * @brief Determine if n is a prime number or not.
 *        Prime numbers have two factors: 1 and itself, hence 1 is not a prime
 *        number because 1 and itself are not two exclusive facts (i.e. 1 is the
 *        same as itself).
 * @version 0.1
 * @date 2022-09-27
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <iostream>
#include <cmath>

bool isPrime(int n){
    if (n < 2) return false; // 1 is not a prime

    for (int i = 2; i <= sqrt(n); i++)
    {
        if (n % i == 0) return false;
    }
    return true;
}

int main() {
  // this function behaves as `main()` for the 'run' command
  // you may sandbox in this function, but should not remove it
  int n = 97;
  std::cout << n <<" is a prime number? " << isPrime(n) << std::endl;
  return 0;
}
