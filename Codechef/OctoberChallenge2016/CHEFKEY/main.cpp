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

//void count_primes(int c, queue<int> &primes) {
//    for(int i = 2; i <= sqrt(c); ++i) {
//        while (c % i == 0) {
//            primes.push(i);
//            c /= i;
//        }
//        if (c == 1) break;
//    }
//}

int main() {
    ios::sync_with_stdio(false);
    int T, M, N, C, res;
    cin >> T;
    while (T-- > 0) {
        cin >> N >> M >> C;
        res = 0;
//        queue<int> primes;
//        count_primes(C, primes);
        int x = C, y = 1;
        while(x > N) {
            --x;
        }
        while(x > 0) {
            if (C % x == 0 && C / x <= M) ++res;
            --x;
        }
        cout << res << endl;
    }
    return 0;
}