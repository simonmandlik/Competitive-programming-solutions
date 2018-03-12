#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<vector<long long>> vvl;

#define INF 1000000000 // 1 billion, safer than 2B for Floyd Warshall’s
#define DEBUG(x) cout << '>' << #x << ':' << x << endl;
#define REP(i, n) for(int i=0;i<(n);i++)
#define FOR(i, a, b) for(int i=(a);i<=(b);i++)
#define FORD(i, a, b) for(int i=(a);i>=(b);i--)

inline bool EQ(double a, double b) { return fabs(a-b) < 1e-9; }

const ll MOD = 1000000007;

void matrix_multiplication(vvl &A, vvl &B, vvl &C) {
	for (int i = 0; i < 2; ++i) {
		for (int j = 0; j < 2; ++j) {
			C[i][j] = 0;
			for (int k = 0; k < 2; ++k) {
				C[i][j] += A[i][k] * B[k][j];
				C[i][j] = C[i][j] % MOD;
			}
		}		
	}
}

void matrix_power_iterative(vvl &z, vvl &res, int p){
	vvl temp = {{0, 0}, {0, 0}} ;
	while(p > 0) {
		if (p & 1) {
			matrix_multiplication(res, z, temp);
			for(int i = 0; i < 2; ++i)
				for(int j = 0; j < 2; ++j)
					res[i][j] = temp[i][j];
		}
		matrix_multiplication(z, z, temp);
		for(int i = 0; i < 2; ++i)
				for(int j = 0; j < 2; ++j)
					z[i][j] = temp[i][j];
		p /= 2;
	}
}

ll fib(int a) {
	if (a == 0) return 0;
	if (a == 1) return 1;
	vvl z = {{0, 1}, {1, 1}};
	vvl res = {{1, 0}, {0, 1}};
	matrix_power_iterative(z, res, a-1);
	return res[1][1];
}

int main() {
    ios::sync_with_stdio(false);
    int T;
    ll a, b;
    cin >> T;
    for(int i = 0; i < 100; ++i) cout << fib(i) << endl;
    while (T-- > 0) {
    	cin >> a >> b;
    	cout << ((fib(b+2) - fib(a+1) + MOD) % MOD) << endl;
    }
    return 0;
}