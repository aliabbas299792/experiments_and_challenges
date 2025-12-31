#include "common.h"

int main() {
  auto n = readLineT<I>();
  constexpr const I mod = 1'000'000'000 + 7;
  I num = 1;
  while(n != 0) {
    if(n > 32) {
      n -= 32;
      num %= mod;
      num <<= 32;
    } else {
      num %= mod;
      num <<= n;
      n = 0;
    }
  }
  std::cout << num % mod << "\n";
}