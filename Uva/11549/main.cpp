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

int MAXN = 15;

ll getNDigits(ll a, int n) {
	char s[MAXN];
	sprintf(s, "%lld", a);
	s[n] = 0;
	return atol(s);
}

ll f(ll a, int n) {
	return getNDigits(a*a, n);
}

int main() {
    ios::sync_with_stdio(false);
    int T, n;
    ll k;
    cin >> T;
    while (T-- > 0) {
    	cin >> n >> k;
    	if (k <= 1) {
    		cout << k << endl;
    		continue;
    	}
    	// FLOYD CYCLE-DETECTION
    	ll hare = f(f(k, n), n);
    	ll turtle = f(k, n);
    	ll res = max(k, hare);
    	res = max(res, turtle);
    	while (hare != turtle) {
    		hare = f(hare, n);
    		res = max(res, hare);
    		hare = f(hare, n);
    		res = max(res, hare);
    		turtle = f(turtle, n);
    		// cout << hare << " " << turtle << endl;
    	}
    	res = max(hare, res);
    	cout << res << endl;

    }
    return 0;
}