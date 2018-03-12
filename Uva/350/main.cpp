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

int Z, I, M;

int f(int l) {
	return ((Z * l + I) % M);
}

int main() {
    ios::sync_with_stdio(false);
    int L, hare, turtle;
    int cas = 1;
    while ((cin >> Z >> I >> M >> L) && (Z+I+M+L > 0)) {

    	// find cycle
    	hare = turtle = L; // f(0)
    	do {
    		hare = f(f(hare));
    		turtle = f(turtle);
    	} while (hare != turtle);

    	// find cycle's beginning
    	hare = L; // f(0)
    	while (hare != turtle) {
    		hare = f(hare);
    		turtle = f(turtle);
    	}

    	// find cycle's length
    	int len = 0;
    	do {
    		++len;
    		hare = f(hare);
    	} while (hare != turtle);

    	cout << "Case " << cas++ << ": ";
    	cout << len << endl;
    }
    return 0;
}