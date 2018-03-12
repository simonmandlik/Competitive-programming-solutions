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
	int w, d, x;
	while(cin >> w >> d) {
		if (w == 0) break;
		int res = 0;
		multiset<int> s;
		REP(i, w) { cin >> x; s.insert(x); }
		REP(i, d) { 
			cin >> x;
			auto it = s.find(x);
			if (it != s.end()) {
				s.erase(it);
			}
			res += x;
		}
		for(int x : s) {
			res += x;
		}
		cout << res << endl;
	}
}