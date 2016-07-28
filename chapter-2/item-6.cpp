
#include <iostream>
#include <vector>


/*
  std::vector<bool>の挙動
  この項目は動作確認ができなかったので曖昧なメモとなる
*/

int main() {
  /*
    std::vector<bool>は概念的にboolを所持しているが
    operator[]はコンテナ要素の参照を返さない

    operator[]が返すのはstd::vector<bool>::referenceである
    std::vector<bool>::referenceは
    std::vector<bool>の要素であるboolを1ビットで表現する

    std::vectorのoperator[]はT&を返すのとを期待されるが
    C++ではビットの参照は認められていない

    std::vcetor<bool>のoperater[]はbool&であるかのように振る舞うオブジェクトを返す
  */

  // boolへの暗黙的変換
  // std::vector<bool> func();
  bool b = func()[2];

  // autoを使う場合は注意
  auto b2 = func()[3];

  /*
    func()[3]はstd::vector<bool>のoperator[]を実行し
    operator[]はstd::vector<bool>::referenceを返し
    autoはstd::vector<bool>::referenceとなる

    std::vector<bool>::referenceの動作は実装依存
  */


  /*
    一般的に、「ユーザーに意識させない(invisible)」プロクシクラスはautoとうまく協調動作しない
    この種のプロクシクラスは、ライフタイムを1文と想定して設計されているためである
  */
  
  // 次のコードは避けるべきである
  auto someVar = 'invisible' proxy class type;
                 // ユーザーに意識させないプロクシクラス型の式

  
  // autoの使用をあきらめることはない
  // 問題は推論してほしい型を推論しないことが問題である

  // 推論する型を強制する
  auto b = static_cast<bool>(func()[2]);

  /*
    func()[3]は今まで通りstd::vector<bool>::referenceを返すが
    それをboolに変換しており
    autoはそれをbの型と推論する

    std::vector<bool>::referenceがboolへの変換を実行する
    この変換の一環として
    有効なポインタの参照がかえる
  */
}
