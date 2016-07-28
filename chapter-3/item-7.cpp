
#include <iostream>


/*
  C++11では初期化の統一技法(波括弧)を導入している
  どの場面でも使用でき、どんな初期化も表現できる
*/

int main() {
  // 制度の落ちる初期化は不可
  double x{0}, y{1}, z{2};
  int sum{ x + y + z }; // err

  int sum(x + y + z);   // ok
  int sum = x + y + z;  // ok
}
