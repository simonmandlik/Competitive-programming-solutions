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

const int maxN = 101, maxK = 9;
double dp[maxK + 2][maxN];

int main() {
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(5);
    int K, N;
    while (cin >> K >> N) {
    	++K; // 0 included
	    for(int i = 0; i < maxK + 2; ++i) {
	    	for(int j = 0; j < maxN; ++j) {
	    		dp[i][j] = 0;
			}
    	}
    	for(int k = 1; k <= K; ++k) {
    		dp[k][0] = 1.0 / K;
    	}
    	for(int n = 1; n < N; ++n) {
    		for(int k = 1; k <= K; ++k) {
    			dp[k][n] = dp[k-1][n-1] + dp[k][n-1] + dp[k+1][n-1];
    			dp[k][n] /= K;
    		}
    	}
    	double sum = 0;
    	for(int k = 1; k <= K; ++k) {
    		sum += dp[k][N - 1];
    	}
    	cout << sum * 100 << endl;
    }
    return 0;
}