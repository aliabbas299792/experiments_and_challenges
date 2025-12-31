#include "common.h"

void hanoiMove(uint8_t from, uint8_t to, uint8_t other, uint8_t level) {
  if(level == 1) {
    std::cout << static_cast<int>(from) << " " << static_cast<int>(to) << "\n";
  } else {
    hanoiMove(from, other, to, level-1);
    hanoiMove(from, to, other, 1);
    hanoiMove(other, to, from, level-1);
  }
}

void hanoi(uint8_t n) {
  hanoiMove(1, 3, 2, n);
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  auto n = readLineT<UI>();
  std::cout << (1 << n) - 1 << "\n";
  hanoi(n);
}
