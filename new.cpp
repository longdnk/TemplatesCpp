#include <bits/stdc++.h>

using namespace std;
#define null NULL

struct Node {
	int value;
	Node next;
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

bool isEmpty(Node *head) {
	return head == null;
}

void addLast(Node *&head, int x) {
	Node *p = createNode(x);
	if (isEmpty(head)) {
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
	while (!isEmpty(head)) {
		++size;
		head = head->next;
	}
	return size;
}

void addAfterK(Node *&head, int k, int x) {
	if (k > getListSize(head) || k <= 0 || isEmpty(head)) {
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
	if (!isEmpty(head)) {
		Node *p = head;
		head = p->next;
		p->next = null;
		delete p;
	}
}

void deleteLast(Node *&head) {
	if (!isEmpty(head)) {
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

void deleteNode(Node *&head, int v) {
	if (!isEmpty(head)) {
		Node *prev = null;
		Node *p = head;
		while (p != null && p->value != v) {
			prev = p;
			p = p->next;
		}
		if (p != null) {
			if (prev == null) {
				deleteFirst(head);
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
	if (k <= 0 || k > getListSize(head) || isEmpty(head)) {
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

void change(int &a, int &b) {
	int tmp = a;
	a = b;
	b = tmp;
}

void sortList(Node *&head) {
	Node *current = head, *index = null;
	if (!isEmpty(head)) {
		while (current != null) {
			index = current->next;
			while (index != null) {
				if (current->value > index->value) {
					change(current->value, index->value);
				}
				index = index->next;
			}
			current = current->next;
		}
	}
}

void output(Node *head) {
	while (!isEmpty(head)) {
		cout << head->value << ' ';
		head = head->next;
	}
	cout << '\n';
}

bool isExist(Node *head, int v) {
	while (!isEmpty(head)) {
		if (head->value == v) {
			return true;
		}
		head = head->next;
	}
	return false;
}

void deleteNodeHaveValue(Node *&head, int v) {
	while (isExist(head, v)) {
		deleteNode(head, v);
	}
}

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
}