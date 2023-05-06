//
// Created by longdnk on 2/2/2023.
//
#include <bits/stdc++.h>

using namespace std;
struct Node {
	int key;
	Node *left;
	Node *right;
};

Node *findMaxEvenX(Node *root, int x) {
	if (root == nullptr) {
		return nullptr;
	}
	if (root->key > x) {
		return findMaxEvenX(root->left, x);
	}
	Node *tmp = findMaxEvenX(root->right, x);
	if (tmp != nullptr) {
		return tmp;
	}
	if (root->key < x && root->key % 2 == 0) {
		return root;
	}
	return findMaxEvenX(root->left, x);
}

bool isValidBST(Node *root, int left, int right) {
	if (root == nullptr) {
		return true;
	}
	if (root->key > left && root->key < right) {
		return isValidBST(root->left, left, root->key) && isValidBST(root->right, root->key, right);
	}
	return false;
}

bool checkBST(Node *root) {
	return isValidBST(root, -1e9, 1e9);
}

bool isSubTree(Node *root, int keyRoot, int keyLeft, int keyRight) {
	if (root == nullptr) {
		return false;
	}
	if (root->left != nullptr && root->right != nullptr && root->key == keyRoot &&
	    root->left->key == keyLeft && root->right->key == keyRight) {
		return true;
	}
	return isSubTree(root->left, keyRoot, keyLeft, keyRight) ||
	       isSubTree(root->right, keyRoot, keyLeft, keyRight);
}

bool checkSubTree(Node *root, Node *subRoot) {
	if (root == nullptr && subRoot == nullptr) {
		return true;
	}
	if (root == nullptr || subRoot == nullptr) {
		return false;
	}
	if (root->key != subRoot->key) {
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

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
}