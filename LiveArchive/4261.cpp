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
	int n, h, c, t=0; ll d, z;
	while(cin >> n && n > 0) {
		if (t++ > 0) cout << endl;
		int a[n], p[n], s[n]; ll dp[n+1];
		REP(i, n) cin >> a[i];
		REP(i, n) dp[i] = s[i] = INT_MAX;
		s[n] = 1; dp[n] = 0; p[n] = -1;
		FORD(i, n, 1) {
			d = 0;
			FORD(j, i-1, 0) {
				d += a[j];
				z = dp[i] + (d-100)*(d-100);
				if (z < dp[j] || (dp[j] == z && s[i]+1 <= s[j])) {
					dp[j] = z;
					p[j] = i;
					s[j] = s[i] + 1;
				}
			}
		}
		cout << "p=" << dp[0] << endl;
		h = 0, c = 0;
		do {
			cout << " " << h;
			if (++c == 30) {
				cout << endl; c = 0;
			}
     		} while((h=p[h]) != -1);
		cout << endl;
	}
}