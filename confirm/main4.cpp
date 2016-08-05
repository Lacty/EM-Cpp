
#include <iostream>


enum UserInfoFields { uiName, uiMail, uiId };

using UserInfo = std::tuple<std::string, // user name
                            std::string, // mail address
                            std::size_t>;// id

int main() {
  UserInfo user({"hoge", "piyo@gmail.com", 5});

  auto mail = std::get<uiMail>(user);

  std::cout << mail << std::endl;
}
