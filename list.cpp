#include <bits/stdc++.h>

#define null NULL
using namespace std;

struct Node {
	int value;
	Node *next;
};

void init(Node *&head) {
	head = null;
}

Node *createNode(int x) {
	Node *p = new Node;
	p->value = x;
	p->next = null;
	return p;
}

void addFirst(Node *&head, int x) {
	Node *p = createNode(x);
	p->next = head;
	head = p;
}

void addLast(Node *&head, int x) {
	Node *p = createNode(x);
	if (head == null) {
		head = p;
	}
	else {
		Node *last = head;
		while (last->next != null) {
			last = last->next;
		}
		last->next = p;
	}
}

void addAfter(Node *&head, int v, int x) {
	Node *p = createNode(x);
	Node *q = head;
	while (q != null && q->value != v) {
		q = q->next;
	}
	if (q != null) {
		p->next = q->next;
		q->next = p;
	}
}

int getListSize(Node *head) {
	int size = 0;
	while (head != null) {
		++size;
		head = head->next;
	}
	return size;
}

void addAfterK(Node *&head, int k, int x) {
	if (k > getListSize(head) || k <= 0 || head == null) {
		return;
	}
	else {
		--k;
		int cnt = 0;
		Node *p = createNode(x);
		Node *q = head;
		while (q != null && cnt < k) {
			++cnt;
			q = q->next;
		}
		if (q != null) {
			p->next = q->next;
			q->next = p;
		}
	}
}

void deleteFirst(Node *&head) {
	if (head != null) {
		Node *p = head;
		head = p->next;
		p->next = null;
		delete p;
	}
}

void deleteLast(Node *&head) {
	if (head != null) {
		Node *prev = null;
		Node *last = head;
		while (last->next != null) {
			prev = last;
			last = last->next;
		}
		if (prev == null) {
			Node *tmp = head;
			head = tmp->next;
			tmp->next = null;
			delete tmp;
		}
		else {
			prev->next = null;
			delete last;
		}
	}
}

void deleteNode(Node *&head, int x) {
	if (head != null) {
		Node *prev = null;
		Node *p = head;
		while (p != null && p->value != x) {
			prev = p;
			p = p->next;
		}
		if (p != null) {
			if (prev == null) {
				Node *tmp = head;
				head = tmp->next;
				tmp->next = null;
				delete tmp;
			}
			else {
				prev->next = p->next;
				p->next = null;
				delete p;
			}
		}
	}
}

void deleteNodeAtK(Node *&head, int k) {
	if (k > getListSize(head) || k <= 0 || head == null) {
		return;
	}
	else {
		--k;
		int cnt = 0;
		Node *prev = null;
		Node *p = head;
		while (p != null && cnt < k) {
			++cnt;
			prev = p;
			p = p->next;
		}
		if (p != null) {
			if (prev == null) {
				Node *tmp = head;
				head = tmp->next;
				tmp->next = null;
				delete tmp;
			}
			else {
				prev->next = p->next;
				p->next = null;
				delete p;
			}
		}
	}
}

void output(Node *head) {
	while (head != null) {
		cout << head->value << ' ';
		head = head->next;
	}
	cout << '\n';
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	Node *head;
	init(head);
//	addFirst(head, 10);
//	addFirst(head, 20);
//	addFirst(head, 30);
	addLast(head, 10);
	addLast(head, 20);
	addLast(head, 30);
	addAfter(head, 30, 40);
	addAfterK(head, 4, 50);
	output(head);
//	deleteNodeAtK(head, );
	output(head);
}