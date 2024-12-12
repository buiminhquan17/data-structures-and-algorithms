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

int get_max(vector<int> arr) {
	int max = arr[0];
	for (int i = 1; i < arr.size(); ++i) {
		if (arr[i] > max) {
			max = arr[i];
		}
	}
	return max;
}

void counting_sort(vector<int>& arr, int exp) {
	int n = arr.size();
	vector<int> output(n);
	vector<int> count(10, 0);
	for (int i = 0; i < n; ++i) {
		count[(arr[i] / exp) % 10]++;
	}
	for (int i = 1; i < 10; ++i) {
		count[i] += count[i - 1];
	}
	for (int i = n - 1; i >= 0; --i) {
		output[count[(arr[i] / exp) % 10] - 1] = arr[i];
		count[(arr[i] / exp) % 10]--;
	}
	for (int i = 0; i < n; ++i) {
		arr[i] = output[i];
	}
}

void radix_sort(vector<int>& arr) {
	int m = get_max(arr);
	for (int exp = 1; m / exp > 0; exp *= 10) {
		counting_sort(arr, exp);
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
	radix_sort(arr);
	print_array(arr);
	is_up(arr) ? cout << "passed!\n" : cout << "failed!\n";
	return 0;
}