
#include <iostream>


/*
template<typename T>
void func(ParamType src);

TとParamTypeの型は必ずしも同じではない

void func(const T src);
int x = 0;
func(x);

上の場合
T         : int
ParamType : const int
*/

template<typename T>
void func0(T src) {}

template<typename T>
void func1(T& src) {}

int main() {
  int x = 0;
  const int cx = x;
  const int& rx = x;


  // ParamTypeが参照でもポインタでもない場合は値渡し(コピー)となる
  
  func0(x);  // ParamType is int
  func0(cx); // ParamType is int
  func0(rx); // ParamType is int


  // ParamTypeが参照またはポインタで、ユニヴァーサル参照出ない場合
  // 引数の参照性は無視される
  
  func1(x);  // T is int : ParamType is int&
  func1(cx); // T is const int : ParamType is const int&
  func1(rx); // T is const int : ParamType is const int&
}
