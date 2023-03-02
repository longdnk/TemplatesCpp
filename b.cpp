#include "bits/stdc++.h"

using namespace std;

//struct SinhVien {
//    string maSo;
//    string hoTen;
//    int namSinh;
//    string lopHoc;
//    float diemTB;
//};
//
//struct Node {
//    SinhVien info;
//    Node *next;
//};
//
//void inputInfo(SinhVien &sv) {
//    cin >> sv.maSo >> sv.hoTen >> sv.namSinh >> sv.lopHoc >> sv.diemTB;
//}
//
//void init(Node *&head) {
//    head = NULL;
//}
//
//Node *createNode(SinhVien x) {
//    Node *p = new Node;
//    p->info = x;
//    p->next = NULL;
//    return p;
//}
//
//void addFirst(Node *&head, SinhVien sv) {
//    Node *p = createNode(sv);
//    p->next = head;
//    head = p;
//}
//
//void addLast(Node *&head, SinhVien sv) {
//    Node *p = createNode(sv);
//    if (head == NULL) {
//        head = p;
//    } else {
//        Node *last = head;
//        while (last->next != NULL) {
//            last = last->next;
//        }
//        last->next = p;
//    }
//}
//
//void addToList(Node *head, SinhVien sv) {
//    inputInfo(sv);
//    addFirst(head, sv);
//}
//
//float findMax(Node *head) {
//    float max = 0;
//    Node *p = head;
//    while (p != NULL) {
//        if (max < p->info.diemTB) {
//            max = p->info.diemTB;
//        }
//        p = p->next;
//    }
//    return max;
//}
//
//void outputInfo(SinhVien sv) {
//    cout << "Ma so: " << sv.maSo << '\n';
//    cout << "Ho ten: " << sv.hoTen << '\n';
//    cout << "Nam sinh: " << sv.namSinh << '\n';
//    cout << "Lop hoc: " << sv.lopHoc << '\n';
//    cout << "Diem TB: " << sv.diemTB << '\n';
//}
//
//void outputMax(Node *head) {
//    Node *p = head;
//    float maxValue = findMax(head);
//    while (p != NULL) {
//        if (p->info.diemTB == maxValue) {
//            outputInfo(p->info);
//        }
//        p = p->next;
//    }
//}
//
//Node *mid_point(Node *head) {
//    if (head == NULL || head->next == NULL) {
//        return head;
//    }
//
//    Node *fast = head;
//    Node *slow = head;
//
//    while (fast != NULL && fast->next != NULL) {
//        fast = fast->next;
//
//        if (fast->next == NULL)
//            break;
//
//        fast = fast->next;
//        slow = slow->next;
//    }
//
//    return slow;
//}
//
//Node *merge(Node *a, Node *b) {
//    if (a == NULL) {
//        return b;
//    }
//    if (b == NULL) {
//        return a;
//    }
//
//    Node *c;
//    if (a->info.diemTB < b->info.diemTB) {
//        c = a;
//        c->next = merge(a->next, b);
//    } else {
//        c = b;
//        c->next = merge(a, b->next);
//    }
//    return c;
//}
//
//Node *sort(Node *head) {
//    if (head == NULL || head->next == NULL) {
//        return head;
//    }
//    Node *mid = mid_point(head);
//    Node *a = head;
//    Node *b = mid->next;
//    mid->next = NULL;
//    a = sort(a);
//    b = sort(b);
//    Node *c = merge(a, b);
//    return c;
//}
//
//void outputRes(Node *head) {
//    sort(head);
//    Node *p = head;
//    while (p != NULL) {
//        outputInfo(p->info);
//        p = p->next;
//    }
//}
//
//int tinhFn(int n, int a) {
//    int *f = new int[n + 1];
//    f[0] = a;
//    f[1] = 2 * a;
//    for (int i = 2; i <= n; ++i) {
//        f[i] = 2 * f[i - 1] + 3 * f[i - 2];
//    }
//    return f[n];
//}
//
//int timFn(int a, int M) {
//    int l = 1, r = M + 1, mid, res = -1;
//    while (l <= r) {
//        mid = (r + l) >> 1;
//        if (tinhFn(mid, a) > M) {
//            res = mid;
//            r = mid - 1;
//        } else {
//            l = mid + 1;
//        }
//    }
//    return res;
//}
//
//int32_t main() {
//    ios::sync_with_stdio(false);
//    cin.tie(nullptr);
//    cout.tie(nullptr);
//}

