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

bool states[1001][1001];
int sums[1001];

int main() {
    ios::sync_with_stdio(false);
    int N;
    for(int i = 0; i<1001; ++i) states[0][i] = states[i][0] = false;
    while (cin >> N) {
    	int num, rowSum;
    	for(int i = 1; i <= N; ++i) sums[i] = 0;

    	for(int i = 1; i <= N; ++i) {
    		rowSum = 0;
    		for(int j = 1; j <= N; ++j) {
    			cin >> num;
    			rowSum += num;
    			sums[j] += num;
    			states[i][j] = false;
                //cout << rowSum << " " << sums[j] << endl;
    			if (rowSum % 2 == 0 && !states[i - 1][j]) {
    				states[i][j] = true;
    				continue;
    			}
    			if (sums[j] % 2 == 0 && !states[i][j - 1]) {
    				states[i][j] = true;
    				continue;
    			}
    		}
    	}
        // for(int i = 0; i <= N; ++i) {
        //     for (int j = 0; j <= N; ++j) {
        //         cout << states[i][j] << " ";
        //     } 
        //     cout << endl;
        // }
    	cout << (states[N][N] ? "W" : "L") << endl;

    }
    return 0;
}
