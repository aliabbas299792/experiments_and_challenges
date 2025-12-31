#include <cstdint>
#include <optional>
#include <string>
#include <vector>
#include <iostream>
#include <numeric>
#include <sstream>
#include <array>
#include <algorithm>

using UI = uint64_t;
using I = int64_t;

template<typename T>
using Vec = std::vector<T>;

template<typename T, typename U>
using Pair = std::pair<T, U>;

template<typename T>
using Opt = std::optional<T>;

template<typename T>
T readLineT() {
  T n{};
  std::cin >> n;
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  return n;
}

template<typename T>
std::vector<T> readLineOfTs(size_t size = 0) {
  std::vector<T> vals{};
  if(size != 0) {
    vals.reserve(size);
  }

  std::string line{};
  std::getline(std::cin, line);
  std::istringstream iss{line};

  T x;
  while (iss >> x) {
    vals.emplace_back(x);
  }

  return vals;
}