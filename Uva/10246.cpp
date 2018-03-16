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
	int t=1, C, R, Q, u, v; ll d;
	while (cin >> C >> R >> Q) {
		if (C == 0) break;
		if (t > 1) cout << endl;
		ll dp[C][C], cost[C][C];
		REP(i, C) REP(j, C) { cost[i][j] = dp[i][j] = LLONG_MAX/3; };
		REP(i, C) { dp[i][i] = 0; cin >> cost[i][i]; }
		REP(i, R) {
			cin >> u >> v >> d; --u; --v;
			cost[v][u] = cost[u][v] = max(cost[u][u], cost[v][v]);	
			dp[u][v] = dp[v][u] = d;
		}
		REP(tmp, 2) REP(k, C) REP(i, C) REP(j, C) {
			if (dp[i][k] + dp[k][j] + max(cost[i][k], cost[k][j]) < dp[i][j] + cost[i][j]) {
				dp[i][j] = dp[i][k] + dp[k][j];
				cost[i][j] = max(cost[i][k], cost[k][j]);
			}
		}
		cout << "Case #" << t++ << endl;
		REP(i, Q) {
			cin >> u >> v;
			cout << (dp[u-1][v-1] == LLONG_MAX/3 ? -1 : dp[u-1][v-1] + cost[u-1][v-1]) << endl;
		}
	}
}