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

void bubble_sort(vector<int>& arr) {
	int is_swapped = 1, length = arr.size();
	do {
		is_swapped = 0;
		for (int i = 0; i < length - 1; ++i) {
			if (arr[i] > arr[i + 1]) {
				swap(arr[i], arr[i + 1]);
				is_swapped = 1;
			}
		}
		--length;
	} while (is_swapped);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	vector<int> arr(n);
	get_random_array(arr, n);
	print_array(arr);
	bubble_sort(arr);
	print_array(arr);
	is_up(arr) ? cout << "passed!\n" : cout << "failed!\n";
	return 0;
}