#include "common.h"

void addReps(std::string &s, char c, int n) {
  for(int i = 0; i < n; i++) {
    s += c;
  }
}

int main() {
  auto s = readLineT<std::string>();

  std::array<UI, 26> letterCount{};
  constexpr const char A = 'A';
  for(auto c : s) {
    letterCount[c - A] += 1;
  }

  bool oddSeen{};
  char centre{};
  std::string prefix{};
  for(size_t i = 0; i < letterCount.size(); i++) {
    char letter = i + A;
    auto &cnt = letterCount[i];
    if(cnt % 2 == 1) {
      if(oddSeen) {
        std::cout << "NO SOLUTION\n";
        return 0;
      }
      oddSeen = true;
      cnt -= 1;
      centre = letter;
      addReps(prefix, letter, cnt / 2);
    } else {
      addReps(prefix, letter, cnt / 2);
    }
  }

  auto suffix = prefix;
  std::reverse(suffix.begin(), suffix.end());
  
  if(centre != 0) {
    prefix += centre;
  }

  auto out = prefix + suffix;
  std::cout << out << "\n";
}