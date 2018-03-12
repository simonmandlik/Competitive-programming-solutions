#include <bits/stdc++.h>
using namespace std;

const int MOD = 1000000007;

void dfs_walk(int n, vector<vector<int>> &nL,
	stack<int> &first_walk, vector<bool> &visited) {
	for(int v : nL[n]) {
		if (!visited[v]) {
			visited[v] = true;
			dfs_walk(v, nL, first_walk, visited);
		}
	}
	first_walk.push(n);
}

void kosaraju_sharir(int N, vector<int> &c,
	vector<vector<int>> &nL, vector<vector<int>> &nLr) {
	vector<bool> visited(N, false);
	stack<int> first_walk, dfs;

	for(int i = 0; i < N; ++i) {
		if (!visited[i]) {
			visited[i] = true;
			dfs_walk(i, nL, first_walk, visited);
		}
	}

	fill(visited.begin(), visited.end(), false);
	int u, v;
	int min_cost, count;
	long long ways = 1, net_cost = 0;
	while(!first_walk.empty()) {
		u = first_walk.top(); first_walk.pop();
		if (!visited[u]) {
			visited[u] = true;
			dfs.push(u);
			min_cost = INT_MAX; count = 1;
			while(!dfs.empty()) {
				v = dfs.top(); dfs.pop();
				if (c[v] < min_cost) {
					min_cost = c[v]; count = 1;
				} else if (c[v] == min_cost) ++count;
				for(int w : nLr[v]) {
					if (!visited[w]) {
						visited[w] = true;
						dfs.push(w);
					}
				}
			}
			ways = (ways * count) % MOD;
			net_cost += min_cost;
		}
	}

	cout << net_cost << " " << ways << endl;

}

int main() {
    ios::sync_with_stdio(false);
    int N, M, u, v;
    cin >> N;
    vector<int> c(N);
    vector<vector<int>> nL(N), nLr(N);

    for(int i = 0; i < N; ++i) cin >> c[i];
    cin >> M;
	for(int i = 0; i < M; ++i) {
		cin >> u >> v; --u; --v;
		nL[u].push_back(v);
		nLr[v].push_back(u);
	}

	kosaraju_sharir(N, c, nL, nLr);
    return 0;
}