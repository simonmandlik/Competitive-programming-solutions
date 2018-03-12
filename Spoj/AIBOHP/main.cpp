#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;

#define INF 1000000000 // 1 billion, safer than 2B for Floyd Warshall’s
#define DEBUG(x) cout << '>' << #x << ':' << x << endl;
#define REP(i, n) for(int i=0;i<(n);i++)
#define FOR(i, a, b) for(int i=(a);i<=(b);i++)
#define FORD(i, a, b) for(int i=(a);i>=(b);i--)

inline bool EQ(double a, double b) { return fabs(a-b) < 1e-9; }

int dp[6102][6102];

int main() {
    ios::sync_with_stdio(false);

    for(int i = 0; i < 6102; ++i) {
    	dp[0][i] = 0;
    }

    int T, N;
    string s, r;
    cin >> T;
    while (T-- > 0) {
    	cin >> s;
    	r = s;
    	reverse(r.begin(), r.end());
    	N = s.length();
    	for(int i = 1; i <= N; ++i) {
    		for(int j = 1; j <= N; ++j) {
    			if (s[i-1] == r[j-1]) {
    				dp[i][j] = dp[i-1][j-1] + 1;
    			} else {
    				dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
    			}
    		}
    	}
    
    	cout << (N - dp[N][N]) << endl;
    }
    return 0;
}