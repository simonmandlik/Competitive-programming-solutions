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
    int T;
    double H, M, S, U;
    double ang1, ang2;
    double r;
    cin >> T;
    cout << fixed << setprecision(3);
    int t = 1;
    while (t <= T) {
    	cin >> H >> M >> S >> U;
    	ang1 = (H + M / 60 + S / 3600 + U / 360000);
    	cin >> H >> M >> S >> U;
    	ang2 = (H + M / 60 + S / 3600 + U / 360000);
    	cin >> r;
    	cout << t++ << ". ";
    	cout << r * r * M_PI * ((ang2 - ang1) / 12) << endl;
    }
    return 0;
}