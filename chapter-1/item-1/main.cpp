
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
void func(T src) {}

int main() {
  {
    // Tが参照でもポインタでもない場合は値渡し(コピー)となる
    int x = 0;
    const int cx = x;
    const int& rx = x;
    func(x);  // ParamType is int
    func(cx); // ParamType is int
    func(rx); // ParamType is int
  }
}
