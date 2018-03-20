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

const int MOD = 1e9+7, MAXN = 1e5 + 3;

int main() {
    ios::sync_with_stdio(false);
	int t, k, a, b; cin >> t >> k;
	ll dp[MAXN], pref[MAXN];
	dp[0] = pref[0] = 1;
	FOR(i, 1, MAXN) {
		dp[i] = dp[i-1];
		if (i - k >= 0) dp[i] += dp[i-k];
		dp[i] %= MOD;
		pref[i] = (pref[i-1] + dp[i]) % MOD;
	}
	while(t-- > 0) {
		cin >> a >> b;
		cout << (pref[b] - pref[a-1] + MOD) % MOD << endl;
	}
}