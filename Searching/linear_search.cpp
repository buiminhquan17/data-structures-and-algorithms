#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

void getRandomArray(std::vector<int>& vector, int length) {
	int randomNumber = 0;
	int min = 10;
	int max = 99;
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

int linearSearch(const std::vector<int>& vector, int key) {
	int length = vector.size();
	for (int i = 0; i < length; ++i) {
		if (vector.at(i) == key) {
			return i;
		}
	}
	return -1;
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
	std::cout << "Enter your key: ";
	std::cin >> key;
	int position = linearSearch(vector, key);
	if (position == -1) {
		std::cout << "Not found!\n";
	} else {
		std::cout << "The position is: " << position << '\n';
	}
	return 0;
}