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
		Node *p = createNode(x);
		Node *q = head;
		int cnt = 1;
		while (q != null && cnt != k) {
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
			last->next = null;
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

bool deleteNodeAtK(Node *&head, int k) {
	if (k > getListSize(head) || k <= 0 || head == null) {
		return false;
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
		return true;
	}
}

void sortList(Node *&head) {
	if (head == null) {
		return;
	}
	else {
		Node *current = head, *index = null;
		while (current != null) {
			index = current->next;
			while (index != null) {
				if (current->value > index->value) {
					int tmp = current->value;
					current->value = index->value;
					index->value = tmp;
				}
				index = index->next;
			}
			current = current->next;
		}
	}
}

void removeDuplicate(Node *&head) {
	const int maxN = 1e5 + 9;
	int cnt[maxN] = {};
	Node *p = head;
	Node *tmp = null;
	while (p != null) {
		++cnt[p->value];
		p = p->next;
	}
	p = head;
	while (p != null) {
		if (cnt[p->value] == 1) {
			addLast(tmp, p->value);
		}
		p = p->next;
	}
	head = tmp;
}

bool isExist(Node *head, int x) {
	Node *p = head;
	while (p != null) {
		if (p->value == x) {
			return true;
		}
		p = p->next;
	}
	return false;
}

void deleteNodeHaveValue(Node *&head, int x) {
	while (isExist(head, x)) {
		deleteNode(head, x);
	}
}

void output(Node *head) {
	while (head != null) {
		cout << head->value << ' ';
		head = head->next;
	}
	cout << '\n';
}

struct Stack {
	Node *top;
};

Stack *initStack() {
	Stack *s = new Stack;
	s->top = null;
	return s;
}

void push(Stack *&s, int x) {
	Node *p = createNode(x);
	p->next = s->top;
	s->top = p;
}

int getPeek(Stack *s) {
	return s->top->value;
}

void pop(Stack *&s) {
	if (s->top != null) {
		cout << getPeek(s) << '\n';
		Node *p = s->top;
		s->top = p->next;
		p->next = null;
		delete p;
	}
}

struct Queue {
	Node *head;
	Node *tail;
};

Queue *initQueue() {
	Queue *q = new Queue;
	q->head = q->tail = null;
	return q;

}

void enQueue(Queue *&q, int x) {
	Node *p = createNode(x);
	if (q->head == null) {
		q->head = q->tail = p;
	}
	else {
		q->tail->next = p;
		q->tail = p;
	}
}

int getFront(Queue *q) {
	return q->head->value;
}

void deQueue(Queue *&q) {
	if (q->head != null) {
		cout << getFront(q) << '\n';
		Node *p = q->head;
		q->head = p->next;
		p->next = null;
		delete p;
		if (q->head == null) {
			q->tail = null;
		}
	}
}

void sortQueue(Queue *&q) {
	Node *current = q->head, *index = null;
	while (current != null) {
		index = current->next;
		while (index != null) {
			if (current->value > index->value) {
				int tmp = current->value;
				current->value = index->value;
				index->value = tmp;
			}
			index = index->next;
		}
		current = current->next;
	}
}

void out(Queue *q) {
	Node *tmp = q->head;
	while (tmp != null) {
		cout << tmp->value << ' ';
		tmp = tmp->next;
	}
	cout << '\n';
}

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
//	Node *head;
//	init(head);
//	addFirst(head, 10);
//	addFirst(head, 20);
//	addFirst(head, 30);
//	addLast(head, 10);
//	addLast(head, 20);
//	addLast(head, 30);
//	addAfter(head, 30, 40);
//	addAfterK(head, 4, 50);
//	output(head);
//	deleteNode(head, 30);
//	deleteNodeAtK(head, 3);
//	sortList(head);
//	output(head);
//	deleteNodeHaveValue(head, 10);
//	output(head);
//	removeDuplicate(head);
//	output(head);
//	Stack *s = initStack();
//	push(s, 10);
//	push(s, 20);
//	push(s, 30);
//	while (s->top != null) {
//		pop(s);
//	}
	Queue *q = initQueue();
	enQueue(q, 10);
	enQueue(q, 30);
	enQueue(q, 20);
	enQueue(q, 40);
	out(q);
	sortQueue(q);
	out(q);
}