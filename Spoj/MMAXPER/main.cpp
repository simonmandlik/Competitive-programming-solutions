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


struct Rect{int a, b;};

int main() {
    ios::sync_with_stdio(false);
    int N;
    cin >> N;
	int W[N], H[N];
	Rect R[N];
    int a, b;
    for (int i = 0; i < N; ++i) {
    	cin >> a >> b;
    	R[i] = {a, b};
    }
    W[0] = R[0].b;
    H[0] = R[0].a;
    for (int i = 1; i < N; ++i)
    {	
    	W[i] = R[i].b + max(W[i - 1] + abs(R[i - 1].a - R[i].a),
    						H[i - 1] + abs(R[i - 1].b - R[i].a));
    	H[i] = R[i].a + max(W[i - 1] + abs(R[i - 1].a - R[i].b),
    						H[i - 1] + abs(R[i - 1].b - R[i].b));
    }
    cout << max(W[N - 1], H[N - 1]) << endl;
    return 0;
}