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
int row[51];
int main() {
    ios::sync_with_stdio(false);
    int T, M, N;
    cin >> T;
    while (T-- > 0) {
    	cin >> N >> M;
    	int x = 0, grundy;
    	if (M > 0) {
	    	for(int i = 0; i < N; ++i) {
	    		for(int j = 0; j < M; ++j) {
	    			cin >> row[j];
	    		}
	    		grundy = row[M-1];
	    		for(int j = M - 2; j >= 0; --j) {
	    			if (row[j] <= grundy) {
	    				grundy = row[j] - 1;
	    			} else {
	    				grundy = row[j];
	    			}
	    		}
	    		x ^= grundy;
	    	}
    	}
    	cout << ((x == 0) ? "SECOND" : "FIRST") << endl;

    }
    return 0;
}