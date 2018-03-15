#include <bits/stdc++.h>
using namespace std;
#define EPS (1e-10)
#define DEBUG(x) cout << "> " << #x << ": " << x << endl;
#define REP(i, n) for (int i = 0; i < (n); i++)
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define FORD(i, a, b) for (int i = (a); i >= (b); i--)
#define BE(c) c.begin(), c.end()
#define PB(v, i) v.push_back(i)
typedef long double ld;
typedef long long ll;
typedef pair<int, int> ii;
typedef pair<double, double> dd;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<double> vd;
typedef vector<bool> vb;
typedef vector<vector<int>> vvi;
typedef vector<ii> vii;

const int MAXN = 10001;

struct Edge {
	int u, w;
};

void update(int u, vll &a, vll &b, ll best) {
	if (best < b[u]) return;
	else if (best > a[u]) {
		b[u] = a[u];
		a[u] = best;
	} else {
		b[u] = best;
	}
}

int main() {
    ios::sync_with_stdio(false);
	int n = 0, u, v, w; string line;
	while (getline(cin, line)) {
		n = 0;
		vector<vector<Edge>> es(MAXN);
		vi deg(MAXN, 0); vll a(MAXN, 0), b(MAXN, 0);
		vb vis(MAXN, false);
		while(line.length() > 0) {
			stringstream ss(line);
			ss >> u >> v >> w; --u; --v;
			es[u].push_back({v, w});
			es[v].push_back({u, w});
			n = max(n, max(u+1, v+1));
			getline(cin, line);
			deg[u]++; deg[v]++;
		}
		queue<int> q;
		REP(i, n) if (deg[i] == 1) q.push(i);
		ll res = 0;
		while (!q.empty()) {
			u = q.front(); q.pop();
			res = max(res, a[u]+b[u]);
			if (deg[u] > 0) {
				for(Edge &e : es[u]) {
					if (!vis[e.u]) {
						update(e.u, a, b, a[u] + e.w);
						if (--deg[e.u] == 1) q.push(e.u);
					}
				}
			}
			vis[u] = true;
		}
		cout << res << endl;
	}
}