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

bool solve(int a) {
	if (a < 2) return false;
	for(int i = 2; a > 1; ++i) {
		if (a % i == 0) {
			if (i % 10 != 3) return false;
			else while(a % i == 0) a /= i;
		}
	}
	return true;
}

int main() {
	int a;
	cin >> a;
	while (a != -1) {
		cout << a << " " << (solve(a) ? "YES" : "NO") << '\n';
		cin >> a;
	}
    return 0;
}