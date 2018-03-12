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

bool w[1000001];
int s[10];

int main() {
    ios::sync_with_stdio(false);
    int M, N;
    while (cin >> N) {
    	cin >> M;
    	for (int i = 0; i < M; ++i) cin >> s[i];
    	w[0] = false;
    	for(int i = 1; i <= N; ++i) {
    		w[i] = false;
    		for (int m = 0; m < M; ++m) {
    			if (i - s[m] >= 0 && !w[i-s[m]]) {
    				w[i] = true;
    				break;
    			}
    		}
    	}
    	// for(int i = 0; i <= N; ++i) {
    	// 	cout << w[i] << " ";
    	// }
    	cout << ((w[N]) ? "Stan wins" : "Ollie wins") << endl;	
    }
    return 0;
}