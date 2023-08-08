#include <bits/stdc++.h>

using namespace std;

struct Node {
    int key;
    Node *next;
};

struct List {
    Node *head;
    Node *tail;
    List() : head(nullptr), tail(nullptr) { }
};

bool addHead(List *&ls, int k) {
    Node *p = new Node;
    if (p == nullptr) {
        return false;
    }
    p->key = k;
    p->next = nullptr;
    if (ls->head == nullptr) {
        ls->head = ls->tail = p;
    }
    else {
        p->next = ls->head;
        ls->head = p;
        ls->tail->next = p;
    }
    return true;
}

void output(List *ls) {
    if (ls->head) {
        Node *p = ls->head;
        do {
            cout << p->key << ' ';
            p = p->next;
        } while (p != ls->head);
    }
    cout << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    List *ls = new List;
    addHead(ls, 10);
    addHead(ls, 20);
    addHead(ls, 30);
    output(ls);
}