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

vector<vector<bool>> mods(102, vector<bool>(102*102*102, false));

void precalc() {
	for(int i = 1; i < 101; ++i) {
		int iii = i*i*i;
		for(long long j = 0; j < iii; ++j) {
			mods[i][(j*j*j) % iii] = true;
		}
	}
}
int main() {
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    int k, C;
    precalc();
    while (T-- > 0) {    	
    	cin >> k >> C;
    	if (C==0 || mods[k][k*k*k - C]) cout << "YES" << endl;
    	else cout << "NO" << endl;
    } 
    return 0;
}