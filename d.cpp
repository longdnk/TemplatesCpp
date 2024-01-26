#include <bits/stdc++.h>

using namespace std;

int n, m;
vector<vector<int>> a;
const int maxN = 1e5 + 9;
bool check[maxN];

void dfs(int u) {
	check[u] = true;
	for (auto item: a[u]) {
		if (!check[item]) {
			dfs(item);
		}
	}
}

//void bfs(int s) {
//	queue<int> q;
//	q.push(s);
//	check[s] = true;
//	while (!q.empty()) {
//		int u = q.front();
//		cout << u << ' ';
//		q.pop();
//		for (auto x: a[u]) {
//			if (!check[x]) {
//				check[x] = true;
//				q.push(x);
//			}
//		}
//	}
//}

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin >> n >> m;
	a = vector<vector<int>>(n + 1);
	for (int i = 1, u, v; i <= m; ++i) {
		cin >> u >> v;
		a[u].emplace_back(v);
		a[v].emplace_back(u);
	}
//	dfs(1);
//	bfs(1);
}