#include <bits/stdc++.h>

#define null NULL
using namespace std;

struct Node {
	int value;
	Node *left;
	Node *right;
};

void init(Node *&root) {
	root = null;
}

Node *createNode(int x) {
	Node *p = new Node;
	p->value = x;
	p->left = p->right = null;
	return p;
}

void insertValue(Node *&root, int x) {
	if (root == null) {
		root = createNode(x);
	}
	else if (root->value > x) {
		insertValue(root->left, x);
	}
	else {
		insertValue(root->right, x);
	}
}

void insertNode(Node *&root, int x) {
	if (root == null) {
		root = createNode(x);
	}
	else {
		Node *p = root;
		Node *parent = null;
		while (p != null && p->value != x) {
			parent = p;
			if (p->value > x) {
				p = p->left;
			}
			else {
				p = p->right;
			}
		}
		if (p == null) {
			p = createNode(x);
			if (parent->value > x) {
				parent->left = p;
			}
			else {
				parent->right = p;
			}
		}
	}
}

void leftNodeRight(Node *root) {
	if (root != null) {
		leftNodeRight(root->left);
		cout << root->value << ' ';
		leftNodeRight(root->right);
	}
}

void leftRightNode(Node *root) {
	if (root != null) {
		leftRightNode(root->left);
		leftRightNode(root->right);
		cout << root->value << ' ';
	}
}

void nodeLeftRight(Node *root) {
	if (root != null) {
		cout << root->value << ' ';
		nodeLeftRight(root->left);
		nodeLeftRight(root->right);
	}
}

Node *searchNode(Node *root, int key) {
	if (root == null || root->value == key) {
		return root;
	}
	else if (root->value > key) {
		return searchNode(root->left, key);
	}
	else {
		return searchNode(root->right, key);
	}
}

Node *search(Node *root, int x) {
	Node *p = root;
	while (p != null && p->value != x) {
		if (p->value > x) {
			p = p->left;
		}
		else {
			p = p->right;
		}
	}
	return p;
}

void printAsc(Node *root) {
	if (root != null) {
		printAsc(root->left);
		cout << root->value << ' ';
		printAsc(root->right);
	}
}

void printDesc(Node *root) {
	if (root != null) {
		printDesc(root->right);
		cout << root->value << ' ';
		printDesc(root->left);
	}
}

void deleteNode(Node *&root, int x) {
	Node *p = root;
	Node *parent = null;
	while (p != null && p->value != x) {
		parent = p;
		if (p->value > x) {
			p = p->left;
		}
		else {
			p = p->right;
		}
	}
	if (p != null) {
		// 2 sub tree
		if (p->left != null && p->right != null) {
			parent = p;
			Node *t = p->right;
			while (t->left != null) {
				parent = t;
				t = t->left;
			}
			p->value = t->value;
			p = t;
		}
		Node *r = null;
		if (p->left == null) {
			r = p->right;
		}
		else {
			r = p->left;
		}
		// is root node
		if (parent == null) {
			root = r;
		}
			// 1 sub or leaf
		else {
			if (parent->value > p->value) {
				parent->left = r;
			}
			else {
				parent->right = r;
			}
		}
		delete p;
	}
}

// res <= k
Node *findElement(Node *root, int x) {
	if (root == null) {
		return null;
	}
	if (root->value > x) {
		return findElement(root->left, x);
	}
	Node *tmp = findElement(root->right, x);
	if (tmp != null) {
		return tmp;
	}
	if (root->value <= x) return root;
	return findElement(root->left, x);
}

// res >= k
Node *findElemento(Node *root, int x) {
	if (root == null) {
		return root;
	}
	if (root->value < x) {
		return findElemento(root->right, x);
	}
	Node *tmp = findElemento(root->left, x);
	if (tmp != null) {
		return tmp;
	}
	if (root->value > x) {
		return root;
	}
	return findElemento(root->right, x);
}

