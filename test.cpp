#include <bits/stdc++.h>

using namespace std;
int longestHill(int a[], int n) {
	int res = 0;
	int count, i = 0;
	while (i < n - 1) {
		count = 0;
		while (i < n - 1 && a[i] <= a[i + 1]) {
			++count;
			++i;
		}
		while (i < n - 1 && a[i] >= a[i + 1]) {
			++count;
			++i;
		}
		++count;
		if (res < count) {
			res = count;
		}
	}
	return res;
}

int tongCon(int a[], int n, int x) {
	if (x == 0) {
		return 1;
	}
	if (n <= 0) {
		return 0;
	}
	return tongCon(a, n - 1, x) + tongCon(a, n - 1, x - a[n - 1]);
}

bool findSum(int a[], int n, int x) {
	if (x == 0) {
		return true;
	}
	if (n <= 0) {
		return false;
	}
	return findSum(a, n - 1, x) || findSum(a, n - 1, x - a[n - 1]);
}

int getMax(int a, int b) {
	return a > b ? a : b;
}

int MaxBelow(int a[], int n, int k) {
	if (k < 0 || k > n - 1 || n <= 0) {
		return -1e9;
	}
	int res = -1e9;
	for (int i = 0; i < n; ++i) {
		if (a[i] < a[k]) {
			res = getMax(res, a[i]);
		}
	}
	return res;
}

int getMin(int a, int b) {
	return a < b ? a : b;
}

int MinAbove(int a[], int n, int k) {
	if (k < 0 || k > n - 1 || n <= 0) {
		return 1e9;
	}
	int res = 1e9;
	for (int i = 0; i < n; ++i) {
		if (a[i] > a[k]) {
			res = getMin(res, a[i]);
		}
	}
	return res;
}
struct Node {
	int key;
	Node *left;
	Node *right;
};

Node *findNode(Node *root, int k) {
	if (root == NULL || root->key == k) {
		return root;
	}
	else if (root->key > k) {
		return findNode(root->left, k);
	}
	else {
		return findNode(root->right, k);
	}
}

void printLeaves(Node *root) {
	if (root == NULL) {
		return;
	}
	printLeaves(root->right);
	printLeaves(root->left);
	if (root->left == NULL && root->right == NULL) {
		cout << root->key << ' ';
	}
}

bool validBST(Node *root, int left, int right) {
	if (root == NULL) {
		return true;
	}
	if (root->key <= left || root->key >= right) {
		return false;
	}
	return validBST(root->left, left, root->key) && validBST(root->right, root->key, right);
}

bool checkBST(Node *root) {
	const int INF = 1'000'000'000;
	return validBST(root, -INF, +INF);
}
// cái nào cũng hay :v

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
}