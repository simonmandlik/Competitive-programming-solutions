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

int solvable(string &s, int i, int j, vvi &mem) {	
	if (mem[i][j] != -1) return mem[i][j];
	if (i == j) return mem[i][j] = 1;
	for(int k = i+1; k < j; ++k) {
		if (solvable(s, i, k, mem) && solvable(s, k, j, mem)) return mem[i][j] = 1;
	}
	if (s[i] == s[j-1]) {
		if (solvable(s, i+1, j-1, mem)) return mem[i][j] = 1;
		for(int k = i+1; k < j-1; ++k) {
			if (s[k] == s[i] && solvable(s, i+1, k, mem) && solvable(s, k+1, j-1, mem)) return mem[i][j] = 1;
		}	
	}
	return mem[i][j] = 0;
}

int main() {
    ios::sync_with_stdio(false);
	string s; vvi mem(151, vi(151));
	while(cin >> s) {
		REP(i, 151) REP(j, 151) mem[i][j] = -1;
		cout << (solvable(s, 0, s.length(), mem) == 1 ? "solvable" : "unsolvable") << endl;
	}
}