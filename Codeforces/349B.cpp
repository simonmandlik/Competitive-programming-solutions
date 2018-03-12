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
	int v; cin >> v; int digit = 0;
	int a[10]; REP(i, 9) { 
		cin >> a[i];
		if (a[i] <= a[digit]) {
			digit = i;
		}
	}
	if (v < a[digit]) {
		cout << -1 << endl;
		return 0;
	}
	int l = v/a[digit];
	v -= l*a[digit];
	for(int i = 8; i > digit; --i) {
		while (v+a[digit] >= a[i]) {
			cout << i+1;
			v -= (a[i]-a[digit]);
			--l;
		}
	}
	REP(i, l) cout << digit+1;
	cout << endl;
}