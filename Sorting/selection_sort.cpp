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

void selectionSort(std::vector<int>& vector) {
	int length = vector.size();
	int minIndex = 0;
	for (int i = 0; i < length - 1; ++i) {
		minIndex = i;
		for (int j = i + 1; j < length; ++j) {
			if (vector.at(minIndex) > vector.at(j)) {
				minIndex = j;
			}
		}
		std::swap(vector.at(minIndex), vector.at(i));
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
	selectionSort(vector);
	std::cout << "Your sorted array: ";
	printArray(vector);
	return 0;
}