int findMaxBelow(Node *root, int value) {
	Node *p = root;
	int res = -1e9;
	while (p != nullptr) {
		if (p->value == value) {
			return p->value;
		}
		else if (p->value > value) {
			p = p->left;
		}
		else {
			res = max(res, p->value);
			p = p->right;
		}
	}
	return res;
}

int findMinAbove(Node *root, int value) {
	Node *p = root;
	int res = 1e9;
	while (p != nullptr) {
		if (p->value == value) {
			return p->value;
		}
		else if (p->value > value) {
			res = min(res, p->value);
			p = p->left;
		}
		else {
			p = p->right;
		}
	}
	return res;
}

int find(Node *root, int k) {
	int res = -1e9;
	Node *p = findElement(root, k);
	if (p != null) {
		res = p->value;
	}
	return res;
}

int test(Node *root, int k) {
	int res = -1e9;
	Node *p = findElemento(root, k);
	if (p != null) {
		res = p->value;
	}
	return res;
}

int findMax(Node *root, int key) {
	Node *curr = root, *ans = nullptr;
	while (curr) {
		if (curr->value <= key) {
			ans = curr;
			curr = curr->right;
		}
		else {
			curr = curr->left;
		}
	}
	if (ans) {
		return ans->value;
	}
	return -1;
}

int findMin(Node *root, int key) {
	Node *curr = root, *ans = NULL;
	while (curr) {
		if (curr->value >= key) {
			ans = curr;
			curr = curr->left;
		}
		else {
			curr = curr->right;
		}
	}
	if (ans != nullptr) {
		return ans->value;
	}
	return -1;
}

bool checkSubTree(Node *root, Node *subRoot) {
	if (root == nullptr && subRoot == nullptr) {
		return true;
	}
	if (root == nullptr || subRoot == nullptr) {
		return false;
	}
	if (root->value != subRoot->value) {
		return false;
	}
	return checkSubTree(root->left, subRoot->left) &&
	       checkSubTree(root->right, subRoot->right);
}

bool IsSubTree(Node *root, Node *subRoot) {
	if (checkSubTree(root, subRoot)) {
		return true;
	}
	if (root == nullptr) {
		return false;
	}
	return IsSubTree(root->left, subRoot) ||
	       IsSubTree(root->right, subRoot);
}

bool isSubTree(Node *root, int keyRoot, int keyLeft, int keyRight) {
	if (root == nullptr) {
		return false;
	}
	if (root->left != nullptr && root->right != nullptr && root->value == keyRight &&
	    root->left->value == keyLeft && root->right->value == keyRight)
		return true;
	return isSubTree(root->left, keyRoot, keyLeft, keyRight) ||
	       isSubTree(root->right, keyRoot, keyLeft, keyRight);
}

int getTreeHeight(Node *root) {
	if (root != nullptr) {
		int left = getTreeHeight(root->left) + 1;
		int right = getTreeHeight(root->right) + 1;
		return left > right ? left : right;
	}
	return 0;
}

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
//	20 15 10 9 18 30 25 27 40
	Node *root;
	init(root);
//	insertValue(root, 20);
//	insertValue(root, 15);
//	insertValue(root, 10);
//	insertValue(root, 9);
//	insertValue(root, 18);
//	insertValue(root, 30);
//	insertValue(root, 25);
//	insertValue(root, 27);
//	insertValue(root, 40);
	insertValue(root, 15);
	insertValue(root, 20);
	insertValue(root, 8);
	insertValue(root, 40);
	insertValue(root, 18);
	insertValue(root, 12);
	insertValue(root, 90);
	insertValue(root, 50);
	leftNodeRight(root);
	cout << '\n';
	deleteNode(root, 20);
	leftNodeRight(root);
	cout << '\n';
	cout << find(root, 45) << '\n';
	cout << test(root, 45) << '\n';
	// 40 20 18 15
//	nodeLeftRight(root);
//	cout << '\n';
//	leftNodeRight(root);
//	cout << '\n';
//	leftRightNode(root);
//	cout << '\n';
//	printAsc(root);
//	cout << '\n';
//	printDesc(root);
//	cout << '\n';
}
