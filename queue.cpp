#include <bits/stdc++.h>

using namespace std;

#define null NULL

struct Node {
    int value;
    Node next;
};

struct Queue {
    Node *head;
    Node *tail;
};

Queue *initQueue() {
    Queue *q = new Queue;
    q->head = q->tail = null;
    return q;
}

Node *createNode(int x) {
    Node *p = new Node;
    p->value = x;
    p->next = null;
    return p;
}

bool isEmpty(Queue *q) {
    return q->head == null;
}

void enQueue(Queue *&q, int x) {
    Node *p = createNode(x);
    if (isEmpty(q)) {
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
    if (!isEmpty(q)) {
        cout << getFront(q) << '\n';
        Node *p = q->head;
        q->head = p->next;
        p->next = null;
        delete p;
        if (isEmpty(q)) {
            q->tail = null;
        }
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    Queue *q = initQueue();
    enQueue(q, 10);
    enQueue(q, 20);
    enQueue(q, 30);
    while (!isEmpty(q)) {
        deQueue(q);
    }
}