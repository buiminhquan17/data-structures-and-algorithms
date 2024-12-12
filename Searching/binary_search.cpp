#include <bits/stdc++.h>
using namespace std;

void getRandomArray(vector<int>& v, int n) {
	int MIN = 10;
	int MAX = 99;
	srand(time(NULL));
	for (int i = 0; i < n; ++i) {
		v[i] = MIN + rand() % (MAX - MIN + 1);
	}
}

void merge(vector<int>& v, int left, int mid, int right) {
	int aSize = mid - left + 1;
	int bSize = right - mid;
	vector<int> a(aSize);
	vector<int> b(bSize);
	for (int i = 0; i < aSize; ++i) {
		a[i] = v[left + i];
	}
	for (int j = 0; j < bSize; ++j) {
		b[j] = v[mid + 1 + j];
	}
	int firstIndex = 0;
	int secondIndex = 0;
	while (firstIndex < aSize && secondIndex < bSize) {
		if (a[firstIndex] <= b[secondIndex]) {
			v[left++] = a[firstIndex++];
		} else {
			v[left++] = b[secondIndex++];
		}
	}
	while (firstIndex < aSize) {
		v[left++] = a[firstIndex++];
	}
	while (secondIndex < bSize) {
		v[left++] = b[secondIndex++];
	}
}

void mergeSort(vector<int>& v, int left, int right) {
	if (left < right) {
		int mid = left + (right - left) / 2;
		mergeSort(v, left, mid);
		mergeSort(v, mid + 1, right);
		merge(v, left, mid, right);
	}
}

int binarySearch(vector<int> v, int key) {
	int left = 0;
	int right = v.size() - 1;
	do {
		int mid = left + (right - left) / 2;
		if (v[mid] == key) {
			return mid;
		} else if (v[mid] < key) {
			left = mid + 1;
		} else {
			right = mid - 1;
		}
	} while (left <= right);
	return -1;
}

void printArray(vector<int> v) {
	for (int i = 0; i < v.size(); ++i) {
		cout << v[i] << ' ';
	}
	cout << '\n';
}

int main(int argc, char const *argv[]) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n;
	cin >> n;

	vector<int> v(n);
	getRandomArray(v, n);

	mergeSort(v, 0, v.size() - 1);

	printArray(v);

	cout << "The position of element: " << binarySearch(v, 54) << '\n';

	return 0;
}