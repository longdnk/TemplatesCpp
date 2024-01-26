#include <bits/stdc++.h>

using namespace std;

const int maxN = 1009;

int a[maxN][maxN], n, m, s, t, f[maxN], trace[maxN], checkt2[maxN], INF = ~(1 << 31);

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n >> m >> s >> t;
    memset(a, -1, sizeof a);
    fill(f + 1, f + 1 + n, INF);
    fill(checkt2 + 1, checkt2 + 1 + n, true);
    memset(trace, 0, sizeof trace);
    for (int i = 1, u, v, c; i < m; ++i) {
        cin >> u >> v >> c;
        a[u][v] = a[v][u] = c;
    }
    f[s] = 0;
    trace[s] = 0;
    int v = s, fmin;
    while (s != t) {
        fmin = INF;
        for (int i = 1; i <= n; ++i) {
            if (checkt2[i] && fmin > f[i]) {
                fmin = f[i];
                v = i;
            }
        }
        if (fmin == INF)
            break;
        checkt2[v] = false;
        for (int i = 1; i <= n; ++i) {
            if (a[v][i] > 0 && f[i] > f[v] + a[v][i]) {
                f[i] = f[v] + a[v][i];
                trace[i] = v;
            }
        }
    }
    cout << f[t] << '\n';
    int path[n + m], d = 0;
    ++d;
    path[d] = t;
    while (trace[t] != 0) {
        t = trace[t];
        ++d;
        path[d] = t;
    }
    for (int i = d; i > 0; --i) {
        cout << path[i] << ' ';
    }
}