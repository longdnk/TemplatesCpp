#include <bits/stdc++.h>

using namespace std;

struct Node {
	int value;
	Node *next;
};

bool isEmpty(Node *head) {
	return head == nullptr;
}

int getListSize(Node *head) {
	int size = 0;
	while (!isEmpty(head)) {
		++size;
		head = head->next;
	}
	return size;
}

bool deleteFirst(Node *&head) {
	if (!isEmpty(head)) {
		Node *p = head;
		head = p->next;
		p->next = nullptr;
		delete p;
		return true;
	}
	return false;
}

Node *merge(Node *first, Node *second) {
	if (!first) {
		return second;
	}
	if (!second) {
		return first;
	}
	if (first->value < second->value) {
		first->next = merge(first->next, second);
		return first;
	}
	else {
		second->next = merge(first, second->next);
		return second;
	}
}

bool deleteNodeAtK(Node *&head, int k) {
	if (isEmpty(head) || k <= 0 || k > getListSize(head)) {
		return false;
	}
	Node *p = head;
	Node *prev = nullptr;
	int cnt = { 1 };
	while (p != nullptr && cnt != k) {
		++cnt;
		prev = p;
		p = p->next;
	}
	if (p != nullptr) {
		if (prev == nullptr) {
			deleteFirst(head);
		}
		else {
			prev->next = p->next;
			p->next = nullptr;
			delete p;
		}
	}
	return true;
}

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
}