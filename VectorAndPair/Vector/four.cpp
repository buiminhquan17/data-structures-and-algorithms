/*
	Cho vector V có N phần tử, nhiệm vụ của bạn in ra các phần tử từ chỉ số L tới chỉ số R sau đó in ra các phần tử từ chỉ số R tới chỉ số L bằng cách dùng iterator.
	Input Format
	Dòng 1 là N : số lượng phần tử trong vector. Dòng 2 là N số trong vector. Dòng 3 là L và R
	Constraints
	1<=N<=1000. 0<=L<=R
	Output Format
	Dòng 1 in ra vector từ L tới R, dòng 2 in ra vector từ R tới L.
	Sample Input 0
	10
	8 1 8 3 8 5 3 5 9 7 
	3 6
	Sample Output 0
	3 8 5 3 
	3 5 8 3 
*/

#include <iostream>
#include <vector>

int main(void) {
	int length;
	std::cin >> length;
	std::vector<int> vector(length);
	for (auto& element : vector) {
		std::cin >> element;
	}
	int left, right;
	std::cin >> left >> right;
	std::vector<int>::iterator it;
	for (it = vector.begin() + left; it < vector.begin() + right + 1; ++it) {
		std::cout << (*it) << ' ';
	}
	std::cout << '\n';
	for (it = vector.begin() + right; it > vector.begin() + left - 1; --it) {
		std::cout << (*it) << ' ';
	}
	// std::vector<int>::iterator it = vector.begin() + left;
	// while (it != vector.begin() + right + 1) {
	// 	std::cout << (*it) << ' ';
	// 	++it;
	// }
	// std::cout << '\n';
	// it = vector.begin() + right;
	// while (it != vector.begin() + left - 1) {
	// 	std::cout << (*it) << ' ';
	// 	--it;
	// }
	return 0;
}