//struct NgayBay {
//    int ngay, thang, nam;
//};
//
//struct ChuyenBay {
//    string maSo;
//    string hoTen;
//    NgayBay ngayBay;
//    int sucChua;
//};
//
//struct Node {
//    ChuyenBay info;
//    Node *pNext {};
//};
//
//void init(Node *&head) {
//    head = nullptr;
//}
//
//Node *createNode(ChuyenBay x) {
//    Node *p = new Node();
//    p->info = x;
//    p->pNext = nullptr;
//    return p;
//}
//
//void addFirst(Node *&head, ChuyenBay x) {
//    Node *p = createNode(x);
//    p->pNext = head;
//    head = p;
//}
//
//void addLast(Node *&head, ChuyenBay x) {
//    Node *p = createNode(x);
//    if (head == nullptr) {
//        head = p;
//    } else {
//        Node *last = head;
//        while (last->pNext != nullptr) {
//            last = last->pNext;
//        }
//        last->pNext = p;
//    }
//}
//
//void inputInfo(ChuyenBay &x) {
//    cin >> x.maSo >> x.hoTen >> x.ngayBay.ngay >> x.ngayBay.thang >> x.ngayBay.nam >> x.sucChua;
//}
//
//void outputInfo(ChuyenBay x) {
//    cout << "===Info===" << '\n';
//    cout << "Code " << x.maSo << '\n';
//    cout << "Name: " << x.hoTen << '\n';
//    cout << "Date: " << x.ngayBay.ngay << '/' << x.ngayBay.thang << '/' << x.ngayBay.nam << '\n';
//    cout << "Tanked: " << x.sucChua << '\n';
//    cout << "===Info===" << "\n\n";
//}
//
//void input(Node *&head, int n) {
//    cin >> n;
//    ChuyenBay c;
//    for (int i = 1; i <= n; ++i) {
//        inputInfo(c);
////        addFirst(head, c);
//        addLast(head, c);
//    }
//}
//
//int findMax(Node *head) {
//    Node *p = head;
//    int maxTank = 0;
//    while (p != nullptr) {
//        if (maxTank < p->info.sucChua) {
//            maxTank = p->info.sucChua;
//        }
//        p = p->pNext;
//    }
//    return maxTank;
//}
//
//void outputMax(Node *head) {
//    Node *p = head;
//    int max = findMax(head);
//    while (p != nullptr) {
//        if (p->info.sucChua == max) {
//            outputInfo(p->info);
//        }
//        p = p->pNext;
//    }
//}
//
//void output(Node *head) {
//    Node *p = head;
//    while (p != nullptr) {
//        outputInfo(p->info);
//        p = p->pNext;
//    }
//}

//int32_t main() {
//    ios::sync_with_stdio(false);
//    cin.tie(nullptr);
//    cout.tie(nullptr);
//    Node *head;
//    init(head);
//    ChuyenBay c1, c2, c3, c4;
//    c1.maSo = "1";
//    c1.hoTen = "Nguyen Van A";
//    c1.ngayBay.ngay = 12;
//    c1.ngayBay.thang = 10;
//    c1.ngayBay.ngay = 2023;
//    c1.sucChua = 123;
//
//    c2.maSo = "2";
//    c2.hoTen = "Nguyen Van B";
//    c2.ngayBay.ngay = 13;
//    c2.ngayBay.thang = 10;
//    c2.ngayBay.ngay = 2023;
//    c2.sucChua = 123;
//
//    c3.maSo = "3";
//    c3.hoTen = "Nguyen Van C";
//    c3.ngayBay.ngay = 14;
//    c3.ngayBay.thang = 10;
//    c3.ngayBay.ngay = 2023;
//    c3.sucChua = 110;
//
//    c4.maSo = "4";
//    c4.hoTen = "Nguyen Van D";
//    c4.ngayBay.ngay = 15;
//    c4.ngayBay.thang = 10;
//    c4.ngayBay.ngay = 2023;
//    c4.sucChua = 110;
//    addLast(head, c1);
//    addLast(head, c2);
//    addLast(head, c3);
//    addLast(head, c4);
//    outputMax(head);
////    output(head);
//}

struct Node {
    //khai bao du lieu cua node co kieu du lieu int
    int value;
    //khai bao con tro den cay con trai
    Node *left;
    //khai bao con tro den cay con phai
    Node *right;
};
typedef struct Node *Tree;
Tree root;

void insertNode(Tree &root, Node *p) {
    if (root != NULL) {
        if (root->value == p->value) {
            return;
        }
        if (root->value > p->value) {
            insertNode(root->left, p);
        } else {
            insertNode(root->right, p);
        }
    } else {
        root = p;
    }
}