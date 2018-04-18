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

int solve(vi &a, vvi &dp, int i, int j) {
	if (dp[i][j] != -INT_MAX/2) return dp[i][j];
	if (i == j) return dp[i][j] = 0;
	if (i + 1 == j) return dp[i][j] = a[i];
	if (i + 2 == j) return dp[i][j] = abs(a[i+1] - a[i]);
	else {
		if (a[i] >= a[j-2]) dp[i][j] = max(dp[i][j], solve(a, dp, i+1, j-1) + a[j-1] - a[i]);
		else dp[i][j] = max(dp[i][j], solve(a, dp, i, j-2) + a[j-1] - a[j-2]);
		if (a[i+1] >= a[j-1]) dp[i][j] = max(dp[i][j], solve(a, dp, i+2, j) + a[i] - a[i+1]);
		else dp[i][j] = max(dp[i][j], solve(a, dp, i+1, j-1) + a[i] - a[j-1]);
		// cout << i << " " << j << endl;
		// cout << dp[i][j] << endl;
		return dp[i][j];
	}
}
int main() {
    ios::sync_with_stdio(false);
	int n, t=1;
	while(cin >> n && n > 0) {
		vi a(n); vvi dp(n+1, vi(n+1, -INT_MAX/2));
		REP(i, n) cin >> a[i];
		cout << "In game " << t++ << ", the greedy strategy might lose by as many as ";
		cout << solve(a, dp, 0, n) << " points." << endl;
	}
}