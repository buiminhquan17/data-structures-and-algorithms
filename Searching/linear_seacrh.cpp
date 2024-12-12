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

int linearSearch(vector<int> v, int key) {
	for (int i = 0; i < v.size(); ++i) {
		if (v[i] == key) {
			return i;
		}
	}
	return -1;
}

void printArray(vector<int> v) {
	for (int i = 0; i < v.size(); ++i) {
		cout << v[i] << ' ';
	}
	cout << '\n';
}

int main(int argc, char const* agrv[]) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n;
	cin >> n;

	vector<int> v(n);
	getRandomArray(v, n);

	printArray(v);

	cout << "The position of element is: " << linearSearch(v, 57) << '\n';

	return 0;
}