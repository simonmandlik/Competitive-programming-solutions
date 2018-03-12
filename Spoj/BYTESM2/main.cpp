#include <bits/stdc++.h>
using namespace std;

typedef long long ll; // comments that are mixed in with code
typedef pair<int, int> ii; // are aligned to the right like this
typedef vector<ii> vii;
typedef vector<int> vi;
typedef vector<vector<int> > vvi;

#define INF 1000000000 // 1 billion, safer than 2B for Floyd Warshall’s
#define DEBUG(x) cout << '>' << #x << ':' << x << endl;
#define REP(i, n) for(int i=0;i<(n);i++)
#define FOR(i, a, b) for(int i=(a);i<=(b);i++)
#define FORD(i, a, b) for(int i=(a);i>=(b);i--)

inline bool EQ(double a, double b) { return fabs(a - b) < 1e-9; }

inline int two(int n) { return 1 << n; }

inline int test(int n, int b) { return (n >> b) & 1; }

inline void set_bit(int &n, int b) { n |= two(b); }

inline void unset_bit(int &n, int b) { n &= ~two(b); }

inline int last_bit(int n) { return n & (-n); }

inline int ones(int n) {
    int res = 0;
    while (n && ++res) n -= n & (-n);
    return res;
}

template<class T>
void chmax(T &a, const T &b) { a = max(a, b); }

template<class T>
void chmin(T &a, const T &b) { a = min(a, b); }

vvi tiles(101, vi(102));
vvi dp(101, vi(102));

int main() {
    ios::sync_with_stdio(false);
    int T, h, w;
    cin >> T;
    while (T-- > 0) {
    	cin >> h >> w;
    	for (int i = 0; i < w + 2; ++i)
    	{
    		dp[0][i] = 0;
    	}
    	for (int i = 1; i <= h; ++i)
    	{
    		dp[i][0] = dp[i][w + 1] = 0;
    		for (int j = 1; j <= w; ++j)
    		{
    			cin >> tiles[i][j];
    			dp[i][j] = tiles[i][j] + max(dp[i - 1][j + 1], max(dp[i - 1][j], dp[i - 1][j - 1]));
    		}
    	}
    	int res = 0;
    	for(int j = 1; j <= w; ++j) {
    		res = max(dp[h][j], res);
    	}
    	cout << res << endl;
    }
    return 0;
}
