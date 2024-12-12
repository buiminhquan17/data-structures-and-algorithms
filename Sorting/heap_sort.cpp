#include <bits/stdc++.h>
using namespace std;

bool is_up(vector<int> arr) {
	for (int i = 0; i < arr.size() - 1; ++i) {
		if (arr[i] > arr[i + 1]) {
			return false;
		}
	}
	return true;
}

void get_random_array(vector<int>& arr, int n) {
	int min = 10;
	int max = 99;
	srand(time(nullptr));
	for (int i = 0; i < n; ++i) {
		arr[i] = min + rand() % (max - min + 1);
	}
}

void print_array(vector<int> arr) {
	for (int i = 0; i < arr.size(); ++i) {
		cout << arr[i] << ' ';
	}
	cout << '\n';
}

void heapify(vector<int>& arr, int n, int i) {
	int largest = i;
	int left = 2 * i + 1;
	int right = 2 * i + 2;
	if (left < n && arr[left] > arr[largest]) {
		largest = left;
	}
	if (right < n && arr[right] > arr[largest]) {
		largest = right;
	}
	if (largest != i) {
		swap(arr[i], arr[largest]);
		heapify(arr, n, largest);
	}
}

void heap_sort(vector<int>& arr) {
	for (int i = arr.size() / 2 - 1; i >= 0; --i) {
		heapify(arr, arr.size(), i);
	}
	for (int i = arr.size() - 1; i >= 0; --i) {
		swap(arr[i], arr[0]);
		heapify(arr, i, 0);
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	vector<int> arr(n);
	get_random_array(arr, n);
	print_array(arr);
	heap_sort(arr);
	print_array(arr);
	return 0;
}