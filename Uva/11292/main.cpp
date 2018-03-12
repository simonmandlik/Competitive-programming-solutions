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

vi heads(20000), knights(20000);

int main() {
    ios::sync_with_stdio(false);
    int k, h;
    cin >> h >> k;
    while (k != 0) {
    	for(int i = 0; i < h; ++i) cin >> heads[i];
    	for(int i = 0; i < k; ++i) cin >> knights[i];
    	sort(heads.begin(), heads.begin() + h);
    	sort(knights.begin(), knights.begin() + k);
    	int cost = 0;
    	bool doomed = false;
    	for(int i = 0, j = 0; i < h && !doomed; ++i) {
    		while(j < k && knights[j] < heads[i]) ++j;

    		if (j == k) doomed = true;
    		else cost += knights[j++];
    	}
    	if (!doomed) cout << cost << endl;
    	else cout << "Loowater is doomed!" << endl;

    	cin >> h >> k;
    }
    return 0;
}