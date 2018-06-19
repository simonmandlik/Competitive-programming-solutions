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

const int MAX_N = 101, MAX_M = 101, LEFT = 1, DIAG = 2, UP = 3;

int main() {
    ios::sync_with_stdio(false);
	string s; int n, m;
	vvi dp(MAX_N, vi(MAX_M)), bt(MAX_N, vi(MAX_M));
	while (cin >> s) {
		vector<string> s1, s2;
		s1.push_back(s);
		while(cin >> s && s != "#") { s1.push_back(s); }
		n = s1.size();
		cin >> s; s2.push_back(s);
		while(cin >> s && s != "#") { s2.push_back(s); }
		m = s2.size();

		REP(i, n+1) { dp[i][0] = 0; bt[i][0] = -1; }
		REP(i, m+1) { dp[0][i] = 0; bt[0][i] = -1; }
		FOR(i, 1, n+1) FOR(j, 1, m+1) {
			if (s1[i-1] == s2[j-1]) {
				dp[i][j] = dp[i-1][j-1] + 1;
				bt[i][j] = DIAG;
			} else if (dp[i][j-1] >= dp[i-1][j]) {
				dp[i][j] = dp[i][j-1];
				bt[i][j] = LEFT;
			} else {
				dp[i][j] = dp[i-1][j];
				bt[i][j] = UP;
			}
		}
		int i = n, j = m;
		stack<string> st;
		while(i > 0 && j > 0) {
			if (bt[i][j] == DIAG) {
				st.push(s1[i-1]);
				i--; j--;
			} else if (bt[i][j] == LEFT) j--;
			else i--;
	
		}
		bool first = true;
		while(!st.empty()) {
			if (!first) cout << " ";
			else first = !first;
			cout << st.top(); st.pop();
		}
		cout << endl;
	}
}