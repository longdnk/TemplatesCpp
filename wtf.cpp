#include <bits/stdc++.h>
using namespace std;

void printPath(const vector<int> &path) {
    for (int node : path) {
        cout << node << " ";
    }
    cout << "\n";
}

bool dfs(int current, int destination, vector<vector<int>> &adj, vector<bool> &visited, vector<int> &parent) {
    visited[current] = true;

    if (current == destination) {
        vector<int> path;
        while (current != -1) {
            path.push_back(current);
            current = parent[current];
        }
        reverse(path.begin(), path.end());
        cout << path.size() - 1 << '\n';
        printPath(path);
        return true;
    }

    for (int neighbor : adj[current]) {
        if (!visited[neighbor]) {
            parent[neighbor] = current;
            if (dfs(neighbor, destination, adj, visited, parent)) {
                return true;
            }
        }
    }

    return false;
}

bool findPath(int source, int destination, vector<vector<int>> &adj) {
    int n = adj.size();
    vector<bool> visited(n, false);
    vector<int> parent(n, -1);

    return dfs(source, destination, adj, visited, parent);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m, s, t;
    cin >> n >> m >> s >> t;

    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].emplace_back(v);
        adj[v].emplace_back(u);
    }

    bool check = findPath(s, t, adj);
    if (!check) {
        cout << "-1" << '\n';
    }

    return 0;
}
