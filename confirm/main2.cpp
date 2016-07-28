
#include <iostream>
#include <unordered_map>

int main() {
  std::unordered_map<std::string, int> m{
    { "hoge", 10 }
  };

  for (const std::unordered_map<std::string, int>& p : m ) {
    
  }
}
