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

const int N = 1000000;

int main() {
    ios::sync_with_stdio(false);
	vb f(N + 2, true);
	for(int i = 2; i <= 100; ++i) {
		int k = i*i*i;
		for(int j = 1; j*k <= N; ++j) {
			f[j*k] = false;
		}
	}
	vi c(N + 2, 0); int k = 1;
	for(int i = 1; i <= N; ++i) {
		if (f[i]) c[i] = k++;
	}
	int T, t = 0; cin >> T;
	int x;
	while(t++ < T) {
		cin >> x;
		cout << "Case " << t << ": ";
		if (f[x]) cout << c[x] << endl;
		else cout << "Not Cube Free" << endl;
	}
}