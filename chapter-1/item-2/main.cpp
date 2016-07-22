
#include <iostream>


/*
  auto もtemaplteの型推論と同一である
*/

int main() {
  // auto は Tを担い
  // 型指定子がParamTypeを担う
  auto x = 0;         // auto is int : 型指定子 is auto
  const auto cx = x;  // auto is int : 型指定子 is const auto
  const auto& rx = x; // auto is int : 型指定子 is const auto&
}
