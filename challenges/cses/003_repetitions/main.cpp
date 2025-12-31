#include <iostream>
#include <string>

int main() {
  std::string s{};
  std::cin >> s;

  char curr = s[0];
  uint64_t max = 1;
  uint64_t l = 0;
  uint64_t r = 1;

  while(r < s.length()) {
    if(s[r] == curr) {
      r += 1;
    } else {
      max = std::max(r - l, max);
      curr = s[r];
      l = r;
      r += 1;
    }
  }

  max = std::max(r - l, max);

  std::cout << max << std::endl;
}