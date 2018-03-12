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

struct Edge { int v; ll w; };

const ll MOD = 1000000007, DIV = 500000004;

void solve(int n, vector<vector<Edge>> &nL, vll &P, vb &v, ll &res) {
	v[n] = true;
	ll s = 0, q = 0, t;
	for(auto &e : nL[n]) {
		if (!v[e.v]) {
			solve(e.v, nL, P, v, res);
			t = e.w * (P[e.v] + 1); t %= MOD;
			s += t; s %= MOD;
			q += (t*t) % MOD; q %= MOD;
		}
	}
	res += ((((s*s) % MOD + (MOD - q)) % MOD) * DIV) % MOD; res %= MOD;
	res += s; res %= MOD;
	P[n] += s; P[n] %= MOD;
}

int main() {
    ios::sync_with_stdio(false);
	int N, a, b, w; cin >> N;
	vector<vector<Edge>> nL(N, vector<Edge>{});
	vll P(N, 0); vb v(N, false);
	ll res = 0;
	REP(i, N-1) {
		cin >> a >> b >> w; --a; --b;
		nL[a].push_back({b, w});
		nL[b].push_back({a, w});
	}
	solve(0, nL, P, v, res);
	cout << res << endl;
}