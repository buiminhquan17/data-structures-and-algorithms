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

void merge(vector<int>& arr, int left, int mid, int right) {
	vector<int> first(mid - left + 1);
	vector<int> second(right - mid);
	for (int i = 0; i < first.size(); ++i) {
		first[i] = arr[left + i];
	}
	for (int j = 0; j < second.size(); ++j) {
		second[j] = arr[mid + 1 + j];
	}
	int i = 0;
	int j = 0;
	while (i < first.size() && j < second.size()) {
		if (first[i] <= second[j]) {
			arr[left++] = first[i++];
		} else {
			arr[left++] = second[j++];
		}
	}
	while (i < first.size()) {
		arr[left++] = first[i++];
	}
	while (j < second.size()) {
		arr[left++] = second[j++];
	}
}

void merge_sort(vector<int>& arr, int left, int right) {
	if (left < right) {
		int mid = left + (right - left) / 2;
		merge_sort(arr, left, mid);
		merge_sort(arr, mid + 1, right);
		merge(arr, left, mid, right);
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
	merge_sort(arr, 0, arr.size() - 1);
	print_array(arr);
	is_up(arr) ? cout << "passed!\n" : cout << "failed!\n";
	return 0;
}