#include "MutantStack.hpp"

#include <iostream>

int main(void) {
  MutantStack<int> mt1 = MutantStack<int>();
  for (size_t i = 0; i < 10; i++)
    mt1.push(i);
  while (mt1.size() > 0) {
    std::cout << mt1.top() << std::endl;
    mt1.pop();
  }
  return (0);
}
