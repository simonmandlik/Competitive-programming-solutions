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

int main() {
    long long sumA = 1, sumB = 3;
    int N = 2, k = 3;
    int count = 0;
    while(count < 10) {
        while (sumA < sumB) {
            sumA += N;
            sumB -= N + 1;
            ++N;
        }
        while (sumB < sumA) {
            sumB += ++k;
        }
        if (sumA == sumB) {
            printf("%10d%10d\n", N, k);
            ++count;
            sumB += ++k;
        }
    }
    return 0;
}