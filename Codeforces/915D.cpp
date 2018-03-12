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

int cb;

bool find_cycle(int n, int k, vvi & nl, vi &ks, vb &vis, stack<ii> &e, int uf, int vf) {
	vis[n] = true;
	ks[n] = k;
	for(int m : nl[n]) {
		if (n == uf && m == vf) continue;
		if (!vis[m]) {
			if (find_cycle(m, k+1, nl, ks, vis, e, uf, vf)) {
				if (ks[n] >= cb) e.push({n, m});
				ks[n] = 0;
				return true;
			}
		} else if (ks[m] != 0) {
			cb = ks[m];
			e.push({n, m});
			ks[n] = 0;
			return true;
		}
	}
	ks[n] = 0;
	return false;
}

int main() {
    ios::sync_with_stdio(false);
	int n, m, u, v; cin >> n >> m;
	vvi nl(n, vi{}); vb vis(n); vi ks(n, 0);
	REP(i, m) { cin >> u >> v; nl[--u].push_back(--v); }

	REP(i, n) {
		fill(vis.begin(), vis.end(), false);
		stack<ii> e, f;
		if (find_cycle(i, 1, nl, ks, vis, e, -1, -1)) {
			while(!e.empty()) {
				bool found = false;
				fill(vis.begin(), vis.end(), false);
				REP(i, n) {
					if (!vis[i] && find_cycle(i, 1, nl, ks, vis, f, e.top().first, e.top().second)) {
						found = true;
					}
				}
				e.pop();
				if (!found) {
					// cout << e.top().first << e.top().second << endl;
					cout << "YES" << endl;
					return 0;
				}
			}
			cout << "NO" << endl;
			return 0;			
		}
	}
	cout << "YES" << endl;
}