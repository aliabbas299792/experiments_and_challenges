#include <iostream>

int main() {
  int num_cases{};
  std::cin >> num_cases;
  for(int i = 0; i < num_cases; i++) {
    int ints{};
    int64_t sum{};
    int64_t sign = 1;
    std::cin >> ints;
    for(int j = 0; j < ints; j++) {
      int num{};
      std::cin >> num;
      sum += sign * num;
      sign *= -1;
    }
    std::cout << sum << "\n";
  }
  
}
