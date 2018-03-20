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

int gcd(ll x, ll y) {
	if (x < y) swap(x, y);
	if (y == 0) return x;
	return gcd(y, x%y);
}

int main() {
    ios::sync_with_stdio(false);
    ll x, y;
    cin >> x >> y;
    int g = gcd(x, y);
    ll l = (x*y)/g;
    if (l/min(x, y)-1 == l/max(x, y)) {
    	cout << "Equal" << endl;
    } else {
    	cout << (x < y ? "Dasha" : "Masha") << endl;
    }
	
}