#include <iostream>
#include <cmath>
#include <vector>
#include <utility>
#include <iomanip>

int main(void) {
	int length;
	std::cin >> length;
	std::vector<std::pair<int, int>> vector(length);
	for (auto& element : vector) {
		std::cin >> element.first >> element.second;
	}
	std::vector<float> results;
	for (auto element : vector) {
		float result = std::sqrt(std::pow(element.first, 2) + std::pow(element.second, 2));
		results.emplace_back(result);
	}
	for (auto result : results) {
		std::cout << std::fixed	<< std::setprecision(2) << result << ' ';
	}
	return 0;
}