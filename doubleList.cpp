#include <bits/stdc++.h>

using namespace std;

struct Node {
	int value;
	Node *next;
	Node *prev;
};

Node *createNode(int x) {
	Node *p = new Node;
	p->value = x;
	p->next = p->prev = nullptr;
	return p;
}

void init(Node *&head) {
	head = nullptr;
}

bool isEmpty(Node *head) {
	return head == nullptr;
}

void insertAtHead(Node *&head, int value) {
	Node *p = createNode(value);
	p->next = head;
	if (!isEmpty(head)) {
		head->prev = p;
	}
	head = p;
}

void insertAtLast(Node *&head, int value) {
	Node *p = createNode(value);
	if (isEmpty(head)) {
		head = p;
	}
	else {
		Node *last = head;
		while (last->next != nullptr) {
			last = last->next;
		}
		p->prev = last;
		last->next = p;
	}
}

void insertAfter(Node *&head, int v, int x) {
	Node *q = head;
	while (q != nullptr && q->value != v) {
		q = q->next;
	}
	if (q != nullptr) {
		if (q->next == nullptr) {
			insertAtLast(head, x);
		}
		else {
			Node *p = createNode(x);
			p->next = q->next;
			p->next->prev = p;
			q->next = p;
			p->prev = q;
		}
	}
}

int getListSize(Node *head) {
	int size = 0;
	while (!isEmpty(head)) {
		++size;
		head = head->next;
	}
	return size;
}

bool insertAfterK(Node *&head, int k, int x) {
	if (k > getListSize(head) || k <= 0) {
		return false;
	}
	int cnt = { 1 };
	Node *q = head;
	Node *p = createNode(x);
	while (q != nullptr && cnt != k) {
		++cnt;
		q = q->next;
	}
	if (q != nullptr) {
		if (q->next == nullptr) {
			insertAtLast(head, x);
		}
		else {
			p->next = q->next;
			p->next->prev = p;
			p->prev = q;
			q->next = p;
		}
	}
	return true;
}

bool deleteFirst(Node *&head) {
	if (!isEmpty(head)) {
		Node *p = head;
		head = p->next;
		if (head != nullptr) {
			p->next->prev = nullptr;
		}
		p->next = nullptr;
		delete p;
		return true;
	}
	return false;
}

bool deleteLast(Node *&head) {
	if (!isEmpty(head)) {
		Node *prev = nullptr;
		Node *last = head;
		while (last->next != nullptr) {
			prev = last;
			last = last->next;
		}
		if (prev == nullptr) {
			deleteFirst(head);
		}
		else {
			prev->next = nullptr;
			delete last;
		}
		return true;
	}
	return false;
}

bool deleteNode(Node *&head, int v) {
	if (!isEmpty(head)) {
		Node *p = head;
		Node *prev = nullptr;
		while (p != nullptr && p->value != v) {
			prev = p;
			p = p->next;
		}
		if (p != nullptr) {
			if (prev == nullptr) {
				deleteFirst(head);
			}
			else if (p->next == nullptr) {
				deleteLast(head);
			}
			else {
				prev->next = p->next;
				prev->next->prev = prev;
				p->next = nullptr;
				delete p;
			}
		}
		return true;
	}
	return false;
}

bool deleteNodeAtK(Node *&head, int k) {
	if (k > getListSize(head) || k <= 0 || isEmpty(head)) {
		return false;
	}
	int cnt = { 1 };
	Node *prev = nullptr;
	Node *p = head;
	while (p != nullptr && cnt != k) {
		++cnt;
		prev = p;
		p = p->next;
	}
	if (p != nullptr) {
		if (prev == nullptr) {
			deleteFirst(head);
		}
		else if (p->next == nullptr) {
			deleteLast(head);
		}
		else {
			prev->next = p->next;
			prev->next->prev = prev;
			p->next = nullptr;
			delete p;
		}
	}
	return true;
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
		first->next->prev = first;
		first->prev = nullptr;
		return first;
	}
	else {
		second->next = merge(first, second->next);
		second->next->prev = second;
		second->prev = nullptr;
		return second;
	}
}

void output(Node *head) {
	while (!isEmpty(head)) {
		cout << head->value << ' ';
		head = head->next;
	}
	cout << '\n';
}

void reverse(Node *head) {
	Node *last = head;
	while (!isEmpty(head)) {
		last = head;
		head = head->next;
	}
	while (!isEmpty(last)) {
		cout << last->value << ' ';
		last = last->prev;
	}
}

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	Node *head;
	init(head);
//	insertAtHead(head, 10);
//	insertAtHead(head, 20);
//	insertAtHead(head, 30);
	insertAtLast(head, 10);
	insertAtLast(head, 20);
	insertAtLast(head, 30);
	insertAfter(head, 30, 40);
	insertAfterK(head, 4, 50);
	output(head);
	reverse(head);
}