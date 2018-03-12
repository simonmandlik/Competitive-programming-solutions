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

int p, q, r, s, t, u;

inline double f(double x) {
	return p * exp(-x) + q * sin(x) + r * cos(x) + s * tan (x) + t * x * x + u;
}

double bisection() {
	double xa = 0, xb = 1;
	while(xa + (1e-9) < xb) {
		double x = (xa + xb) / 2;
		if (f(xa) * f(x) > 0) {
			xa = x;
		} else {
			xb = x;
		}
	}
	return (xa + xb) / 2;
}

int main() {
    ios::sync_with_stdio(false);
  	cout << fixed << setprecision(4);
    while (cin >> p >> q >> r >> s >> t >> u) {
    	if (f(0) * f(1) > 0) {
    		cout << "No solution" << endl;	
    	} else {
    		cout << bisection() << endl;
    	}
    	
    }
    return 0;
}