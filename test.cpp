#include <bits/stdc++.h>

using namespace std;
template<class T>
struct Node {
	int key;
	Node *pLeft;
	Node *pRight;
	Node *pParent;
};

Node<class T> *createNode(int x) {
	Node<T> *p = new Node<T>;
	p->key = x;
	p->pLeft = p->pRight = p->pParent = nullptr;
	return p;
}

void insert(Node<T> *&root, int value, Node<T> *parent) {
	Node<T> *p = createNode(value);
	if (root == nullptr) {
		p->pParent = parent;
		root = p;
	}
	else if (root->key > value) {
		insert(root->pLeft, value, root);
	}
	else {
		insert(root->pRight, value, root);
	}
}

void insertNode(Node<T> *&root, int k) {
	insert(root, k, nullptr);
}

Node<T> *convertArrayToTree(int a[], int n) {
	Node<T> *tmp = nullptr;
	for (int i = 0; i < n; ++i) {
		insertNode(tmp, a[i]);
	}
	return tmp;
}

Node<T> *searchTree(Node<T> *root, int k) {
	if (root == nullptr || root->key == k) {
		return root;
	}
	else if (root->key > k) {
		return searchTree(root->pLeft, k);
	}
	else {
		return searchTree(root->pRight, k);
	}
}

Node<T> *searchValue(Node<T> *root, int k) {
	while (root != nullptr && root->key != k) {
		if (root->key > k) {
			root = root->pLeft;
		}
		else {
			root = root->pRight;
		}
	}
	return root;
}

void deleteNode(Node<T> *&root, int x) {
	Node<T> *p = root;
	Node<T> *parent = nullptr;
	while (p != nullptr && p->key != x) {
		parent = p;
		if (p->key > x) {
			p = p->pLeft;
		}
		else {
			p = p->pRight;
		}
	}
	if (p != nullptr) {
		if (p->pLeft != nullptr && p->pRight != nullptr) {
			parent = p;
			Node<T> *t = p->pRight;
			while (t->pLeft != nullptr) {
				parent = t;
				t = t->pLeft;
			}
			p->key = t->key;
			p = t;
		}
		Node<T> *r;
		if (p->pLeft == nullptr) {
			r = p->pRight;
		}
		else {
			r = p->pLeft;
		}
		if (parent == nullptr) {
			root = r;
		}
		else {
			if (parent->key > p->key) {
				parent->pLeft = r;
			}
			else {
				parent->pRight = r;
			}
		}
	}
}

int removeNode(Node<T> *&root, int k) {
	if (searchTree(root, k) != nullptr) {
		deleteNode(root, k);
		return 1;
	}
	return 0;
}

Node<T> *findMaxBelow(Node<T> *root, int k) {
	if (root == nullptr) {
		return nullptr;
	}
	else if (root->key > k) {
		return findMaxBelow(root->pLeft, k);
	}
	Node<T> *tmp = findMaxBelow(root->pRight, k);
	if (tmp != nullptr) {
		return tmp;
	}
	if (root->key < k) {
		return root;
	}
	return findMaxBelow(root->pLeft, k);
}

Node<T> *findMinAbove(Node<T> *root, int k) {
	if (root == nullptr) {
		return nullptr;
	}
	else if (root->key < k) {
		return findMinAbove(root->pRight, k);
	}
	Node<T> *tmp = findMinAbove(root->pLeft, k);
	if (tmp != nullptr) {
		return tmp;
	}
	if (root->key < k) {
		return root;
	}
	return findMinAbove(root->pRight, k);
}

bool checkSubTree(Node<T> *root, Node<T> *subRoot) {
	if (root == nullptr && subRoot == nullptr) {
		return true;
	}
	if (root == nullptr || subRoot == nullptr) {
		return false;
	}
	if (root->key != subRoot->key) {
		return false;
	}
	return checkSubTree(root->pLeft, subRoot->pLeft) && checkSubTree(root->pRight, subRoot->pRight);
}

bool IsSubTree(Node<T> *root, Node<T> *subRoot) {
	if (checkSubTree(root, subRoot)) {
		return true;
	}
	if (root == nullptr) {
		return false;
	}
	return IsSubTree(root->pLeft, subRoot) || IsSubTree(root->pRight, subRoot);
}

