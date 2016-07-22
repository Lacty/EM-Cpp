
#include <iostream>
#include <typeinfo>

/*
  auto もtemaplteの型推論と同一である
*/

void func(int i, float f) {}

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

  
  // 配列および関数名は非参照型指定子のポインタに成り下がる
  
  const char name[] = "I'm Yanai"; // name is const char[10]
  
  auto arr1 = name; // arr1 is const char*
  auto& arr2 = name; // arr2 is const char(&)[10]
  
  auto func1 = func; // func1 is void (*)(int, float)
  auto func2 = func; // func2 is void (&)(int, float)
}
