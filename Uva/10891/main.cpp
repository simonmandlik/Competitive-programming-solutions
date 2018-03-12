#include <bits/stdc++.h>
using namespace std;

#define DEBUG(x) cout << '>' << #x << ':' << x << endl;
#define REP(i, n) for(int i=0;i<(n);i++)
#define FOR(i, a, b) for(int i=(a);i<=(b);i++)
#define FORD(i, a, b) for(int i=(a);i>=(b);i--)

inline bool EQ(double a, double b) { return fabs(a - b) < 1e-9; }

const int INF = 1 << 29;
typedef long long ll;

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

long long sum[101][101];
long long dp[101][101];

void compute(int N) {
	int to;
	for (int length = 1; length < N; ++length) {
		for (int from = 0; from < N - length; ++from) {
			to = from + length;
			sum[from][to] = sum[from][from] + sum[from + 1][to];
			dp[from][to] = sum[from][to];
			for (int l = from; l < to; ++l)
			{
				dp[from][to] = max(dp[from][to], sum[from][l] - dp[l + 1][to]);
				dp[from][to] = max(dp[from][to], - dp[from][l] + sum[l + 1][to]);
			}
		}
	}
}


int main() {
    ios::sync_with_stdio(false);
    int N, k;
    cin >> N;
    while (N > 0) {
    	for (int i = 0; i < N; ++i) {
    		cin >> k;
    		sum[i][i] = dp[i][i] = k;
    	}
    	compute(N);
    	// for (int i = 0; i < N; ++i)
    	// {
    	// 	for (int j = 0; j < N; ++j)
    	// 	{
    	// 		cout << sum[i][j] << ' ';
    	// 	}
    	// 	cout << endl;
    	// }
    	// for (int i = 0; i < N; ++i)
    	// {
    	// 	for (int j = 0; j < N; ++j)
    	// 	{
    	// 		cout << dp[i][j] << ' ';
    	// 	}
    	// 	cout << endl;
    	// }
    	cout << dp[0][N - 1] << endl;
    	cin >> N;
    }
    return 0;
}