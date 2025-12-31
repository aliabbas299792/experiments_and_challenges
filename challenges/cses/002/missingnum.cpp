#include "common.h"

#include <vector>

int main() {
  auto n = readLineT<int>();
  std::vector<int> nums(n, -1);

  std::string line{};
  std::getline(std::cin, line);
  std::istringstream iss{line};
  int x;
  while (iss >> x) {
    nums[x-1] = x;
  }
  
  for (int i = 0; i < n; i++) {
    if (nums[i] != i+1) {
        std::cout << i+1 << "\n";
        break;
    }
  }
  
  return 0;
}
