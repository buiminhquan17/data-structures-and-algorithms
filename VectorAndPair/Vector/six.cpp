#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

int main(void) {
	int length;
	std::cin >> length;
	std::vector<int> vector(length);
	for (auto& element : vector) {
		std::cin >> element;
	}
	std::cout << *std::min_element(vector.begin(), vector.end()) << '\n';
	std::cout << *std::max_element(vector.begin(), vector.end()) << '\n';
	std::cout << std::accumulate(vector.begin(), vector.end(), 0) << '\n';
	return 0;
}