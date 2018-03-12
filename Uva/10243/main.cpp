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

vvi nL;
vi present, empty;
vector<bool> visited;

void solve(int n, int prev) {
	present[n] = 1;
	empty[n] = 0;
	for (int ch : nL[n]) {
		if (ch == prev) continue;
		if (!visited[ch]) solve(ch, n);
		present[n] += min(empty[ch], present[ch]);
		empty[n] += present[ch];
	}
	visited[n] = true;	
}

int main() {
    ios::sync_with_stdio(false);    
    int N;
    cin >> N;
    while (N > 0) {
    	nL.resize(N);
    	present.resize(N);
    	empty.resize(N);
    	visited.resize(N);
    	visited.clear();
    	empty.clear();
    	present.clear();
    	nL.clear();
    	int deg, u;
    	for (int i = 0; i < N; ++i) {
    		cin >> deg;
    		while(deg-- > 0) {
    			cin >> u; --u;
    			nL[i].push_back(u);
    		}
    	}
    	if (N == 1) {
    		cout << 1 << endl;
    		cin >> N;
    		continue;
    	}
    	solve(0, -1);
    	cout << min(present[0], empty[0]) << endl;
    	cin >> N;
    }
    return 0;
}