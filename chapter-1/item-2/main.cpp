
#include <iostream>
#include <typeinfo>

/*
  auto もtemaplteの型推論と同一である
*/

int main() {
  // auto は Tを担い
  // 型指定子がParamTypeを担う
  auto x = 0;         // auto is int : 型指定子 is auto
  const auto cx = x;  // auto is int : 型指定子 is const auto
  const auto& rx = x; // auto is int : 型指定子 is const auto&

  auto&& uref1 = x;  // uref1 is int&
  auto&& uref2 = cx; // uref2 is const int&
  auto&& uref3 = rx; // uref3 is const int&
  auto&& uref4 = 0;  // uref4 is int&&
}
