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

int districts[100000001];
int zeros[100000001];
int ones[100000001];

int main() {
    ios::sync_with_stdio(false);
    int T, o1, o2, N, d, count;
    bool found;
    cin >> T;
    while (T-- > 0) {
    	cin >> o1 >> o2; N = o1*o2;
    	for(int i = 0; i < N; ++i) cin >> districts[i];
    	for(int i = 0; i < o2; ++i) districts[N + i] = districts[i];
    	found = false;
    	zeros[0] = 0; ones[0] = 0;
		for(int i = 1; i <= N + o2; ++i) {
			zeros[i] = zeros[i-1];
			ones[i] = ones[i-1];
			if (districts[i] == 0) {
				++zeros[i];
			} else {
				++ones[i];
			}
		}   
    	for(int i = 0; i < o2; ++i) {
    		count = 0;
    		for(int j = 0; j < o1; ++j) {
    			if (ones[i + j * o2 + o2] - ones[i + j * o2] > 
    				zeros[i + j * o2 + o2] - zeros[i + j * o2]) {
    				++count;
    			}
    		}	
    		if (count > o1 / 2) {
    			found = true;
    			break;
    		}
    	}    	
    	cout << (found ? 1 : 0) << endl;
    }
    return 0;
}