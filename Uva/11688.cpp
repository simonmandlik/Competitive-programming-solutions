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

int dfs_depth(int n, vi &left, vi &right, vi &depth, int d) {
	if (n == -1) return 0;
	depth[n] = max(dfs_depth(left[n], left, right, depth, d+1), dfs_depth(right[n], left, right, depth, d+1));
	return ++depth[n];
}

void dfs(int n, vi &left, vi &right, vi &depth, vi &res, int l, int r, int lb, int rb, int d) {
	if (n == -1) return;
	int ld = d + l + depth[left[n]];
	int rd = d + r + depth[right[n]];
	res[n] = max(max(lb, rb), max(ld, rd));
	dfs(left[n], left, right, depth, res, l-1, r, lb, max(rb, rd+1), d+1);
	dfs(right[n], left, right, depth, res, l, r-1, max(lb, ld+1), rb, d+1);
}

int main() {
    ios::sync_with_stdio(false);
	int N, root;
	while(cin >> N && N > 0 ) {
		vi left(N), right(N), res(N, -1), depth(N);
		vb haspar(N, false);
		REP(i, N) {
			cin >> left[i]; --left[i];
			cin >> right[i]; --right[i];
			if (left[i] > 0) haspar[left[i]] = true;
			if (right[i] > 0) haspar[right[i]] = true;
		}
		REP(i, N) if (!haspar[i]) root = i;
		dfs_depth(root, left, right, depth, 0);
		dfs(root, left, right, depth, res, 0, 0, 0, 0, 1);
		REP(i, N) cout << res[i] << endl;
	}
}