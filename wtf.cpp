#include <bits/stdc++.h>

using namespace std;

struct Node {
	int key;
	Node *next;

	Node() = default;

	Node(int x) : key(x), next(nullptr) { }
};

struct List {
	Node *head;
	Node *tail;

	List() : head(nullptr), tail(nullptr) { }
};

void addHead(List *&ls, int k) {
	Node *p = new Node(k);
	if (ls->head == nullptr) {
		ls->head = ls->tail = p;
	}
	else {
		p->next = ls->head;
		ls->head = p;
	}
	ls->tail->next = ls->head;
}

void addLast(List *&ls, int k) {
	Node *p = new Node(k);
	if (ls->head == nullptr) {
		ls->head = ls->tail = p;
	}
	else {
		ls->tail->next = p;
		ls->tail = p;
	}
	ls->tail->next = ls->head;
}

Node *searchNode(List *ls, int k) {
	if (ls->head != nullptr) {
		Node *p = ls->head;
		do {
			if (p->key == k) {
				return p;
			}
			p = p->next;
		} while (p != ls->head);
	}
	return nullptr;
}

bool addAfter(List *&ls, int v, int k) {
	Node *q = searchNode(ls, v);
	if (q != nullptr) {
		Node *p = new Node(k);
		p->next = q->next;
		q->next = p;
		if (q == ls->tail) {
			ls->tail = p;
		}
		return true;
	}
	return false;
}

Node *searchElement(List *ls, Node *&prev, int k) {
	Node *p = ls->head;
	do {
		if (p->key == k) {
			return p;
		}
		prev = p;
		p = p->next;
	} while (p != ls->head);
	return nullptr;
}

bool addBefore(List *&ls, int v, int k) {
	Node *prev = nullptr;
	Node *q = searchElement(ls, prev, v);
	if (q != nullptr) {
		if (prev == nullptr) {
			addHead(ls, k);
		}
		else {
			Node *p = new Node(k);
			p->next = prev->next;
			prev->next = p;
		}
		return true;
	}
	return false;
}

bool deleteHead(List *&ls) {
	if (ls->head != nullptr) {
		Node *p = ls->head;
		if (ls->head == ls->tail) {
			ls->head = ls->tail = nullptr;
		}
		else {
			ls->head = p->next;
			ls->tail->next = ls->head;
		}
		delete p;
		return true;
	}
	return false;
}

bool deleteLast(List *&ls) {
	if (ls->head != nullptr) {
		Node *last = ls->head;
		Node *prev = nullptr;
		while (last != ls->tail) {
			prev = last;
			last = last->next;
		}
		if (prev == nullptr) {
			return deleteHead(ls);
		}
		prev->next = last->next;
		ls->tail = prev;
		delete last;
		return true;
	}
	return false;
}

bool deleteNode(List *&ls, int k) {
	if (ls->head != nullptr) {
		Node *prev = nullptr;
		Node *p = searchElement(ls, prev, k);
		bool flag = false;
		if (p != nullptr) {
			flag = true;
			if (prev == nullptr) {
				return deleteHead(ls);
			}
			prev->next = p->next;
			p->next = nullptr;
			if (p == ls->tail) {
				ls->tail = prev;
			}
			delete p;
		}
		return flag;
	}
	return false;
}

int getListSize(List *ls) {
	Node *p = ls->head;
	int size = 0;
	do {
		++size;
		p = p->next;
	} while (p != ls->head);
	return size;
}

bool deleteNodeAtK(List *&ls, int k) {
	if (k <= 0 || k > getListSize(ls) || ls->head == nullptr) {
		return false;
	}
	Node *p = ls->head;
	Node *prev;
	do {
		--k;
		prev = p;
		p = p->next;
	} while (p != ls->head && k > 1);
	if (k == 0) {
		return deleteHead(ls);
	}
	if (p == ls->tail) {
		ls->tail = prev;
	}
	prev->next = p->next;
	p->next = nullptr;
	delete p;
	return true;
}

void output(List *ls) {
	if (ls->head) {
		Node *p = ls->head;
		do {
			cout << p->key << ' ';
			p = p->next;
		} while (p != ls->head);
	}
	cout << '\n';
}

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	List *ls = new List;
//	addHead(ls, 10);
//	addHead(ls, 20);
//	addHead(ls, 30);
	addLast(ls, 10);
	addLast(ls, 20);
	addLast(ls, 30);
	addAfter(ls, 30, 50);
	addBefore(ls, 50, 40);
//	deleteHead(ls);
//	deleteLast(ls);
//	deleteNode(ls, 10);
//	deleteNodeAtK(ls, 1);
	output(ls);
}