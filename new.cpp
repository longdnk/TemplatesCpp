#include <bits/stdc++.h>

using namespace std;
#define null NULL

struct Stack {
    struct Node {
        int value;
        Node *next;
    } *top;

    Stack *initStack() {
        Stack *s = new Stack;
        s->top = null;
        return s;
    }

    Stack::Node *createNode(int x) {
        Node *p = new Node;
        p->value = x;
        p->next = null;
        return p;
    }

    bool isEmpty(Stack *s) {
        return s->top == null;
    }

    void push(Stack *&s, int x) {
        Node *p = createNode(x);
        p->next = s->top;
        s->top = p;
    }

    void pop(Stack *&s) {
        if (!isEmpty(s)) {
            Node *p = s->top;
            s->top = p->next;
            p->next = null;
            delete p;
        }
    }
};

struct Queue {
    struct Node {
        int value;
        Node *next;
    } *head, *tail;

    Queue *initQueue() {
        Queue *q = new Queue;
        q->head = q->tail = null;
        return q;
    }

    Queue::Node *createNode(int x) {
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
            return;
        }
        q->tail->next = p;
        q->tail = p;
    }

    void deQueue(Queue *&q) {
        if (!isEmpty(q)) {
            Node *p = q->head;
            q->head = p->next;
            p->next = null;
            delete p;
            if (isEmpty(q)) {
                q->tail = null;
            }
        }
    }
};

struct Node {
    int value;
    Node *next;
};

Node *createNode(int x) {
    Node *p = new Node;
    p->value = x;
    p->next = null;
    return p;
}

void init(Node *&head) {
    head = null;
}

bool isEmpty(Node *head) {
    return head == null;
}

void addFirst(Node *&head, int x) {
    Node *p = createNode(x);
    p->next = head;
    head = p;
}

void addLast(Node *&head, int x) {
    Node *p = createNode(x);
    if (isEmpty(head)) {
        head = p;
    } else {
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

void addNodeAtK(Node *&head, int x, int k) {
    if (k <= 0 || k > getListSize(head) || isEmpty(head)) {
        return;
    } else {
        --k;
        Node *p = createNode(x);
        Node *q = head;
        int cnt = 0;
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
        Node *prev = head;
        Node *last = head;
        while (last->next != null) {
            prev = last;
            last = last->next;
        }
        prev->next = null;
        delete last;
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
                Node *tmp = head;
                head = tmp->next;
                tmp->next = null;
                delete tmp;
            } else {
                prev->next = p->next;
                p->next = null;
                delete p;
            }
        }
    }
}

void deleteNodeAtK(Node *&head, int k) {
    if (k > getListSize(head) || k <= 0 || isEmpty(head)) {
        return;
    } else {
        --k;
        Node *prev = null;
        Node *p = head;
        int cnt = 0;
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
            } else {
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
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    Node *head;
    init(head);
    addLast(head, 10);
    addLast(head, 20);
    addLast(head, 30);
    addAfter(head, 30, 40);
    output(head);
    addNodeAtK(head, 100, 4);
    deleteNodeAtK(head, 5);
    output(head);
}