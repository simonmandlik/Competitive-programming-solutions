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
	ll a,b,c,d,e,n, ba=0, bb = 0, bc = 0, bd = 0, be = 0, rem = 0;
	cin >> n;
	vi p(n);
	REP(i, n) cin >> p[i];
	cin >> a >> b >> c >> d >> e;
	REP(i, n) {
		be += (rem+p[i])/e;
		rem = (rem+p[i])%e;
		bd += rem/d;
		rem = rem%d;
		bc += rem/c;
		rem = rem%c;
		bb += rem/b;
		rem = rem%b;
		ba += rem/a;
		rem = rem%a;
	}
	cout << ba << " " << bb << " " << bc << " " << bd << " " << be << endl;
	cout << rem << endl;
}