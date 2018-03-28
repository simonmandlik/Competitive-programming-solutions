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
	int N; string fn, ln; int res, gc; vb used(26);
	while(cin >> N && N > 0) {
		vvi g(18, vi());
		REP(i, N) {
			cin >> fn >> ln;
			g[ln[0] - 'A'].push_back(fn[0] - 'A');
		}
		res = INT_MAX;
		for(int conf = 0; conf < (1 << 18); ++conf) {
			gc = 0;
			REP(i, 26) used[i] = false;
			REP(i, 18) {
				if ((1 << i) & conf) {
					gc++;
				} else {
					for(int v : g[i]) used[v] = true;
				}
			}
			REP(i, 26) gc += used[i];
			res = min(res, gc);
		}
		cout << res << endl;
	}
}