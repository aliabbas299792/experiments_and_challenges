#include "common.h"

int main() {
  auto n = readLineT<int>();
  auto ns = readLineOfTs<int>(n);

  size_t sum{};
  int curr = 0;
  for(auto n : ns) {
    if(curr > n) {
      sum += curr - n;
    } else {
      curr = n;
    }
  }

  std::cout << sum << "\n";
}