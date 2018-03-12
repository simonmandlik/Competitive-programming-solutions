#include <bits/stdc++.h>
using namespace std;

#define vv(a) vector<vector<a>>
#define ll long long

inline bool EQ(double a, double b) { return fabs(a-b) < 1e-9; }

const int MOD = 1e9;

void matrix_mult(int n, vv(ll) &A, vv(ll) &B, vv(ll) &C, ll M) {
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			C[i][j] = 0;
			for (int k = 0; k < n; ++k) {
				C[i][j] += A[i][k] * B[k][j];
				C[i][j] = C[i][j] % M;
			}
		}		
	}
}

// considerably slower!!!
void matrix_power_recursive(int n, vv(ll) &a, vv(ll) &res, ll p, ll M) {
	vv(ll) temp(a);

	// unit matrix for p = 0
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			res[i][j] = 0;
		}
	}
	for (int i = 0; i < n; ++i) res[i][i] = 1;

	if (p == 0) return;
	if (p == 1) {
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				res[i][j] = a[i][j];
			}
		} 
		return;
	}
	matrix_power_recursive(n, a, res, p / 2, M);
	matrix_mult(n, res, res, temp, M);
	if (p & 1) {		
		matrix_mult(n, temp, a, res, M);			
	} else {
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				res[i][j] = temp[i][j];
			}
		}
	}
}
int main() {
    ios::sync_with_stdio(false);
    int T, K, n;
    cin >> T;
    while (T-- > 0) {
    	cin >> K;
    	vv(ll) in(K, vector<ll>(K, 0));
    	vv(ll) res(K, vector<ll>(K, 0));
    	for(int i = K-1; i > 0; --i) {
    		cin >> in[K-1][i];
    	}
    	vv(ll) f(K, 0);
  		for(int i = 0; i < K; ++i) {
    		cin >> f[i];
    	}  	
    	cin >> n;
    	if (n <= K) {
    		cout << f[n-1] << endl;
    	} else {
    		matrix_power_recursive(K, in, res, n-K-1, MOD);
    		ll a = 0;
    		for(int i = 0; i < K; ++i) {
    			
    		}
    		cout << a << endl;
    	}

    }
    return 0;
}