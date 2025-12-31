#include <iostream>
#include <cstdint>

void weird_algo(uint64_t n) {
	std::cout << n << " ";
	while(n != 1) {
		if(n % 2 == 0) {
			n /= 2;
		} else {
			n = n*3 + 1;
		}
		std::cout << n << " ";
	}
	std::cout << "\n";
}

int main() {
	uint64_t n{};
	std::cin >> n;
	weird_algo(n);	
}

