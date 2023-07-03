#include <bits/stdc++.h>

using namespace std;

struct Node {
    int key;
    Node *prev;
    Node *next;
};

bool deleteNodeAtK(Node *&head, int k) {
    if (k > getListSize(head) || k <= 0 || isEmpty(head)) {
        return false;
    }
    Node *p = head;
    while (p != NULL && k > 1) {
        --k;
        p = p->next;
    }
    if (p != NULL) {
        if (p->prev != NULL) {
            p->prev->next = p->next;
        }
        else {
            head = p->next;
        }
        if (p->next != NULL) {
            p->next->prev = p->prev;
        }
        delete p;
        return true;
    }
}

int getListSize(Node *head) {
    if (isEmpty(head)) {
        return 0;
    }
    return getListSize(head->next) + 1;
}

bool isEmpty(Node *head) {
    return head == NULL;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}
