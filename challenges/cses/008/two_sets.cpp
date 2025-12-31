#include "common.h"

bool divisionPossible(UI n) {
  return (n*(n + 1)) % 4 == 0;
}

Opt<Pair<Vec<UI>, Vec<UI>>> greedyConstruct(uint64_t n) {
  if(!divisionPossible(n)) return std::nullopt;

  UI goal = (n*(n+1)) / 4;
  Vec<UI> leftList{}, rightList{};
  UI leftSum{};

  for(I i = n; i >= 1; i--) {
    if(leftSum + i <= goal) {
      leftSum += i;
      leftList.push_back(i);
    } else {
      rightList.push_back(i);
    }
  }

  return {{leftList, rightList}};
}

int main() {
  auto n = readLineT<uint64_t>();
  if(auto opt = greedyConstruct(n); opt) {
    auto [l, r] = *opt;
    std::cout << "YES\n";
    for(auto &l : {l, r}) {
      std::cout << l.size() << "\n";
      for(auto e : l) {
        std::cout << e << " ";
      }
      std::cout << "\n";
    }
  } else {
    std::cout << "NO\n";
  }
}