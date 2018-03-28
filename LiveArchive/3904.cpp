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
	ll dp[31]; int T, n; cin >> T;
	while(T-- > 0) {
		cin >> n;
		dp[0] = 1;
		dp[1] = 1;
		FOR(i, 2, n+1) dp[i] = 2*dp[i-2] + dp[i-1];
		if (n % 2 == 1) cout << (dp[n] + dp[n/2])/2 << endl;
		else cout << (dp[n] + dp[n/2] + 2*dp[n/2-1])/2 << endl;
	}
}