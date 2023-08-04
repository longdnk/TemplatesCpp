#include <bits/stdc++.h>

using namespace std;

// để tao ra một cây nhị phân tìm kiếm từ cây nhị phân đề cho
// ta duyệt cây theo một thứ tự nhất định (node - left - right)
// với mỗi lần duyệt ta tiến hành gọi hàm chèn kiểm tra nút có hợp lệ hay không 
// sau đó chèn vào cây mới 

// A
struct Node {
    int key;
    Node *left;
    Node *right;
};

void createBST(Node *&root, Node *tmp) {
    if (tmp == nullptr) {
        return;
    }
    insertNode(root, tmp);
    if (root->left != nullptr) {
        createBST(root, tmp->left);
    }
    if (root->right != nullptr) {
        createBST(root, tmp->right);
    }
}

bool insertNode(Node *&root, Node *p) {
    if (root == nullptr) {
        return insert(root, p);
    }
    if (root->key == p->key) {
        return false;
    }
    else if (root->key > p->key) {
        return insertNode(root->left, p);
    }
    else {
        return insertNode(root->right, p);
    }
}

bool insert(Node *&root, Node *p) {
    Node *tmp = new Node;
    if (tmp == nullptr) {
        return false;
    }
    tmp->key = p->key;
    tmp->left = tmp->right = nullptr;
    root = tmp;
    return true;
}

// B
Node *createNode(int x) {
    Node *p = new Node;
    p->key = x;
    p->left = p->right = nullptr;
    return p;
}

bool validSubTree(Node *root, int kRoot, int kLeft, int kRight) {
    Node *tmp = createNode(kRoot);
    tmp->left = createNode(kLeft);
    tmp->right = createNode(kRight);
    return isSubTree(root, tmp);
}

bool isSubTree(Node *root, Node *subRoot) {
    if (checkSubTree(root, subRoot)) {
        return true;
    }
    if (root == nullptr || subRoot == nullptr) {
        return false;
    }
    return isSubTree(root->left, subRoot) || isSubTree(root->right, subRoot);
}

bool checkSubTree(Node *root, Node *subRoot) {
    if (root == nullptr && subRoot == nullptr) {
        return true;
    }
    if (root == nullptr || subRoot == nullptr) {
        return false;
    }
    if (root->key != subRoot->key) {
        return false;
    }
    return checkSubTree(root->left, subRoot->left) && checkSubTree(root->right, subRoot->right);
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}