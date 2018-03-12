#include <bits/stdc++.h>
using namespace std;
#define EPS (1e-10)
#define DEBUG(x) cout << "> " << #x << ": " << x << endl;
#define REP(i, n) for (int i = 0; i < (n); i++)
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define FORD(i, a, b) for (int i = (a); i >= (b); i--)
#define BE(c) c.begin(), c.end()
#define PB(v, i) v.push_back(i)
typedef long double ld;
typedef long long ll;
typedef pair<int, int> ii;
typedef pair<double, double> dd;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<double> vd;
typedef vector<bool> vb;
typedef vector<vector<int>> vvi;
typedef vector<ii> vii;

typedef vvi Matrix;

const int MOD = 10;

void matmul(Matrix &A, Matrix &B, Matrix &C) {
	REP(i, A.size()) REP(j, A.size()) C[i][j] = 0;
	REP(i, A.size()) REP(j, A.size()) REP(k, A.size()) {
		C[i][j] += (A[i][k] * B[k][j]) % MOD;
		C[i][j] %= MOD;
	}
}

void add(int c, Matrix &A) {
	REP(i, A.size()) {
		A[i][i] += c;
		A[i][i] %= MOD;
	}
}

void add(Matrix &A, Matrix &B, Matrix &C) {
	REP(i, A.size()) REP(j, A.size()) {
		C[i][j] = (A[i][j] + B[i][j]) % MOD;
	}
}

void power(Matrix &A, Matrix &res, int p) {
	Matrix tmp(A.size(), vi(A.size()));
	REP(i, A.size()) REP(j, A.size()) res[i][j] = 0;
	REP(i, A.size()) res[i][i] = 1;

	while(p > 0) {
		if (p%2 == 1) {
			matmul(A, res, tmp);
			REP(i, A.size()) REP(j, A.size()) res[i][j] = tmp[i][j];
		} 
		matmul(A, A, tmp);
		REP(i, A.size()) REP(j, A.size()) A[i][j] = tmp[i][j];
		p /= 2;
	}
}

void print_mat(Matrix &A) {
    REP(i, A.size()) {
    	cout << A[i][0];
    	FOR(j, 1, A.size()) {
    		cout << " " << A[i][j];
    	}
    	cout << endl;
    }
}

void solve(Matrix &A, Matrix &res, int k) {
	if (k == 0) {
		REP(i, A.size()) REP(j, A.size()) res[i][j] = 0;
		REP(i, A.size()) res[i][i] = 1;
	} else if (k == 1) {
		REP(i, A.size()) REP(j, A.size()) res[i][j] = A[i][j];
	} else {
		Matrix tmp(A.size(), vi(A.size())), tmp2(A.size(), vi(A.size()));
		solve(A, res, k/2);
		REP(i, A.size()) REP(j, A.size()) tmp2[i][j] = A[i][j];
		power(tmp2, tmp, k/2);
		add(1, tmp);
		matmul(res, tmp, tmp2);
		REP(i, A.size()) REP(j, A.size()) res[i][j] = tmp2[i][j];
		// print_mat(res);
		if (k % 2 == 1) {
			REP(i, A.size()) REP(j, A.size()) tmp2[i][j] = A[i][j];
			power(tmp2, tmp, k);
			// print_mat(tmp);
			add(res, tmp, res);
		}
	}
	// cout << k << endl;
	// print_mat(res);
	// cout <<endl<<endl;
}

int main() {
    ios::sync_with_stdio(false);
    int n, k; 
    while(cin >> n >> k) {
    	if (n == 0) break;
	    Matrix A(n, vi(n)), res(n, vi(n));
	    REP(i, n) REP(j, n) { cin >> A[i][j]; A[i][j] %= MOD; }
	    // REP(i, 5) {
	    // 	power(A, res, i);
	    // 	print_mat(res);
	    // 	cout << endl;
	    // }
	    solve(A, res, k);
	    print_mat(res);
	    cout << endl;
	}
	
}