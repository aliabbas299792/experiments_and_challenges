#include "common.h"

int main() {
  auto n = readLineT<int>();

  if(n <= 3 && n != 1) {
    std::cout << "NO SOLUTION" << std::endl;
    return 0;
  }

  for(int i = 1; i >= 0; i--) {
    for(int j = i + 1; j <= n; j += 2) {
      std::cout << j << " ";
    }
  }

  std::cout << std::endl;
}
