
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


  // initializatio
  // autoは型を明示した変数宣言より利点が多いそうだ chapter-5参照

  auto x1 = 0; // type is int
  auto x2(0);  // 同上

  auto x3 = { 0 }; // type is std::initializer_list<int>

  // 2014/11 にC++ドラフト(N3922)に変更が加えられ
  // 上とは異なる意味になった
  // 最新のコンパイラなら対応してるかな？
  auto x4{ 0 }; // type is int

  // x5では２つの型推論が働いている
  // {}が使用されているのでx5の型はstd::initializer_list
  // std::inisializer_listはテンプレートなのでTの推論が必要となる
  // {}内の初期化子でTを推論する
  auto x5 = { 0, 3, 1 }; // x5's type is std::inisializer_list<int>
}
