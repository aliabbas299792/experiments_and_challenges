#include "common.h"

Vec<std::string> gray(UI n) {
  Vec<std::string> codes{ "0", "1" };

  for(UI i = 1; i < n; i++) {
    Vec<std::string> newCodes{};
    newCodes.reserve(codes.size() * 2);

    for(I j = 0; j < static_cast<I>(codes.size()); j++) {
      newCodes.push_back("0" + codes[j]);
    }
    for(I j = static_cast<I>(codes.size()) - 1; j >= 0; j--) {
      newCodes.push_back("1" + codes[j]);
    }
    codes = std::move(newCodes);
  }

  return codes;
}

int main() {
  auto n = readLineT<UI>();
  auto codes = gray(n);
  for(auto c : codes) {
    std::cout << c << "\n";
  }
}