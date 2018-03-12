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

long long dp[202];
int limit = INT_MAX;

int main() {
    ios::sync_with_stdio(false);
    int T, N;
    cin >> T;
    string s;
    dp[0] = 0;
    while (T-- > 0) {
    	cin >> s;
    	N = s.length();

        for(int i = 1; i <= N; ++i) {
            dp[i] = 0;
            int len = 1;
            while(i + 1 - len > 0) {
                long long num = stol(s.substr(i - len, len));
                if (num > limit) break;
                else {
                    dp[i] = max(dp[i], num + dp[i - len]);
                }
                ++len;
            }
        }
    	cout << dp[N] << endl;
    }
    return 0;
}	