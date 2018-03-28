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
	int T, u, v, l, t, a; cin >> T;
	string s;
	queue<int> q;
	int AM[26][26]; vb vis(26);
	while (T-- > 0) {
		t = a = 0;
		REP(i, 26) REP(j, 26) AM[i][j] = 0;
		fill(vis.begin(), vis.end(), false);
		while(cin >> s && s[0] != '*') {
			u = s[1] - 'A'; v = s[3] - 'A';
			AM[u][v] = AM[v][u] = 1;
		}
		cin >> s;
		for(int i = 0; i < s.length(); i += 2) {
			u = s[i] - 'A';
			if (!vis[u]) {
				q.push(u);
				vis[u] = true;
				l = 0;
				while(!q.empty()) {
					v = q.front(); q.pop();
					l++;
					REP(i, 26) {
						if (!vis[i] && AM[v][i] > 0) {
							vis[i] = true;
							q.push(i);
						}
					}
				}	
				if (l == 1) a++;
				else t++;			
			}
		}
		cout << "There are " << t << " tree(s) and " << a << " acorn(s)." << endl;
	}
}