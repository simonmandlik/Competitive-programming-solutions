#include <bits/stdc++.h>
#pragma GCC optimize ("Ofast")
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

int main() {
    ios::sync_with_stdio(false);
    int T; cin >> T;
    REP(t, T) {
        int N; cin >> N;
        vll A(N), B(N);
        REP(i, N) cin >> A[i];
        REP(i, N) cin >> B[i];
        sort(A.begin(), A.end());
        sort(B.begin(), B.end());
        ll res = 0;
        for (int i = 0; i < N; ++i) res += A[i] * B[N-i-1];
        cout << "Case #" << t+1 << ": " << res << endl;
    }
}
