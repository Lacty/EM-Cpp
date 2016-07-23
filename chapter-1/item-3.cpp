
#include <iostream>
#include <vector>


/*
  decltype
  与えた名前の型を返す

  int x = 0;     // decltype(x) is int

  struct Point { // decltype(Point::x) is int
    int x, int y
  };

  bool func(const Point& p); // decltype(func) is bool
                             // decltype(p) is const Point&
*/

int main() {
  // 要素型をTとするコンテナのoperator []は
  // 通常T&を返す

  std::vector<int> v;
  if (v[0] == 0) {}   // decltype(v[0]) is int&


  /*
    コンテナによって返す型が異なるが
    decltypeを使用することで安易に戻り型を求めることができる

    tempalte<typename Container, typename Index>
    auto func(Container& c, Index i)
      -> decltype(c[i])
    {
      return c[i];
    }

    このautoは型推論には関与せず
    ->後の戻り型を置換する
  */

  /*
    C++14からはすべてのラムダの戻り型、すべての関数戻り型を推論できる

    template<typename Container, typename Index>
    auto func(Container& c, Index i)
    {
      return c[i];
    }

    しかし
    戻り型をautoとした場合
    コンパイラはテンプレートの型推論を実行するため
    初期化式の参照性は無視される

    コンテナの[]がT&を返すのならば
    Tを返すことになる

    std::vector<int> v;
    func(v, 0) = 10;    // funcはv[0]を返し10を代入しようとするが
                        // コンパイルできない

    autoによる推論でfuncからの返り型がint(右辺値)になる
    右辺値への代入はにとめられないためエラーとなる
  */

  /*
    C++14からはdecltype(auto)が使用可能になる
    autoは型推論を示し
    decltypeはdecltypeの規則を用いるという意味となる
    (参照性を無くすなどの動作が入らない

    tempalte<typename Container, typename Index>
    decltype(auto) func(Container& c, Index i)
    {
      return c[i];
    }

    Point p;
    const Point& cp = p;
    
    auto pos1 = cp; // autoの型推論にて pos1 is Point

    decltype(auto) pos2 = cp; // decltypeの型推論にて pos2 is const Point&
  */

  /*
    Container& c
    これは
    func(v, 0) = 0;
    のように返り値をいじれるようにするため参照にしてあるが

    このままだと右辺値のコンテナが実引数に渡せない
    左辺値参照に右辺値をバインドできないためである

    これを回避するためには
    左辺値にも右辺値にもバインド可能な参照仮引数を受け付けるように宣言しなければならない

    template<typename Container, typename Index>
    decltype(auto) func(Container&& c, Index i);
  */

  /*
    C++14
    tempalte<typename Container, typename Index>
    decltype(auto) func(Container&& c, Index i)
    {
      return std::forward<Container>(c)[i];
    }

    C++11
    tempalte<typename Container, typename Index>
    auto func(Container&& c, Index i)
      -> decltype(std::forward<Container>(c)[i])
    {
      return std::forward<Container>(c)[i];
    }

    std::forwardについてはitem-25参照
  */
}
