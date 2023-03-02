#include<bits/stdc++.h>

using namespace std;
#define null NULL

const int maxN = 1e6 + 9;
bool memo[maxN][15];
int ans[maxN], n, m, q;
vector<vector<int>> a;

struct Stack {
    struct Node {
        struct query {
            int u, d, c;
        } param;
        Node *next;
    } *top;

    static Stack *initStack() {
        auto *s = new Stack;
        s->top = null;
        return s;
    }

    Stack::Node *createNode(Stack::Node::query x) {
        auto *p = new Stack::Node;
        p->param = x;
        p->next = null;
        return p;
    }

    void push(Stack *&s, Stack::Node::query params) {
        Stack::Node *p = createNode(params);
        p->next = s->top;
        s->top = p;
    }

    bool isEmpty(Stack *s) {
        return s->top == null;
    };

    void pop(Stack *&s) {
        if (!isEmpty(s)) {
            Stack::Node *p = s->top;
            s->top = p->next;
            p->next = null;
            delete p;
        }
    }
};

Stack *s = Stack::initStack();

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

void search(Stack *stack, Stack::Node::query params) {
    auto [u, d, c] = params;
    {
        dfs(u, d, c);
        s->pop(stack);
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n >> m;
    a = *new vector<vector<int>>(n + 1);
    for (int i = 1, u, v; i <= m; ++i) {
        cin >> u >> v;
        a[u].emplace_back(v);
        a[v].emplace_back(u);
    }
    cin >> q;
    for (int i = 1, u, d, c; i <= q; ++i) {
        cin >> u >> d >> c;
        s->push(s, { u, d, c });
    }
    while (!s->isEmpty(s)) {
        search(s, s->top->param);
    }
    for (int i = 1; i <= n; ++i) {
        cout << ans[i] << '\n';
    }
}