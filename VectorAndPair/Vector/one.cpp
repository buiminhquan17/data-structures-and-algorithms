/*
	Cho vector và 2 thao tác.
	Thao tác 1 : Thêm 1 phần tử và cuối vector.
	Thao tác 2 : Xóa phần tử khỏi cuối vector nếu vector không rỗng.
	Nhiệm vụ của bạn là thực hiện 1 loạt các thao tác này và in ra mảng sau khi thực hiện xong mọi thao tác. Nếu vector rỗng in ra EMPTY, ngược lại in ra các phần tử trong vector trên 1 dòng.
	Input Format
	Dòng 1 là N : số thao tác được thực hiện. N dòng tiếp theo mỗi dòng mô tả thao tác, nếu thao tác là 1 sẽ có thêm phần tử được thêm vào cuối.
	Constraints
	1<=N, M<=200; Các phần tử thêm vào vector là số nguyên int 32bit.
	Output Format
	In ra EMPTY nếu vector rỗng, ngược lại in ra các phần tử trong vector trên 1 dòng.

	Sample Input 0
	7
	1 58
	2
	2
	1 52
	1 81
	1 12
	1 2
	Sample Output 0
	52 81 12 2 
*/

#include <iostream>
#include <vector>

int main(void) {
	std::vector<int> vector;
	int query, operation, element;
	std::cin >> query;
	for (int i = 0; i < query; ++i) {
		std::cin >> operation;
		if (operation == 1) {
			std::cin >> element;
			vector.push_back(element);
		} else {
			if (vector.empty() == false) {
				vector.pop_back();
			}
		}
	}
	if (vector.empty()) {
		std::cout << "EMPTY";
	} else {
		for (int element : vector) {
			std::cout << element << ' ';
		}
	}
	return 0;
}