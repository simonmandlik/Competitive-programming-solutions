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
    ios::sync_with_stdio(false);
    int s = 2000;
    int product = 2000000000;
    int d, e, f, mul = 1000000, mulf, emul;
    cout << fixed << setprecision(2);
    for (int a = 1; a <= s - 3; ++a) {
    	if (a*a*a*a >= product) break;
    	for (int b = a; b <= s - a - 2; ++b) {
    		if (a * b*b*b  >= product) break;
    		for (int c = b; c <= s - a - b - 1; ++c) {
    			if (a * b * c*c  >= product) break;
    			e = a * b * c;
    			f = a + b + c;

    			if (e == mul) continue;
    			
    			int mulf = mul * f;
    			int emul = e - mul;

    			if (mulf % emul != 0) continue;

    			d = mulf / emul;
    			if (d < c) continue;
    			if (d*e > product) continue;
    			if (f + d > s) continue;

    			cout << a / 100.0 << " " << b / 100.0 << " " << c / 100.0 << " " << d / 100.0 << endl;
    		}
    	}
    }

    return 0;
}













