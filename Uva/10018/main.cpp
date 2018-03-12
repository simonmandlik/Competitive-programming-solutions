#include <bits/stdc++.h>

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

using namespace std;

void solve(long long P, int it) {
    stringstream ss;
    ss << P;
    string s = ss.str();
    reverse(s.begin(), s.end());
    long long N = atol(s.c_str());
    if (it > 0 && N == P) cout << it << " " << P << endl;
    else solve(P + N, ++it);
}

int main() {
    ios::sync_with_stdio(false);
    int T;
    long long P;
    cin >> T;
    while (T-- > 0) {
        cin >> P;
        solve(P, 0);
    }
    return 0;
}