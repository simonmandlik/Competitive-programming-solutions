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
	int m, w, h, W, H, x, y;
	while(cin >> m && m > 0) {
		W = H = x = y = 0;
		while(cin >> w >> h && w+h > 0) {
			if (x + w > m) {
				W = max(W, x);
				H = y;
				x = w;
			} else {
				x += w;
			}
			y = max(y, H+h);
			// cout << x << " " << y << endl;
		}
		W = max(W, x);
		H = y;
		x = w;
		cout << W << " x " << H << endl; 
	}
}