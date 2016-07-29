
#include <iostream>


class Hoge {
public:
  Hoge(int x, bool b) { std::cout << "Hoge(int, bool)" << std::endl; }
  Hoge(int x, double d) { std::cout << "Hoge(int, double)" << std::endl; }
  Hoge(std::initializer_list<long double> il) { std::cout << "Hoge(std::initializer_list)" << std::endl; }
};

int main() {
  Hoge h1(0, true);
  Hoge h2{0, true};
  Hoge h3(5, 0.6);
  Hoge h4{5, 0.5};
}
