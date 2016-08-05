
#include <iostream>


/*
  無効なレンプレートのインスタンス化を防ぐ
*/

int main() {
  /*
    暗黙的にintへ変換されるものがある
    コンパイル可能でも、意味をなさない恐れがある
  */

  // ラッキーナンバーか調べる
  // bool isLucky(int num) { return true; };
  if (isLucky('a')) {}
  if (isLucky(true)) {}
  if (isLucky(0.6)) {}

  
  /*
    上例はコンパイル不可とすべき
  */

  /* 
    char bool doubleを不可とする
    
    bool isLucky(char)   = delete;
    bool isLucky(bool)   = delete;
    bool isLucky(double) = delete;
  */

  if (isLucky('a')) {} // err...


  /*
    templateも同じくdeleteできる
  */
  template<typename T>
  void func(T num) {} // 数値のみ受け取りたい

  // charの受け取りを不可とする
  template<>
  void func<char>(char) = delete;
}
