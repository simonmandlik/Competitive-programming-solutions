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

const int maxK=10, maxM=100;

// bottom up
int dp[maxM + 1][maxM + 1][maxK + 1];

// top down
int memo[maxM + 1][maxM + 1][maxK + 1];

int memoization(int from, int to, int mails) {
	if (memo[from][to][mails] != -1) return memo[from][to][mails];
	int m = INF;
	if (from == to) {
		m = 0;
	} else {
		for(int i = from + 1; i <= to; ++i) {
			m = min(m, i + max(memoization(from, i - 1, mails - 1), memoization(i, to, mails)));
		}	
	}	

	return memo[from][to][mails] = m;
}

int main() {
    ios::sync_with_stdio(false);
    for(int i = 0; i <= maxM; ++i) {
    	for(int j = 0; j <= maxM; ++j) {
    		for(int k = 0; k <= maxK; ++k) {
    			memo[i][j][k] = dp[i][j][k] = -1;
    		}
    		memo[i][j][1] = dp[i][j][1] = (j*(j+1))/2 - ((i+1)*i)/2;
    	}
        for (int j = 0; j < 11; j++)
            dp[i][i][j] = 0;
    }

    int T;
    cin >> T;
    int k, m;
    while (T-- > 0) {
    	cin >> k >> m;
    	cout << memoization(0, m, k) << endl;
    }
    return 0;
}