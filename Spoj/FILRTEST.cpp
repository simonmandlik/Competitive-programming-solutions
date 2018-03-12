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
	int K; string s;
	vector<int> Z(1000003);
	while(cin >> K >> s) {
		if (K == -1) break;
		Z[0] = Z[1] = 0;
		for(int i = 2; i <= s.length(); ++i) {
			int k = Z[i-1];
			while(true) {
				if (s[i-1] == s[k]) {
					Z[i] = k+1;
					break;
				}
				if (k == 0) {
					Z[i] = 0;
					break;
				}
				k = Z[k];
			}
		}
				
		int prefix_l = Z[s.length()];
		if (K < s.length()) cout << 0 << endl;
		else {
			cout << (K-s.length()) / (s.length() - prefix_l) + 1 << endl;
		}
	}
}