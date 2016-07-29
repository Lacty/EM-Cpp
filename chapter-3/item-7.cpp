
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

  /*
    波括弧は、非スタティックなメンバ変数のデフォルト値の指定にも使える

    class Hoge {
      int x{ 0 }; // ok
      int y = 0;  // ok
      int z(0);   // err
    };
  */

  /*
    コピー不可なオブジェクト(std::atomic)は波括弧、丸括弧で初期化可能だが
    [=]での初期化はできない
  */

  std::atomic<int> aa{ 0 }; // ok
  std::atomic<int> ab(0);   // ok
  std::atomic<int> ac = 0;  // err
}
