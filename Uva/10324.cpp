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

const int MAXN = 1000001;
int main() {
    ios::sync_with_stdio(false);
	string s;
	int pref[MAXN], N, Q, i, j, t=1;
	while(cin >> s) {
		N = s.length();
		memset(pref, 0, sizeof(pref));
		FOR(i, 1, N+1) {
			pref[i] = pref[i-1];
			if (s[i-1] == '1') {
				pref[i]++;
			}
		}
		cout << "Case " << t++ << ":" << endl;
		cin >> Q;
		REP(q, Q) {
			cin >> i >> j;
			if (i>j) swap(i,j);
			cout << (((j-i+1) == (pref[j+1] - pref[i]) || (pref[j+1] - pref[i]) == 0) ? "Yes": "No") << endl;
		}
	}
}