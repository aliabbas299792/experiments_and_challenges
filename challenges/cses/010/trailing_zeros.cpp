#include "common.h"

int main() {
  auto n = readLineT<uint64_t>();
  uint64_t pow = 1;
  uint64_t zeros = 0;

  while(n / pow != 0) {
    pow *= 5;
    zeros += n / pow;
  }
  
  std::cout << zeros << "\n";
}