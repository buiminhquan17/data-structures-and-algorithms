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

int median_of_three(vector<int> arr, int left, int right) {
	int mid = left + (right - left) / 2;
	if (arr[left] > arr[mid]) {
		swap(arr[left], arr[mid]);
	}
	if (arr[left] > arr[right]) {
		swap(arr[left], arr[right]);
	}
	if (arr[mid] > arr[right]) {
		swap(arr[mid], arr[right]);
	}
	return arr[mid];
}

// Thuật toán sắp xếp phân hoạch sử dụng phép phân hoạch Lomuto (Lomuto Partition)
int partition(vector<int>& arr, int left, int right) {
	int pivot = arr[right];
	int i = left - 1;
	for (int j = left; j < right; ++j) {
		if (arr[j] < pivot) {
			++i;
			swap(arr[i], arr[j]);
		}
	}
	swap(arr[i + 1], arr[right]);
	return i + 1;
}

void quick_sort(vector<int>& arr, int left, int right) {
	if (left < right) {
		int piv = partition(arr, left, right);
		quick_sort(arr, left, piv - 1);
		quick_sort(arr, piv + 1, right);
	}
}

// Thuật toán sắp xếp phân hoạch sử dụng phép phân hoạch Hoare (Hoare Partition)
// int partition(vector<int>& arr, int left, int right) {
// 	int pivot = median_of_three(arr, left, right);
// 	int i = left;
// 	int j = right;
// 	do {
// 		while (arr[i] < pivot) ++i;
// 		while (arr[j] > pivot) --j;
// 		if (i >= j) {
// 			return j;
// 		}
// 		swap(arr[i], arr[j]);
// 		++i;
// 		--j;
// 	} while (true);
// }

// void quick_sort(vector<int>& arr, int left, int right) {
// 	if (left < right) {
// 		int piv = partition(arr, left, right);
// 		quick_sort(arr, left, piv);
// 		quick_sort(arr, piv + 1, right);
// 	}
// }

// Thuật toán sắp xếp phân hoạch
// void quick_sort(vector<int>& arr, int left, int right) {
// 	int pivot = median_of_three(arr, left, right);
// 	int i = left;
// 	int j = right;
// 	do {
// 		while (arr[i] < pivot) ++i;
// 		while (arr[j] > pivot) --j;
// 		if (i <= j) {
// 			swap(arr[i], arr[j]);
// 			++i;
// 			--j;
// 		}
// 	} while (i <= j);
// 	if (left < j) quick_sort(arr, left, j);
// 	if (i < right) quick_sort(arr, i, right);
// }

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	vector<int> arr(n);
	get_random_array(arr, n);
	print_array(arr);
	quick_sort(arr, 0, arr.size() - 1);
	print_array(arr);
	is_up(arr) ? cout << "passed!\n" : cout << "failed!\n";
	return 0;
}