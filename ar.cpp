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

void removeDuplicate(int a[], int &n) {
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

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
	int a[] = { 5, 1, 5, 10, 7, 3 };
	int n = sizeof(a) / sizeof(a[0]);
	sortArray(a, n);
	for (int i = 0; i < n; ++i) {
		cout << a[i] << ' ';
	}
	cout << '\n';
	removeDuplicate(a, n);
	for (int i = 0; i < n; ++i) {
		cout << a[i] << ' ';
	}
	cout << '\n';
	printElement(a, n, 10);
}