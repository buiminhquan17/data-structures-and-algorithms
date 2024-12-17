#include <iostream>
#include <vector>
#include <utility>

int main(void) {
	int length;
	std::cin >> length;
	std::vector<std::pair<std::pair<int, int>, int>> vector(length);
	for (auto& element : vector) {
		std::cin >> element.first.first >> element.first.second >> element.second;
	}
	std::vector<int> results;
	for (auto element : vector) {
		int summation = element.first.first + element.first.second + element.second;
		results.emplace_back(summation);
	}
	for (auto result : results) {
		std::cout << result << ' ';
	}
	return 0;
}