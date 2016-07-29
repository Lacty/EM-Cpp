
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


  /*
    波括弧を使用したコンストラクタの呼び出し
  */

  class Hoge;

  Hoge h(0); // 実引数を与えたコンストラクタの呼び出し
  Hoge h2(); // Hogeを返す関数を宣言しようとしている
  Hoge h3{}; // 実引数を与えずコンストラクタを呼び出す


  // std::initializer_listを使用したコンストラクタのないクラス
  class Hoge {
  public:
    Hoge(int x, bool flag);
    Hoge(int x, double y);
  };

  Hoge h(1, true);  // 1つ目のコンストラクタ
  Hoge h2{1, true}; // 1つ目のコンストラクタ
  Hoge h3(0, 0.5);  // 2つ目のコンストラクタ
  Hoge h4{0, 0.5};  // 2つ目のコンストラクタ

  /*
    std::initializer_listを使用したコンストラクタをもつクラス

    コンパイラから見て波括弧で囲った初期化子が
    std::initializer_listを用いたコンストラクタの呼び出しであると少しでもみなせば
    std::initializer_listを用いたコンストラクタを呼び出す
  */

  class Hoge {
  public:
    Hoge(int x, bool flag);
    Hoge(int x, double y);

    Hoge(std::initializer_list<long double> il);
  };

  Hoge h(0, true);  // 1つ目のコンストラクタ
  Hoge h2{0, true}; // std::initializer_listのコンストラクタが呼ばれる
                    // 0 と trueはlong doubleに変換される

  Hoge h3(4, 0.6);  // 2つ目のコンストラクタ
  Hoge h4{4, 0.6};  // std::initializer_listのコンストラクタが呼ばれる
}
