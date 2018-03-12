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

int dp[101];
int prices[100];

int main() {
    ios::sync_with_stdio(false);
    int T, N, K;
    cin >> T;
    dp[0] = 0;
    while (T-- > 0) {
    	cin >> N >> K;
    	for(int i = 0; i < K; ++i) {
    		cin >> prices[i];
    		dp[i+1] = INF;
    	}
    	for(int i = 1; i <= K; ++i) {
    		for(int k = 1; k <= K; ++k) {
    			if (i - k >= 0 && prices[k - 1] != -1) {
    				dp[i] = min(dp[i], dp[i - k] + prices[k - 1]);
    			}
    		}
    	}
    	cout << ((dp[K] == INF) ? -1 : dp[K]) << endl;
    }
    return 0;
}