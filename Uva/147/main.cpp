#include <bits/stdc++.h>
using namespace std;

typedef long long ll; // comments that are mixed in with code
typedef pair<int, int> ii; // are aligned to the right like this
typedef vector<ii> vii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;

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

int main () {
    int coins [] = {1, 2, 4, 10, 20, 40, 100, 200, 400, 1000, 2000};
    vector<double> dp(6000 + 10);
 
    dp [0] = 1;
 
    for ( int i = 0; i < 11; i++ ) {
        for ( int j = 1; j <= 6000; j++ ) {
            if ( j - coins [i] >= 0 )
                dp [j] += dp [j - coins [i]];
        }
    }
 
    double c; 
    while (cin >> c) {
        if (c == 0) break;
        int index = c * 20; 
        printf ("%6.2lf%17.lf\n", c, dp [index]);
    }
 
    return 0;
}
 
