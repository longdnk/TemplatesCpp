#include <bits/stdc++.h>

using namespace std;

struct Node {
    int key;
    Node *next;
    Node *prev;
    Node() = default;
    Node(int x) : key(x), next(NULL), prev(NULL) { }
};

struct Deque {
    Node *head;
    Node *tail;
    Deque() : head(NULL), tail(NULL) { }
};

void pushFront(Deque *&dq, int k) {
    Node *p = new Node(k);
    p->next = dq->head;
    if (dq->head == NULL) {
        dq->head = dq->tail = p;
    }
    else {
        dq->head->prev = p;
        dq->head = p;
    }
}

void pushBack(Deque *&dq, int k) {
    Node *p = new Node(k);
    p->prev = dq->tail;
    if (dq->head == NULL) {
        dq->head = dq->tail = p;
    }
    else {
        dq->tail->next = p;
        dq->tail = p;
    }
}

int getFront(Deque *dq) {
    if (dq->head == NULL) {
        return -1e9;
    }
    return dq->head->key;
}

int getRear(Deque *dq) {
    if (dq->head == NULL) {
        return -1e9;
    }
    return dq->tail->key;
}

void popFront(Deque *&dq) {
    if (dq->head == NULL) {
        return;
    }
    Node *tmp = dq->head;
    dq->head = tmp->next;
    tmp->next = NULL;
    if (dq->head == NULL) {
        dq->tail = NULL;
    }
    else {
        dq->head->prev = NULL;
    }
    delete tmp;
}

void popBack(Deque *&dq) {
    if (dq->tail == NULL) {
        return;
    }
    Node *temp = dq->tail;
    dq->tail = temp->prev;
    temp->prev = NULL;
    if (dq->tail == NULL) {
        dq->head = NULL;
    }
    else {
        dq->tail->next = NULL;
    }
    delete temp;
}

void printDeque(Deque *dq) {
    if (dq->head == NULL) {
        return;
    }
    Node *current = dq->head;
    while (current != NULL) {
        cout << current->key << ' ';
        current = current->next;
    }
    cout << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    Deque *dq = new Deque;
    pushFront(dq, 1);
    pushFront(dq, 2);
    pushBack(dq, 3);
    pushBack(dq, 4);
    printDeque(dq);
    int frontElement = getFront(dq);
    int backElement = getRear(dq);
    cout << "Front: " << frontElement << '\n';
    cout << "Rear: " << backElement << '\n';
    popFront(dq);
    popBack(dq);
    printDeque(dq);
}