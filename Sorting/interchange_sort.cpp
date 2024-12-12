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

void interchange_sort(vector<int>& arr) {
	for (int i = 0; i < arr.size() - 1; ++i) {
		for (int j = i + 1; j < arr.size(); ++j) {
			if (arr[i] > arr[j]) {
				swap(arr[i], arr[j]);
			}
		}
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
	interchange_sort(arr);
	print_array(arr);
	is_up(arr) ? cout << "passed!\n" : cout << "failed!\n";
	return 0;
}