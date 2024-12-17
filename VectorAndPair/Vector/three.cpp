/*
	Cho vector V có N phần tử, nhiệm vụ của bạn là sắp xếp các phần tử trong vector theo thứ tự tăng dần, giảm dần sau đó in ra bằng cách dùng iterator.
*/

#include <iostream>
#include <vector>
#include <algorithm>

int main(void) {
	int length;
	std::cin >> length;
	std::vector<int> vector(length);
	for (auto& element : vector) {
		std::cin >> element;
	}
	std::sort(vector.begin(), vector.end());
	for (std::vector<int>::iterator it = vector.begin(); it < vector.end(); ++it) {
		std::cout << (*it) << ' ';
	}
	std::cout << '\n';
	std::sort(vector.begin(), vector.end(), std::greater<int>());
	for (std::vector<int>::iterator it = vector.begin(); it < vector.end(); ++it) {
		std::cout << (*it) << ' ';
	}
	return 0;
}