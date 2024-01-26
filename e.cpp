#include <bits/stdc++.h>

using namespace std;

void printPath(const vector<int> &path) {
    for (int node : path) {
        cout << node << " ";
    }
    cout << "\n";
}

bool bfs(int source, int destination, vector<vector<int>> &adj) {
    int n = adj.size();
    vector<bool> visited(n, false);
    vector<int> parent(n, -1);
    queue<int> q;

    q.push(source);
    visited[source] = true;

    while (!q.empty()) {
        int current = q.front();
        q.pop();

        for (int neighbor : adj[current]) {
            if (!visited[neighbor]) {
                q.push(neighbor);
                visited[neighbor] = true;
                parent[neighbor] = current;

                if (neighbor == destination) {
                    vector<int> path;
                    while (neighbor != -1) {
                        path.push_back(neighbor);
                        neighbor = parent[neighbor];
                    }
                    reverse(path.begin(), path.end());
                    cout << path.size() - 1 << '\n';
                    printPath(path);
                    return true;
                }
            }
        }
    }
    return false;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, m, s, t;
    cin >> n >> m >> s >> t;

    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    bool check = bfs(s, t, adj);

    if (!check) {
        cout << "-1" << '\n';
        exit(0);
    }
}