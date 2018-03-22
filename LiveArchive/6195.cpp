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

int main() {
    ios::sync_with_stdio(false);
	int n, m, u, v, c; queue<int> q;
	bool s;
	while(cin >> n >> m && n+m > 0) {
		vvi nl(n, vi()); vi d(n, 0);
		REP(i, m) {
			cin >> u >> v;
			nl[--u].push_back(--v);
			nl[v].push_back(u);
			d[v]++;
		}
		REP(i, n) if (d[i] == 0) q.push(i);
		c = 0; s = false;
		while(!q.empty()) {
			if (q.size() > 1) s = true;
			for(int v : nl[q.front()])
				if (--d[v] == 0) q.push(v);
			q.pop();
			++c;
		}
		if (c == n) 
			if (s)
				cout << 2 << endl;
			else
				cout << 1 << endl;
		else cout << 0 << endl;
	}
}