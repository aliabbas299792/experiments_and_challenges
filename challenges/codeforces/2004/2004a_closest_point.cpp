#include <iostream>

int main() {
  int num_cases{};
  std::cin >> num_cases;
  for(int i = 0; i < num_cases; i++) {
    int set_size{};
    std::cin >> set_size;
    bool yes = set_size == 1;

    int prev{}, curr{};
    std::cin >> prev;
    for(int j = 1; j < set_size; j++) {
      std::cin >> curr;

      if(curr - prev > 1 && set_size == 2) {
        yes = true;
      }

      prev = curr;
    }

    if(yes) {
      std::cout << "YES\n";
    } else {
      std::cout << "NO\n";
    }
  }
}
