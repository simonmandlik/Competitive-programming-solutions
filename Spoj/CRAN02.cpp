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
	int t, n, a, res, s; cin >> t;
	while (t-- > 0) {
		cin >> n;
		vi pref;
		ll res = 0;
		s = 0;
		pref.push_back(0);
		REP(i, n) {
			cin >> a;
			s += a;
			pref.push_back(s);
		}
		sort(pref.begin(), pref.end());
		ll i = 0, j;
		while(i < pref.size()) {
			j = i;
			while(j < pref.size() && pref[i] == pref[j]) ++j;
			res += ((j-i)*(j-i-1))/2;
			i = j;
		}
		cout << res << endl;
	}
}