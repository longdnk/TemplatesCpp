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
	p->pLeft = p->pRight = p->pParent = NULL;
	return p;
}

void insert(Node<T> *&root, int value, Node<T> *&parent) {
	Node<T> *p = createNode(value);
	if (root == NULL) {
		p->pParent = parent;
		root = p;
	}
	if (root->key == value) {
		return;
	}
	else if (root->key > value) {
		insert(root->pLeft, value, root);
	}
	else {
		insert(root->pRight, value, root);
	}
}

void insertNode(Node<T> *&root, int value) {
	Node<T> *tmp = NULL;
	insert(root, value, tmp);
}

Node<T> *convertArrayToTree(int a[], int n) {
	Node<T> *tmp = NULL;
	for (int i = 0; i < n; ++i) {
		insertNode(tmp, a[i]);
	}
	return tmp;
}

Node<T> *searchTree(Node<T> *root, int k) {
	if (root == NULL || root->key == k) {
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
	Node<T> *p = root;
	while (p != NULL && p->key != k) {
		if (p->key > k) {
			p = p->pLeft;
		}
		else {
			p = p->pRight;
		}
	}
	return p;
}

void find(Node<T> *&root, Node<T> *&parent, int k) {
	Node<T> *&p = *&root;
	if (p == NULL || p->key == k) {
		return;
	}
	else if (p->key > k) {
		find(p = p->pLeft, parent = root, k);
	}
	else {
		find(p = p->pRight, parent = root, k);
	}
}

Node<T> *findPredecessor(Node<T> *&root, Node<T> *&parent) {
	root = root->pRight;
	while (root->pLeft != NULL) {
		parent = root;
		root = root->pLeft;
	}
	return root;
}

void deleteNode(Node<T> *&root, int k) {
	Node<T> *p = root;
	Node<T> *parent = NULL;
	while (p != NULL && p->key != k) {
		parent = p;
		if (p->key > k) {
			p = p->pLeft;
		}
		else {
			p = p->pRight;
		}
	}
	if (p != NULL) {
		if (p->pLeft != NULL && p->pRight != NULL) { // 2 sub
			parent = p;
			Node<T> *t = p->pRight; // find predecessor
			while (t->pLeft != NULL) {
				parent = t;
				t = t->pLeft;
			}
			p->key = t->key;
			p = t;
		}
		Node<T> *r = NULL;
		if (p->pLeft == NULL) {
			r = p->pRight;
		}
		else {
			r = p->pLeft;
		}
		if (parent == NULL) { // is ROOT node
			root = r;
		}
		// others
		else {
			if (parent->key > p->key) {
				parent->pLeft = r;
			}
			else {
				parent->pRight = r;
			}
		}
		delete p;
	}
}

int removeNode(Node<T> *&root, int k) {
	if (searchTree(root, k) != NULL) {
		deleteNode(root, k);
		return 1;
	}
	return 0;
}

bool validBST(Node<T> *root, int left, int right) {
	if (root == NULL) {
		return true;
	}
	if (root->key <= left || root->key >= right) {
		return false;
	}
	return validBST(root->pLeft, left, root->key) && validBST(root->pRight, root->key, right);
}

bool checkBST(Node<T> *root) {
	return validBST(root, -1e9, 1e9);
}

bool checkSubTree(Node<T> *root, Node<T> *subRoot) {
	if (root == NULL && subRoot == NULL) {
		return true;
	}
	if (root == NULL || subRoot == NULL) {
		return false;
	}
	if (root->key != subRoot->key) {
		return false;
	}
	return checkSubTree(root->pLeft, subRoot->pLeft) && checkSubTree(root->pRight, subRoot->pRight);
}

bool isSubTree(Node<T> *root, Node<T> *subRoot) {
	if (checkSubTree(root, subRoot)) {
		return true;
	}
	if (root == NULL) {
		return false;
	}
	return isSubTree(root->pLeft, subRoot) || isSubTree(root->pRight, subRoot);
}

Node<T> *findMaxEvenX(Node<T> *root, int x) {
	if (root == NULL) {
		return NULL;
	}
	if (root->key > x) {
		return findMaxEvenX(root->pLeft, x);
	}
	Node<T> *tmp = findMaxEvenX(root->pRight, x);
	if (tmp != NULL) {
		return tmp;
	}
	if (root->key <= x && root->key % 2 == 0) {
		return root;
	}
	return findMaxEvenX(root->pLeft, x);
}

Node<T> *findMinAbove(Node<T> *root, int x) {
	if (root == NULL) {
		return NULL;
	}
	if (root->key < x) {
		return findMinAbove(root->pRight, x);
	}
	Node<T> *tmp = findMinAbove(root->pLeft, x);
	if (tmp != NULL) {
		return tmp;
	}
	if (root->key > x) {
		return root;
	}
	return findMinAbove(root->pRight, x);
}

void printLeaves(Node<T> *root) {
	if (root == NULL) {
		return;
	}
	printLeaves(root->pRight);
	printLeaves(root->pLeft);
	if (root->pLeft == NULL && root->pRight == NULL) {
		cout << root->key << ' ';
	}
}

void output(Node<T> *root) {
	if (root != NULL) {
		output(root->pLeft);
		output(root->pRight);
		// cout << root->key << ' ' << (root->pParent ? root->pParent->key : 0) << '\n';
		cout << root->key << ' ';
	}
}

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
}