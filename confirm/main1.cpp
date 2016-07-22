
#include <iostream>


/*
  move関数はキャスト関数である
*/

void func(int& src) {
  std::cout << "ref" << std::endl;
}

void func(int&& src) {
  std::cout << "uref" << std::endl;
}

int main() {
  int x = 0;
  func(x);            // ref
  func(std::move(x)); // uref

  func(10);           // uref
}
