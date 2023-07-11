#include <bits/stdc++.h>

using namespace std;

struct Data {
    int value;
    int priority;
};

struct Node {
    Data key;
    Node *next;
};

struct Queue {
    Node *head;
    Node *tail;
    Queue() : head(NULL), tail(NULL) { }
};

Node *createNode(Data x) {
    Node *p = new Node;
    p->key = x;
    p->next = NULL;
    return p;
}

bool isEmpty(Queue *q) {
    return q->head == NULL;
}

void enQueue(Queue *&q, Data k) {
    Node *p = createNode(k);
    if (isEmpty(q)) {
        q->head = q->tail = p;
    }
    else {
        Node *tmp = q->head;
        Node *prev = NULL;
        while (tmp != NULL && tmp->key.priority > k.priority) {
            prev = tmp;
            tmp = tmp->next;
        }
        if (tmp != NULL) {
            if (prev == NULL) {
                p->next = q->head;
                q->head = p;
            }
            else {
                p->next = prev->next;
                prev->next = p;
            }
        }
        if (tmp == NULL) {
            q->tail->next = p;
            q->tail = p;
        }
    }
}

bool deQueue(Queue *&q) {
    if (!isEmpty(q)) {
        Node *p = q->head;
        q->head = p->next;
        p->next = NULL;
        delete p;
        if (isEmpty(q)) {
            q->tail = NULL;
        }
        return true;
    }
    return false;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    Queue *q = new Queue;
    enQueue(q, { 1, 3 });
    enQueue(q, { 2, 5 });
    enQueue(q, { 10, 1 });
    enQueue(q, { 11, 2 });
    while (!isEmpty(q)) {
        auto [value, priority] = q->head->key;
        cout << value << ' ' << priority << '\n';
        q->head = q->head->next;
    }
}