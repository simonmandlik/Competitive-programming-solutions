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

set<int> sols;

void solve2(vi x) {
	sols.insert(x[0]+x[1]);
	sols.insert(x[0]-x[1]);
	sols.insert(x[1]-x[0]);
	sols.insert(x[0]*x[1]);
	if (x[1] != 0 && x[0]%x[1] == 0) sols.insert(x[0]/x[1]);
	if (x[0] != 0 && x[1]%x[0] == 0) sols.insert(x[1]/x[0]);
}

void solve3(vi x) {
	REP(i, 3) REP(j, 3) {
		if (i != j) {
			int k = 0;
			while (k == i || k == j) ++k;
			solve2({x[i]+x[j], x[k]});
			solve2({x[i]-x[j], x[k]});
			solve2({x[i]*x[j], x[k]});
			if (x[j] != 0 && x[i]%x[j] == 0) solve2({x[i]/x[j], x[k]});
		}
	}
}

void solve4(vi x) {
	REP(i, 4) REP(j, 4) {
		if (i != j) {
			int k = 0;
			while (k == i || k == j) ++k;
			int l = 0;
			while (l == i || l == j || l == k) ++l;
			solve3({x[i]+x[j], x[k], x[l]});
			solve3({x[i]-x[j], x[k], x[l]});
			solve3({x[i]*x[j], x[k], x[l]});
			if (x[j] != 0 && x[i]%x[j] == 0) solve3({x[i]/x[j], x[k], x[l]});
		}
	}
}

int main() {
    ios::sync_with_stdio(false);
	int a, b, c, d, t = 1;
	while(cin >> a >> b >> c >> d) {
		if (a == 0) break;
		sols.clear();
		solve4({a, b, c, d});
		int count, first, last = -INT_MAX, b_c = -1, from, to;
		for(int x : sols) {
			if (last == -INT_MAX || x != last + 1) {
				first = x;
				count = 0;
			} else {
				count++;
			}
			last = x;
			if (count >= b_c) {
				b_c = count; from = first; to = last;
			}
		}
		cout << "Case " << t++ << ": " << from << " to " << to << endl;
	}
}