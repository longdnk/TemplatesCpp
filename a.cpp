#include <bits/stdc++.h>

using namespace std;
const int maxN = 1e6 + 9;

bool memo[maxN][15];
int ans[maxN], n, m, q, u, v, d, c;
vector<vector<int>> a;

struct Stack {
    struct Node {
        struct query {
            int u, d, c;
        } data;
        Node *next;
    } *top;
    typedef Stack stack;
    typedef Stack::Node node;
    typedef node::query query;

    stack *initStack() {
        stack *s = new stack;
        s->top = nullptr;
        return s;
    }

    node *createNode(query data) {
        node *p = new node;
        p->data = data;
        p->next = nullptr;
        return p;
    }

    void push(stack *&s, query data) {
        node *p = createNode(data);
        p->next = s->top;
        s->top = p;
    }

    bool isEmpty(stack *s) {
        return s->top == nullptr;
    }

    void pop(stack *&s) {
        if (!isEmpty(s)) {
            node *p = s->top;
            s->top = p->next;
            p->next = nullptr;
            delete p;
        }
    }
};

void dfs(int u, int d, int c) {
    if (memo[u][d] || d < 0) {
        return;
    }
    memo[u][d] = true;
    if (!ans[u]) {
        ans[u] = c;
    }
    for (auto v: a[u]) {
        dfs(v, d - 1, c);
    }
}

void resolve(Stack *s) {
    auto [u, d, c] = s->top->data;
    dfs(u, d, c);
    s->pop(s);
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n >> m;

    Stack *s = s->initStack();
    a = *new vector<vector<int>>(n + 1);

    for (int i = 1; i <= m; ++i) {
        cin >> u >> v;
        a[u].emplace_back(v);
        a[v].emplace_back(u);
    }

    cin >> q;

    for (int i = 1; i <= q; ++i) {
        cin >> u >> d >> c;
        s->push(s, { u, d, c });
    }
    while (!s->isEmpty(s)) {
        resolve(s);
    }
    for (int i = 1; i <= n; ++i) {
        cout << ans[i] << '\n';
    }
}
