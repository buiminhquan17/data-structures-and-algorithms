#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

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

int medianOfThree(std::vector<int> vector, int left, int right) {
	int middle = left + (right - left) / 2;
	if (vector.at(left) > vector.at(middle)) {
		std::swap(vector.at(left), vector.at(middle));
	}
	if (vector.at(left) > vector.at(right)) {
		std::swap(vector.at(left), vector.at(right));
	}
	if (vector.at(middle) > vector.at(right)) {
		std::swap(vector.at(middle), vector.at(right));
	}
	return middle;
}

void quickSort(std::vector<int>& vector, int left, int right) {
	int pivotIndex = medianOfThree(vector, left, right);
	int pivot = vector.at(pivotIndex);
	int i = left;
	int j = right;
	do {
		while (vector.at(i) < pivot) { ++i; }
		while (vector.at(j) > pivot) { --j; }
		if (i <= j) {
			std::swap(vector.at(i), vector.at(j));
			++i;
			--j;
		}
	} while (i <= j);
	if (left < j) { quickSort(vector, left, j); }
	if (i < right) { quickSort(vector, i, right); }
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
	quickSort(vector, 0, length - 1);
	std::cout << "Your sorted array: ";
	printArray(vector);
	return 0;
}