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
	int n, q; cin >> n >> q;
	ll a[n], c[n] = {0}; REP(i, n) cin >> a[i];
	sort(a, a+n);
	vii qs(q);
	REP(i, q) {cin >> qs[i].first >> qs[i].second; qs[i].first--; qs[i].second--;}
	sort(qs.begin(), qs.end());
	int j = 0, l = 0;
	multiset<int> ends;
	REP(i, n) {
		while(j < q && qs[j].first <= i) {
			ends.insert(qs[j].second);
			++l; ++j;
		}
		while(!ends.empty() && *ends.begin() < i) {
			--l; ends.erase(ends.begin());
		}
		c[i] = l;
	}
	sort(c, c+n);
	ll s = 0;
	REP(i, n) {
		s += c[i]*a[i];
	}
	cout << s << endl;
}