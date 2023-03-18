#include <bits/stdc++.h>

using namespace std;

void sortArray(int a[], int n) {
	for (int i = 0; i < n; ++i) {
		for (int j = i + 1; j < n; ++j) {
			if (a[i] > a[j]) {
				int tmp = a[i];
				a[i] = a[j];
				a[j] = tmp;
			}
		}
	}
}

int countElement(int a[], int n, int x) {
	int cnt = 0;
	for (int i = 0; i < n; ++i) {
		if (a[i] == x) {
			++cnt;
		}
	}
	return cnt;
}

void deleteDuplicate(int a[], int &n) {
	int *b = new int[n + 1];
	int index = 0;
	for (int i = 0; i < n; ++i) {
		if (countElement(a, n, a[i]) == 1) {
			b[index] = a[i];
			++index;
		}
	}
	n = index;
	for (int i = 0; i < n; ++i) {
		a[i] = b[i];
	}
}

void printElement(int a[], int n, int k) {
	for (int i = 0; i < n - 1; ++i) {
		int A = a[i];
		int B = a[i + 1];
		if (A <= k && k <= B) {
			cout << A << ' ' << B << '\n';
		}
	}
}

void output(int a[], int n) {
	for (int i = 0; i < n; ++i) {
		cout << a[i] << ' ';
	}
	cout << '\n';
}

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int a[] = { 10, 1, 5, 3, 5, 7 };
	int n = sizeof(a) / sizeof(a[0]);
	cout << "Before sort" << '\n';
	output(a, n);
	sortArray(a, n);
	cout << "After sort" << '\n';
	output(a, n);
	cout << "Before delete" << '\n';
	output(a, n);
	deleteDuplicate(a, n);
	cout << "Afer delete" << '\n';
	output(a, n);
	cout << "All element" << '\n';
	printElement(a, n, 4);
}