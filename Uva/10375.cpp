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

const int MAX = 10001;
int main() {
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(5);
    int p, q, r, s; ld res;
	ld L[MAX]; REP(i, MAX) L[i] = log(i);
	while(cin >> p >> q >> r >> s) {
		res = 0;
		if (q < p-q) q = p-q;
		if (s < r-s) s = r-s;
		for(int i = 1; i <= p-q; ++i) res += L[i+q] - L[i];
		for(int i = 1; i <= r-s; ++i) res += L[i] - L[i+s];
		cout << exp(res) << endl;
	}
}