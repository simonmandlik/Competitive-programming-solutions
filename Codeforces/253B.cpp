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
    ifstream in("input.txt");
    ofstream out("output.txt");
	int n; in >> n;
	int a[n];
	REP(i, n) in >> a[i];
	sort(a, a+n);
	int i = 0, j = 1, m = n-1;
	while(j < n) {
		// cout << a[i] << " " << a[j] << " " << i <<  " " << j << endl;
		if(2*a[i] >= a[j]) {
			m = min(m, n+i-j-1);
			++j;
		} else {
			++i;
		}
	}
	out << m << endl;
}