#include <iostream>
#include <numeric>
#include <sstream>
#include <vector>

int main() {
  int n{};
  std::cin >> n;
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

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
