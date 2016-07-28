
#include <iostream>

/*
  明示的型宣言よりautoを優先する
*/

int main() {
  int  x1;      // 未初期化の恐れ
  auto x2;      // err, 初期化子がない
  auto x3 = 0;  // x3の値が確実に定義される


  // 32bit 64bit上の動作の違い
  std::vector<int> v;
  unsigned sz = v.size();

  /*
    v.size() は std::vector<int>::size_typeを返り型とする

    32bitの場合
    unsigned : 32bit
    v.size() : 32bit
    ともにサイズは同じだが

    64bitの場合
    unsigned : 32bit
    v.size() : 64bit
    となり環境によって不正な動作になりかねない
  */

  // autoを使えばstd::vector<int>::size_typeになってくれる
  auto sz = v.size();
}
