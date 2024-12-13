#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

bool isUp(const std::vector<int>& vector) {
	int length = vector.size();
	for (int i = 0; i < length - 1; ++i) {
		if (vector.at(i) > vector.at(i + 1)) {
			return false;
		}
	}
	return true;
}

void getRandomArray(std::vector<int>& vector, int length) {
	int randomNumber = 0;
	int min = 100;
	int max = 2000;
	for (int i = 0; i < length; ++i) {
		randomNumber = min + std::rand() % (max - min + 1);
		vector.emplace_back(randomNumber);
	}
}

void printArray(const std::vector<int>& vector) {
	int length = vector.size();
	for (int i = 0; i < length; ++i) {
		std::cout << vector.at(i) << ' ';
	}
	std::cout << '\n';
}

void merge(std::vector<int>& vector, int left, int middle, int right) {
	std::vector<int> first(middle - left + 1);
	std::vector<int> second(right - middle);
	int firstLength = first.size();
	int secondLength = second.size();
	for (int i = 0; i < firstLength; ++i) {
		first.at(i) = vector.at(left + i);
	}
	for (int j = 0; j < secondLength; ++j) {
		second.at(j) = vector.at(middle + 1 + j);
	}
	int i = 0, j = 0;
	while (i < firstLength && j < secondLength) {
		if (first.at(i) <= second.at(j)) {
			vector.at(left++) = first.at(i++);
		} else {
			vector.at(left++) = second.at(j++);
		}
	}
	while (i < firstLength) {
		vector.at(left++) = first.at(i++);
	}
	while (j < secondLength) {
		vector.at(left++) = second.at(j++);
	}
}

void mergeSort(std::vector<int>& vector, int left, int right) {
	if (left < right) {
		int middle = left + (right - left) / 2;
		mergeSort(vector, left, middle);
		mergeSort(vector, middle + 1, right);
		merge(vector, left, middle, right);
	}
}

int main(void) {
	int length, key;
	std::cout << "Enter the length of the array: ";
	std::cin >> length;
	if (length <= 0) {
		std::cerr << "An error has occurred!\n";
		return 1;
	}
	std::vector<int> vector;
	srand(time(nullptr));
	getRandomArray(vector, length);
	std::cout << "Your array is: ";
	printArray(vector);
	mergeSort(vector, 0, length - 1);
	std::cout << "Your sorted array: ";
	printArray(vector);
	std::cout << (isUp(vector) ? "YES" : "NO") << '\n';
	return 0;
}