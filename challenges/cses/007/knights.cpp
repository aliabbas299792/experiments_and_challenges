#include "common.h"

uint64_t nonAttackingCombos(uint64_t n) {
  auto n2 = n*n;
  auto total = n2 * (n2 - 1);
  return total / 2 - 4*(n - 1)*(n - 2);
}

int main() {
  auto n = readLineT<uint64_t>();
  for(uint64_t i = 1; i <= n; i++) {
    std::cout << nonAttackingCombos(i) << "\n";
  }
}