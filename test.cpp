#include <bits/stdc++.h>

using namespace std;

struct Node {
    int key;
    Node *left;
    Node *right;
};

Node *createNode(int x);

void insertNode(Node *&root, int k) {
    if (root == NULL) {
        root = createNode(k);
    }
    else if (root->key == k) {
        return;
    }
    else if (root->key > k) {
        insertNode(root->left, k);
    }
    else {
        insertNode(root->right, k);
    }
}

Node *createNode(int x) {
    Node *p = new Node;
    p->key = x;
    p->left = p->right = NULL;
    return p;
}

Node *searchTree(Node *root, int k) {
    if (root == NULL || root->key == k) {
        return root;
    }
    else if (root->key > k) {
        return searchTree(root->left, k);
    }
    else {
        return searchTree(root->right, k);
    }
}

Node *searchNode(Node *root, int k) {
    Node *p = root;
    while (p != NULL && p->key != k) {
        if (p->key > k) {
            p = p->left;
        }
        else {
            p = p->right;
        }
    }
    return p;
}

Node *findMaxEvenX(Node *root, int x) {
    if (root == NULL) {
        return NULL;
    }
    else if (root->key > x) {
        return findMaxEvenX(root->left, x);
    }
    Node *tmp = findMaxEvenX(root->right, x);
    if (tmp != NULL) {
        return tmp;
    }
    if (root->key <= x && root->key % 2 == 0) {
        return root;
    }
    return findMaxEvenX(root->left, x);
}

Node *findMinOddX(Node *root, int x) {
    if (root == NULL) {
        return NULL;
    }
    else if (root->key < x) {
        return findMinOddX(root->right, x);
    }
    Node *tmp = findMinOddX(root->left, x);
    if (tmp != NULL) {
        return tmp;
    }
    if (root->key >= x && root->key % 2 != 0) {
        return root;
    }
    return findMinOddX(root->right, x);
}

int remove(Node *&root, int x);
Node *findSuccessor(Node *tmp);

int removeNode(Node *&root, int k) {
    Node *tmp = searchTree(root, k);
    if (tmp == NULL) {
        return 0;
    }
    return remove(root, k);
}

int remove(Node *&root, int x) {
    if (root->key > x) {
        return removeNode(root->left, x);
    }
    else if (root->key < x) {
        return removeNode(root->right, x);
    }
    else {
        if (root->left == NULL || root->right == NULL) {
            Node *tmp = root->left ? root->left : root->right;
            delete root;
            root = tmp;
        }
        else {
            Node *successor = findSuccessor(root);
            root->key = successor->key;
            return removeNode(root->right, successor->key);
        }
    }
    return 1;
}

Node *findSuccessor(Node *tmp) {
    tmp = tmp->right;
    while (tmp->left != NULL) {
        tmp = tmp->left;
    }
    return tmp;
}

void printLeafs(Node *root) {
    if (root == NULL) {
        return;
    }
    printLeafs(root->right);
    printLeafs(root->left);
    if (root->left == NULL && root->right == NULL) {
        cout << root->key << ' ';
    }
}

bool validBST(Node *root, int left, int right) ;

bool checkBST(Node *root) {
    if (root == NULL) {
        return false;
    }
    return validBST(root, -1e9, 1e9);
}

bool validBST(Node *root, int left, int right) {
    if (root == NULL) {
        return true;
    }
    if (root->key <= left && root->key >= right) {
        return false;
    }
    return validBST(root->left, left, root->key) && validBST(root->right, root->key, right);
}

bool validEvenTree(Node *root);

bool checkEvenTree(Node *root) {
    if (root == NULL) {
        return false;
    }
    return validEvenTree(root);
}

bool validEvenTree(Node *root) {
    if (root == NULL) {
        return true;
    }
    if (root->key % 2 != 0) {
        return false;
    }
    return validEvenTree(root->left) && validEvenTree(root->right);
}

bool checkSubTree(Node *root, Node *subRoot);

bool isSubTree(Node *root, Node *subRoot) {
    if (checkSubTree(root, subRoot)) {
        return true;
    }
    if (root == NULL || subRoot == NULL) {
        return false;
    }
    return isSubTree(root->left, subRoot) || isSubTree(root->right, subRoot);
}

bool checkSubTree(Node *root, Node *subRoot) {
    if (root == NULL && subRoot == NULL) {
        return true;
    }
    if (root == NULL || subRoot == NULL) {
        return false;
    }
    if (root->key != subRoot->key) {
        return false;
    }
    return checkSubTree(root->left, subRoot->left) && checkSubTree(root->right, subRoot->right);
}

void createBST(Node *root, Node *&tmp, int left, int right);

Node *trimBST(Node *root, int low, int high) {
    Node *tmp = NULL;
    createBST(root, tmp, low, high);
    return tmp;
}

void createBST(Node *root, Node *&tmp, int left, int right) {
    if (root == NULL) {
        return;
    }
    if (root->key >= left && root->key <= right) {
        insertNode(tmp, root->key);
    }
    createBST(root->left, tmp, left, right);
    createBST(root->right, tmp, left, right);
}

void traversal(Node *root, int *cnt);

bool isUniqueTree(Node *root) {
    if (root == NULL) {
        return false;
    }
    int cnt[109] = { };
    int nxt = 0;
    traversal(root, cnt);
    for (int i = 0; i <= 100; ++i) {
        if (cnt[i] >= 1) {
            ++nxt;
        }
    }
    return nxt == 1;
}

void traversal(Node *root, int *cnt) {
    if (root == NULL) {
        return;
    }
    ++cnt[root->key];
    traversal(root->left, cnt);
    traversal(root->right, cnt);
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}