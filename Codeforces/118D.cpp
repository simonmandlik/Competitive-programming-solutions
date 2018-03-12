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

int dp[101][101][2] = {-1};

const int M = 1e8;

int solve(int n1, int n2, int k1, int k2, int k) {
	if (dp[n1][n2][k] == -1) {
		if (n1 == 0 && n2 == 0) return 1;
		dp[n1][n2][k] = 0;
		if (k == 1) {
			for(int i = 1; i <= min(k1, n1); ++i) {
				dp[n1][n2][k] += solve(n1-i, n2, k1, k2, 0);
				dp[n1][n2][k] %= M;
			}
		} else {
			for(int i = 1; i <= min(k2, n2); ++i) {
				dp[n1][n2][k] += solve(n1, n2-i, k1, k2, 1);
				dp[n1][n2][k] %= M;
			}
		}
	}
	return dp[n1][n2][k];
}

int main() {
    ios::sync_with_stdio(false);
	int n1, n2, k1, k2; cin >> n1 >> n2 >> k1 >> k2;
	REP(j, 101)REP(k, 101) dp[j][k][0] = dp[j][k][1] = -1;
	cout << (solve(n1, n2, k1, k2, 0) + solve(n1, n2, k1, k2, 1)) % M << endl;
}