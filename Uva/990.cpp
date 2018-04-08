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
	int t, w, n, test = 0;
	vi d(30), v(30); vb res(30);
	int dp[31][1001], pred[31][1001];
	while(cin >> t >> w) {
		if (test++ > 0) cout << endl;
		w *= 3;
		cin >> n;
		REP(i, n) cin >> d[i] >> v[i];
		REP(i, n+1) REP(j, t+1) dp[i][j] = pred[i][j] = 0;
		for(int i = 1; i <= n; ++i) {
			for(int j = 1; j <= t; ++j) {
				pred[i][j] = j;
				dp[i][j] = dp[i-1][j];
				if (j-w*d[i-1] >= 0 && dp[i][j] < dp[i-1][j-w*d[i-1]] + v[i-1]) {
					dp[i][j] = dp[i-1][j-w*d[i-1]] + v[i-1];
					pred[i][j] = j - w*d[i-1];
				} 
			}
		}
		fill(res.begin(), res.end(), false);
		int j = t, c=0;
		for(int i = n; i > 0; --i) {
			if (pred[i][j] != j) { res[i-1] = true; ++c; }
			j = pred[i][j]; 
		}
		cout << dp[n][t] << endl << c << endl;
		for(int i = 0; i < n; ++i) {
			if (res[i]) {
				cout << d[i] << " " << v[i] << endl;
			}
		}
	}
}