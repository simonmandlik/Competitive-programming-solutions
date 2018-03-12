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

ll fastExp(ll a, ll p, ll MOD) {
	if (p == 0) return 1;
	if (p % 2 == 1) {
		return (a*fastExp(a,p-1, MOD)) % MOD;
	} else {
		ll x = fastExp(a, p/2, MOD);
		return (x*x) % MOD;
	}
}

int main() {
    ios::sync_with_stdio(false);
	ll T, t, n, K, MOD, x;
	cin >> T; t = 0;
	while(++t <= T) {
		cin >> n >> K >> MOD;
		ll res = 0;
		REP(i, n) {
			cin >> x;
			res += x; res %= MOD;
		}
		res = ((K * res) % MOD) * fastExp(n, K-1, MOD) % MOD;
		cout << "Case " << t << ": " << res << endl;
	}
}