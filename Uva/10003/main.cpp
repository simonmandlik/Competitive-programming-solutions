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

int main() {
    ios::sync_with_stdio(false);
    int N, c;
    cin >> N;
    while (N > 0) {
    	cin >> c;
    	c += 2; //beginning and end
    	vi cuts(c);
    	cuts[0] = 0;
    	cuts[c - 1] = N;
    	for(int i = 1; i < c - 1; ++i) {
    		cin >> cuts[i];
    	}
    	vvi price(c, vi(c, INF));

    	for(int i = 0; i < c - 1; ++i) price[i][i + 1] = 0;
    	for(int length = 2; length <= c - 1; ++length) {
    		for(int i = 0; i < c - length; ++i) {
    			int j = i + length;
    			for(int k = i + 1; k < j; ++k) {
    				price[i][j] = min(price[i][j], price[i][k] + price[k][j]);
    			}
    			price[i][j] += cuts[j] - cuts[i];
    		}
    	}
    	cout << "The minimum cutting is ";
    	cout << price[0][c - 1];
    	cout << ".\n";

    	cin >> N;
    }
    return 0;
}