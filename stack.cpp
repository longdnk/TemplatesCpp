#include <bits/stdc++.h>

using namespace std;
#define null NULL

struct Node {
    int value;
    Node *next;
};

struct Stack {
    Node *top;
};

Stack *initStack() {
    Stack *s = new Stack;
    s->top = null;
    return s;
}

Node *createNode(int x) {
    Node *p = new Node;
    p->value = x;
    p->next = null;
    return p;
}

void push(Stack *&s, int x) {
    Node *p = createNode(x);
    p->next = s->top;
    s->top = p;
}

int getPeek(Stack *s) {
    return s->top->value;
}

bool isEmpty(Stack *s) {
    return s->top == null;
}

void pop(Stack *&s) {
    if (!isEmpty(s)) {
        cout << getPeek(s) << '\n';
        Node *p = s->top;
        s->top = p->next;
        p->next = null;
        delete p;
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    Stack *s = initStack();
    push(s, 10);
    push(s, 20);
    push(s, 30);
    while (!isEmpty(s)) {
        pop(s);
    }
}