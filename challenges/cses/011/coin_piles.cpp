#include "common.h"

bool canBeEmptied(int64_t pile1, int64_t pile2) {
  if(pile1 > pile2) {
    std::swap(pile1, pile2);
  }
  
  if(pile1 < pile2/2) {
    return false;
  }

  return (pile1 + pile2) % 3 == 0;
}

int main() {
  auto n = readLineT<int64_t>();
  for(int i = 0; i < n; i++) {
    auto nums = readLineOfTs<int64_t>();
    auto pile1 = nums[0], pile2 = nums[1];
    std::cout << (canBeEmptied(pile1, pile2) ? "YES" : "NO") << "\n";
  }
}