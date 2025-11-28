#include <iostream>

int main() {
  int weight{};
  
  std::cin >> weight;
  
  if(weight >= 4 && weight % 2 == 0) {
    std::cout << "YES\n";
  } else {
    std::cout << "NO\n";
  }
  
  return 0;
}
