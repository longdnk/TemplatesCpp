#include <bits/stdc++.h>

using namespace std;

struct Node {
	int key;
	Node *next;
	Node *prev;

	Node() = default;

	Node(int x) : key(x), next(nullptr), prev(nullptr) { }
};

struct List {
	Node *head;
	Node *tail;

	List() : head(nullptr), tail(nullptr) { }
};

void displayList(List *&ls) {
	if (ls->head == nullptr) {
		return;
	}

	Node *current = ls->head;
	do {
		cout << current->key << " -> ";
		current = current->next;
	} while (current != ls->head);

	cout << '\n';

	Node *p = ls->tail;
	do {
		cout << p->key << " -> ";
		p = p->prev;
	} while (p != ls->tail);
}

void addToHead(List *&ls, int val) {
	Node *p = new Node(val);
	if (ls->head == nullptr) {
		ls->head = ls->tail = p;
		p->next = p->prev = p;
	}
	else {
		p->next = ls->head;
		p->prev = ls->head->prev;
		ls->head->prev->next = p;
		ls->head->prev = p;
		ls->head = p;
	}
}

void addToTail(List *&ls, int val) {
	Node *p = new Node(val);
	if (ls->head == nullptr) {
		ls->head = ls->tail = p;
		p->next = p->prev = p;
	}
	else {
		p->next = ls->head;
		p->prev = ls->head->prev;
		ls->head->prev->next = p;
		ls->head->prev = p;
		ls->tail = p;
	}
}

bool addAfter(List *&ls, int prevValue, int val) {
	if (ls->head != nullptr) {
		Node *prevNode = ls->head;
		bool flag = false;
		while (prevNode != nullptr && prevNode->key != prevValue) {
			prevNode = prevNode->next;
		}
		if (prevNode != nullptr) {
			Node *p = new Node(val);
			p->next = prevNode->next;
			p->prev = prevNode;

			prevNode->next = p;
			p->next->prev = p;

			if (prevNode == ls->tail) {
				ls->tail = p;
			}
			flag = true;
		}
		return flag;
	}
	return false;
}

bool addBefore(List *&ls, int v, int k) {
	if (ls->head != nullptr) {
		Node *prevNode = ls->head;
		bool flag = false;
		while (prevNode != nullptr && prevNode->key != v) {
			prevNode = prevNode->next;
		}
		if (prevNode != nullptr) {
			Node *prev = prevNode->prev;
			if (prev == ls->tail) {
				addToHead(ls, k);
			}
			else {
				Node *p = new Node(k);
				p->next = prevNode->next;
				p->prev = prevNode;
				prevNode->next = p;
				p->next->prev = p;
			}
			flag = true;
		}
		return flag;
	}
	return false;
}

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	List *ls = new List;
//	addToHead(ls, 10);
//	addToHead(ls, 20);
//	addToHead(ls, 30);
//	addToHead(ls, 40);
//	displayList(ls);
	addToTail(ls, 10);
	addToTail(ls, 20);
	addToTail(ls, 30);
	addToTail(ls, 40);
	addAfter(ls, 40, 60);
	addBefore(ls, 40, 50);
	displayList(ls);
}