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
typedef pair<double, double> pdd;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<double> vd;
typedef vector<bool> vb;
typedef vector<vector<int>> vvi;
typedef vector<ii> vii;

int sign(int x) {
	if (x == 0) return 0;
	return x < 0 ? -1:1;
}

int main() {
    ios::sync_with_stdio(false);
	int N, K, d, ds, x, y; string q;
	while(cin >> N >> K) {
		int a[N];
		REP(i, N) cin >> a[i];
		d = int(sqrt(N)); ds = N/d;
		int r[d];
		for(int x = 0; x < ds; ++x) {
			r[x] = 1;
			for(int i = x*d; i < (x+1)*d; ++i) {
				r[x] *= sign(a[i]);
			}
		}
		REP(k, K) {
			cin >> q >> x >> y;
			if (q == "C") {
				--x;
				if (sign(a[x] != sign(y))) {
					if (y == 0) a[x] = r[x/d] = 0;
					else {
						a[x] = y;
						if (x < ds*d) {
							r[x/d] = 1;
							for(int i = (x/d)*d; i < (x/d + 1) * d; ++i) {
								r[x/d] *= sign(a[i]);
							}
						}
					}
				}
			} else {
				--x; --y;
				int res = 1;	
				if (y-x <= 2*d) {
					for(int i = x; i <= y; ++i) res *= sign(a[i]);
				} else {
					for(int i = x; i < ((x+d-1)/d)*d; ++i) {
						res *= sign(a[i]);
					}
					for(int i = (y/d)*d; i <= y; ++i) {
						res *= sign(a[i]);
					}
					for(int i = (x+d-1)/d; i < y/d; ++i) {
						res *= r[i];
					}
				}
				if (res == 0) cout << '0';
				else if (res > 0) cout << '+';
				else cout << '-';
			}
		}
		cout << endl;
	}
}