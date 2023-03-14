#include "bits/stdc++.h"

using namespace std;

const int mMax = 1e5 + 9;

int cnt, ans, a[mMax], b[mMax], c[mMax], make[mMax], t[mMax], linked[mMax][20], n, u, v, sz, q;
vector<vector<int>> e, g;

struct Stack {
    struct Node {
        int value;
        Node *next;
    } *top;
    typedef Stack stack;
    typedef stack::Node node;

    stack *initStack() {
        stack *s = new stack;
        s->top = nullptr;
        return s;
    }

    node *createNode(int x) {
        node *p = new node;
        p->value = x;
        p->next = nullptr;
        return p;
    }

    void push(stack *&s, int x) {
        node *p = createNode(x);
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

    int peek(stack *s) {
        return s->top->value;
    }
};

struct compareBtoB {
    auto operator()(const int &x, const int &y) -> bool {
        return b[x] < b[y];
    }
};

struct compareBtoC {
    auto operator()(const int &x, const int &y) -> bool {
        return b[x] <= b[y] && c[x] >= c[y];
    }
};

struct findLinked {
    auto operator()(int &x, int &y) -> int {
        auto cmp = compareBtoC();
        if (cmp(x, y)) {
            return x;
        }
        if (cmp(y, x)) {
            return y;
        }
        for (int i = sz; i >= 0; --i) {
            if (!cmp(linked[x][i], y)) {
                x = linked[x][i];
            }
        }
        return linked[x][0];
    }
};

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    Stack *s = s->initStack();

    cin >> n;
    e = *new vector<vector<int>>(n + 1);
    g = *new vector<vector<int>>(n + 1);

    for (int i = 1; i <= n - 1; ++i) {
        cin >> u >> v;
        e[u].emplace_back(v);
        e[v].emplace_back(u);
    }

    sz = (int) log2(n);
    cin >> q;

    linked[1][0] = 1;
    function<auto(int) -> void> dfs = [&](int u) -> void {
        b[u] = ++cnt;
        for (int i = 1; i <= sz; ++i) {
            linked[u][i] = linked[linked[u][i - 1]][i - 1];
        }
        for (int i = 0; i < (int) e[u].size(); ++i) {
            if (e[u][i] != linked[u][0]) {
                linked[e[u][i]][0] = u;
                dfs(e[u][i]);
            }
        }
        c[u] = ++cnt;
    };

    dfs(1);

    for (int test = 1, m; test <= q; ++test) {
        cin >> m;

        for (int i = 1; i <= m; ++i) {
            cin >> a[i];
            g[a[i]].clear();
            make[a[i]] = test;
            t[a[i]] = test;
        }

        sort(a + 1, a + 1 + m, compareBtoB());

        for (int i = 1; i <= m - 1; ++i) {
            auto local = findLinked();
            int current = local(a[i], a[i + 1]);
            if (make[current] < test) {
                make[current] = test;
                a[++m] = current;
                g[current].clear();
            }
        }

        sort(a + 1, a + 1 + m, compareBtoB());

        while (!s->isEmpty(s)) {
            s->pop(s);
        }

        s->push(s, a[1]);

        for (int i = 2; i <= m; ++i) {
            while (c[s->peek(s)] < c[a[i]]) {
                s->pop(s);
            }
            g[s->peek(s)].emplace_back(a[i]);
            s->push(s, a[i]);
        }

        ans = { 0 };

        function<auto(int) -> int> check = [&](int u) -> int {
            int cnt = 0;
            for (int i = 0; i < (int) g[u].size(); ++i) {
                if (t[u] == test) {
                    if (t[g[u][i]] == test && linked[g[u][i]][0] == u) {
                        ans = -1;
                        return -1;
                    }
                    bool x = check(g[u][i]);
                    if (ans == -1) {
                        return -1;
                    }
                    ans += x;
                } else {
                    bool x = check(g[u][i]);
                    if (ans == -1) {
                        return -1;
                    }
                    cnt += x;
                }
            }
            if (t[u] == test || cnt == 1) {
                return 1;
            }
            if (cnt > 1) {
                ++ans;
            }
            return 0;
        };
        check(a[1]);
        cout << ans << '\n';
    }
}