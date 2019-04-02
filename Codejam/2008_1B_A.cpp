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
        ll res = 0, a[3][3];
        REP(i, 3) REP(j, 3) a[i][j] = 0;
        int n, x, y, B, D, M;
        ll A, C;
        cin >> n >> A >> B >> C >> D >> x >> y >> M;
        REP(i, n) {
            a[x%3][y%3]++;
            x = (A*x + B) % M;
            y = (C*y + D) % M;
        }
        REP(i, 3) REP(j, 3) res += (a[i][j] * (a[i][j] - 1) * (a[i][j] - 2)) / 6;
        REP(i, 9) FOR(j, i+1, 9) FOR(k, j+1, 9) {
            if ((i/3 + j/3 + k/3) % 3 == 0 &&
                (i%3 + j%3 + k%3) % 3 == 0) {
                res += a[i/3][i%3]*a[j/3][j%3]*a[k/3][k%3];
            }
        }
        cout << "Case #" << t+1 << ": " << res << endl;
    }
}
