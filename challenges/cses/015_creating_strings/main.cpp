#include "common.h"

UI fact(UI n) {
  if(n <= 1) {
    return 1;
  }
  return n * fact(n - 1);
}

void printNumPerms(const std::string &s, const std::array<UI, 26> &letterCnts) {
  auto n = fact(s.length());
  for(auto cnt : letterCnts) {
    n /= fact(cnt);
  }
  std::cout << n << "\n";
}

std::array<UI, 26> countLetters(const std::string &s) {
  std::array<UI, 26> letterCnts{};
  for(auto c : s) {
    letterCnts[c - 'a'] += 1;
  }
  return letterCnts;
}

void printPerms(std::string &output, std::array<UI, 26> &letterCnts) {
  bool recursed = false;
  for(size_t i = 0; i < letterCnts.size(); i++) {
    auto c = static_cast<char>(i + 'a');
    if(letterCnts[i] > 0) {
      output += c;
      letterCnts[i] -= 1;
      printPerms(output, letterCnts);
      letterCnts[i] += 1;
      output.pop_back();
      recursed = true;
    }
  }
  if(!recursed) {
    std::cout << output << "\n";
  }
}

void printPerms(std::array<UI, 26> letterCnts) {
  std::string output{};
    printPerms(output, letterCnts);
}

int main() {
    auto s = readLineT<std::string>();
    auto letterCnts = countLetters(s);
    printNumPerms(s, letterCnts);
    printPerms(letterCnts);
}
