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

int comb[30][30];

void compute_comb() {
	comb[0][0] = comb[1][1] = comb[1][0] = 1;
	for(int i = 2; i <= 26; ++i) {
		comb[i][0] = 1;
		for (int j = 1; j <= 26; ++j) comb[i][j] = comb[i-1][j-1] + comb[i-1][j];
	}
}

int main() {
    ios::sync_with_stdio(false);
    int a, b;
    cin >> a >> b;
    compute_comb();
    cout << fixed << setprecision(8);
    while (a >= 0) {
    	double result = comb[13][a] * comb[13][b];
    	result /= comb[26][a+b];
    	if (a != b) result *= 2;
    	cout << a << '-' << b << " split: " << result << endl;
    	cin >> a >> b;
    }
    return 0;
}