bool isSubTree(Node<T> *root, int keyRoot, int keyLeft, int keyRight) {
	if (root == nullptr) {
		return false;
	}
	if (root->pLeft != nullptr && root->pRight != nullptr && root->key == keyRoot &&
	    root->pLeft->key == keyLeft && root->pRight->key == keyRight) {
		return true;
	}
	return isSubTree(root->pLeft, keyRoot, keyLeft, keyRight) || isSubTree(root->pRight, keyRoot, keyLeft, keyRight);
}

Node<T> *findMaxEvenX(Node<T> *root, int x) {
	if (root == nullptr) {
		return nullptr;
	}
	if (root->key > x) {
		return findMaxEvenX(root->pLeft, x);
	}
	Node<T> *tmp = findMaxEvenX(root->pRight, x);
	if (tmp != nullptr) {
		return tmp;
	}
	if (root->key <= x && !(root->key & 1)) {
		return root;
	}
	return findMaxEvenX(root->pLeft, x);
}

Node<T> *findMinOddX(Node<T> *root, int x) {
	if (root == nullptr) {
		return nullptr;
	}
	if (root->key < x) {
		return findMinOddX(root->pRight, x);
	}
	Node<T> *tmp = findMinOddX(root->pLeft, x);
	if (tmp != nullptr) {
		return tmp;
	}
	if (root->key > x && (root->key & 1)) {
		return root;
	}
	return findMinOddX(root->pRight, x);
}

void printLeaves(Node<T> *root) {
	if (root == nullptr) {
		return;
	}
	printLeaves(root->pRight);
	printLeaves(root->pLeft);
	if (root->pLeft == nullptr && root->pRight == nullptr) {
		cout << root->key << ' ';
	}
}

void print1Sub(Node<T> *root) {
	if (root == nullptr) {
		return;
	}
	print1Sub(root->pLeft);
	print1Sub(root->pRight);
	if ((root->pLeft == nullptr && root->pRight != nullptr) || (root->pLeft != nullptr && root->pRight == nullptr)) {
		cout << root->key << ' ';
	}
}

void print2Sub(Node<T> *root) {
	if (root == nullptr) {
		return;
	}
	print2Sub(root->pRight);
	print2Sub(root->pLeft);
	if (root->pLeft != nullptr && root->pRight != nullptr) {
		cout << root->key << ' ';
	}
}

bool validBST(Node<T> *root, int left, int right) {
	if (root == nullptr) {
		return true;
	}
	if (root->key <= left && root->key >= right) {
		return false;
	}
	return validBST(root->pLeft, left, root->key) && validBST(root->pRight, root->key, right);
}

bool checkBST(Node<T> *root) {
	const int INF = 1e6;
	validBST(root, -INF, +INF);
}

bool findBST(Node<T> *root, Node<T> *subRoot) {
	return checkBST(root) && checkBST(subRoot);
}

int getMax(int a, int b) {
	return a > b ? a : b;
}

int findMaxElement(Node<T> *root, int maximum) {
	if (root == nullptr) {
		return maximum;
	}
	return findMaxElement(root->pRight, getMax(maximum, root->key));
}

int findMax(Node<T> *root) {
	return findMaxElement(root, -1e9);
}

int getMin(int a, int b) {
	return a < b ? a : b;
}

int findMinElement(Node<T> *root, int minimum) {
	if (root == nullptr) {
		return minimum;
	}
	return findMinElement(root->pLeft, getMin(minimum, root->key));
}

int findMin(Node<T> *root) {
	return findMinElement(root, 1e9);
}

int maxBelow(Node<T> *root, int k) {
	int res = -1e9;
	while (root != nullptr && root->key != k) {
		if (root->key > k) {
			root = root->pLeft;
		}
		else {
			res = getMax(res, root->key);
			root = root->pRight;
		}
	}
	return res;
}

int minAbove(Node<T> *root, int k) {
	int res = 1e9;
	while (root != nullptr && root->key != k) {
		if (root->key > k) {
			res = getMin(res, root->key);
			root = root->pLeft;
		}
		else {
			root = root->pRight;
		}
	}
	return res;
}

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
}