/*
	Cho vector V có N phần tử, nhiệm vụ của bạn là lật ngược vector V và in ra.
	Sau khi lật ngược toàn bộ vector, bạn tiếp tục lật ngược các phần tử từ chỉ số L tới chỉ số R sau đó in ra vector.
	Để lật ngược vector V :
	reverse(V.begin(), V.end()), để lật ngược vector V từ chỉ số L tới chỉ số R :
	reverse(V.begin() + L, V.begin() + R + 1);
	Input Format
	Dòng 1 là N : số lượng phần tử trong vector. Dòng 2 là N số trong vector. Dòng 3 là L và R
	Constraints
	1<=N<=1000. 0<=L<=R
	Output Format
	Dòng 1 in ra vector sau lần lật 1, dòng 2 in ra vector sau lận lật 2.
	Sample Input 0
	13
	5 3 4 1 6 3 0 3 1 4 8 4 1 
	3 3
	Sample Output 0
	1 4 8 4 1 3 0 3 6 1 4 3 5 
	1 4 8 4 1 3 0 3 6 1 4 3 5 
	Sample Input 1
	10
	7 8 1 7 1 9 1 4 0 9 
	3 5
	Sample Output 1
	9 0 4 1 9 1 7 1 8 7 
	9 0 4 1 9 1 7 1 8 7 
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
	int left, right;
	std::cin >> left >> right;
	std::reverse(vector.begin(), vector.end());
	for (auto element : vector) {
		std::cout << element << ' ';
	}
	std::cout << '\n';
	std::reverse(vector.begin() + left, vector.begin() + right + 1);
	for (auto element : vector) {
		std::cout << element << ' ';
	}
	return 0;
}