#include "common.h"

uint64_t retrieveCoord(uint64_t x, uint64_t y) {
  auto [pos, level] = std::minmax(x, y);
  auto offset = (level - 1) * (level - 1);

  if(level % 2 == 0) {
    if(pos == x) {
      return offset + (2 * level - 1) - (pos - 1);
    } else {
      return offset + pos;
    }
  } else {
    if(pos == x) {
      return offset + pos;
    } else {
      return offset + (2 * level - 1) - (pos - 1);
    }
  }
}

int main() {
  auto num_tests = readLineT<uint64_t>();

  std::vector<uint64_t> answers{};
  
  for (uint64_t i = 0; i < num_tests; i++) {
    auto pair = readLineOfTs<uint64_t>();
    auto y = pair[0], x = pair[1];
    answers.emplace_back(retrieveCoord(x, y));
  }

  for(auto a : answers) {
    std::cout << a << std::endl;
  }
}