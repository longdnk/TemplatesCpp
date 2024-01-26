#include <bits/stdc++.h>

using namespace std;

template <class T>
struct Node {
    int key;
    Node *pLeft;
    Node *pRight;
    Node *pParent;
};

Node<class T> *createNode(int x);
bool insert(Node<T> *&root, int k, Node<T> *parent);
void insertNode(Node<T> *&root, int k);
Node<T> *convertArrayToTree(int a[], int n);
Node<T> *findSuccessor(Node<T> *tmp);
void traversal(Node<T> *root);
int remove(Node<T> *&root);
int removeNode(Node<T> *&root, int k);

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int a[] = {8, 10, 3, 1, 6, 14, 4, 7, 13};
    int n = sizeof(a) / sizeof(a[0]);
    Node<T> *root = convertArrayToTree(a, n);
    removeNode(root, 13);
    traversal(root);
}

void insertNode(Node<T> *&root, int k) {
    insert(root, k, root);
}

bool insert(Node<T> *&root, int k, Node<T> *parent) {
    if (root == nullptr) {
        Node<T> *p = createNode(k);
        if (p == nullptr) {
            return false;
        }
        p->pParent = parent;
        root = p;
        return true;
    }
    if (root->key == k) {
        return false;
    }
    else if (root->key > k) {
        return insert(root->pLeft, k, root);
    }
    else {
        return insert(root->pRight, k, root);
    }
}

Node<class T> *createNode(int x) {
    Node<T> *p = new Node<T>;
    if (p == nullptr) {
        return nullptr;
    }
    p->key = x;
    p->pLeft = p->pRight = p->pParent = nullptr;
    return p;
}

Node<T> *convertArrayToTree(int a[], int n) {
    Node<T> *root = nullptr;
    for (int i = 0; i < n; ++i) {
        insertNode(root, a[i]);
    }
    return root;
}

Node<T> *searchTree(Node<T> *root, int k) {
    if (root == nullptr || root->key == k) {
        return root;
    }
    else if (root->key > k) {
        return searchTree(root->pLeft, k);
    }
    else {
        return searchTree(root->pRight, k);
    }
}

// Node<T> *searchTree(Node<T> *root, int k) {
//     Node<T> *p = root;
//     while (p != nullptr && p->key != k) {
//         if (p->key > k) {
//             p = p->pLeft;
//         }
//         else {
//             p = p->pRight;
//         }
//     }
//     return p;
// }

int removeNode(Node<T> *&root, int k) {
    Node<T> *tmp = searchTree(root, k);
    if (tmp == nullptr) {
        return 0;
    }
    return remove(tmp);
}

int remove(Node<T> *&root) {
    if (root->pLeft == nullptr && root->pRight == nullptr) { // Leaf
        if (root->key < (root->pParent)->key) {
            (root->pParent)->pLeft = nullptr;
        }
        else {
            (root->pParent)->pRight = nullptr;
        }
        root = nullptr;
        delete root;
    }
    else if (root->pLeft == nullptr || root->pRight == nullptr) { // 1 Sub tree
        if (root->key < (root->pParent)->key) {
            (root->pParent)->pLeft = root->pRight ?: root->pLeft;
            if (root->pLeft) {
                (root->pLeft)->pParent = root->pParent;
            }
            else {
                (root->pRight)->pRight = root->pParent;
            }
        }
        else {
            (root->pParent)->pRight = root->pLeft ?: root->pRight;
            if (root->pLeft) {
                (root->pLeft)->pParent = root->pParent;
            }
            else {
                (root->pRight)->pParent = root->pParent;
            }
        }
        root = nullptr;
        delete root;
    }
    else { // 2 Sub + Root
        Node<T> *successor = findSuccessor(root);
        root->key = successor->key;
        return removeNode(root->pRight, successor->key);
    }
    return 1;
}

Node<T> *findSuccessor(Node<T> *tmp) {
    tmp = tmp->pRight;
    while (tmp->pLeft) {
        tmp = tmp->pLeft;
    }
    return tmp;
}

void traversal(Node<T> *root) {
    if (root == nullptr) {
        return;
    }
    cout << root->key << ' ' << (root->pParent ? (root->pParent)->key : 0) << '\n';
    traversal(root->pLeft);
    traversal(root->pRight);
}