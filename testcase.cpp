#include "bits/stdc++.h"

using namespace std;
template <class T>
struct Node {
	int key;
	Node *pLeft;
	Node *pRight;
	Node *pParent;
};

Node<class T> *createNode(int k) {
	Node<T> *p = new Node<T>;
	p->key = k;
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

void insertNode(Node<T> *&root, int k) {
	Node<T> *tmp = NULL;
	insert(root, k, tmp);
}

Node<T> *convertArrayToTree(int a[], int n) {
	Node<T> *root = NULL;
	for (int i = 0; i < n; ++i) {
		insertNode(root, a[i]);
	}
	return root;
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

void deleteNode(Node<T> *&root, int x) {
	Node<T> *p = root;
	Node<T> *parent = NULL;
	while (p != NULL && p->key != x) {
		parent = p;
		if (p->key > x) {
			p = p->pLeft;
		}
		else {
			p = p->pRight;
		}
	}
	if (p != NULL) {
		// 2 sub tree
		if (p->pLeft != NULL && p->pRight != NULL) {
			parent = p;
			Node<T> *t = p->pRight;
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
		// is root node
		if (parent == NULL) {
			root = r;
		}
		// 1 sub or leaf
		else {
			if (parent->key > p->key) {
				parent->pLeft = r;
			}
			else {
				parent->pRight = r;
			}
			r->pParent = parent;
		}
		delete p;
	}
}

int removeNode(Node<T> *&root, int k) {
	if (searchValue(root, k) != NULL) {
		deleteNode(root, k);
		return 1;
	}
	return 0;
}

void output(Node<T> *root) {
	if (root == NULL) {
		return;
	}
	output(root->pLeft);
	output(root->pRight);
	cout << root->key << ' ' << (root->pParent ? root->pParent->key : 0) << '\n';
}

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	Node<T> *root = NULL;
	insertNode(root, 20);
	insertNode(root, 10);
	insertNode(root, 30);
	insertNode(root, 50);
	insertNode(root, 40);
	removeNode(root, 20);
	output(root);
}