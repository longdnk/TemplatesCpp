#include <bits/stdc++.h>

using namespace std;

struct Node {
    int key, priority;
    Node *next;

};

struct PriorityQueue {
    Node *head;
};

PriorityQueue *init() {
    PriorityQueue *pq = new PriorityQueue;
    pq->head = nullptr;
    return pq;
}

Node *createNode(int d, int p) {
    Node *temp = new Node;
    temp->key = d;
    temp->priority = p;
    temp->next = nullptr;
    return temp;
}

int peek(PriorityQueue *pq) {
    return pq->head->key;
}

bool isEmpty(PriorityQueue *pq) {
    return pq->head == nullptr;
}

void pop(PriorityQueue *&pq) {
    if (!isEmpty(pq)) {
        cout << peek(pq) << '\n';
        Node *tmp = pq->head;
        pq->head = tmp->next;
        tmp->next = nullptr;
        delete (tmp);
    }
}

void push(PriorityQueue *&pq, int d, int p) {
    Node *start = pq->head;

    Node *temp = createNode(d, p);
    if (isEmpty(pq)) {
        pq->head = temp;
    } else {
        if (pq->head->priority > p) {
            temp->next = pq->head;
            pq->head = temp;
            return;
        } else {
            while (start->next != nullptr && start->next->priority < p) {
                start = start->next;
            }
            temp->next = start->next;
            start->next = temp;
        }
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    PriorityQueue *pq = init();
    push(pq, 4, 1);
    push(pq, 5, 2);
    push(pq, 6, 3);
    push(pq, 7, 0);
    while (!isEmpty(pq)) {
        pop(pq);
    }
}