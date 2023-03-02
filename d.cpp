#include <bits/stdc++.h>

using namespace std;
#define null NULL

struct QNode {
    int key;
    QNode *next;
};

struct Queue {
    struct QNode *front, *rear;
};

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    auto initQueue = [&](Queue *&q) -> void {
        q = new Queue;
        q->front = q->rear = null;
    };

    auto enQueue = [&](Queue *&q, int k) -> void {

        auto createElement = [&](int k) -> QNode * {
            auto *temp = new QNode;
            temp->key = k;
            temp->next = null;
            return temp;
        };

        QNode *temp = createElement(k);

        if (q->rear == null) {
            q->front = q->rear = temp;
            return;
        }

        q->rear->next = temp;
        q->rear = temp;
    };

    auto deQueue = [&](Queue *&q) -> void {
        if (q->front == null) {
            return;
        }

        QNode *temp = q->front;

        q->front = q->front->next;

        if (q->front == null) {
            q->rear = null;
        }

        delete (temp);
    };

    Queue *q;
    initQueue(q);
    enQueue(q, 10);
    enQueue(q, 20);
    enQueue(q, 30);
    while (q->front != null) {
        cout << q->front->key << '\n';
        deQueue(q);
    }
}