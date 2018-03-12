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

vi knapsack(201);
vi prices(21);

int main() {
    ios::sync_with_stdio(false);
    int T, M, C, c;
    cin >> T;
    while (T-- > 0) {
    	cin >> M >> C;
    	fill(knapsack.begin() + 1, knapsack.begin() + M + 1, -1);
    	knapsack[0] = 0;
    	for(int i = 1; i <= C; ++i) {
    		cin >> c;
    		for(int j = 0; j < c; ++j) {
    			cin >> prices[j];
    		}

    		for(int k = M; k >= 0; --k) {
    			if (knapsack[k] == i - 1) {
    				for(int l = 0; l < c; ++l) {
    					int a = prices[l];
    					if (k + a <= M) {
    						knapsack[k + a] = i;
    					}
    				}
    			}
    		}
    	}

    	int res = M;
    	while(knapsack[res] != C && res >= 0) --res;
    	if (res < 0) cout << "no solution" << endl;
    	else cout << res << endl;
    	
    }
    return 0;
}