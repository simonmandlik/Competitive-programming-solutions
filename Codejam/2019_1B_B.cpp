#include <bits/stdc++.h>
#pragma GCC optimize ("Ofast")
using namespace std;
#define EPS (1e-10)
#define DBG(x) cout << "> " << #x << ": " << x << endl;
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
typedef vector<string> vs;
typedef vector<vector<int>> vvi;
typedef vector<ii> vii;
////////////////////////////////////////////////////////////////////////////////

int main() {
    ios::sync_with_stdio(false);
    int T, W; cin >> T >> W;
    for(int t = 1; t <= T; ++t) {
        vll rings(7, 0);
        vll res(7, 0);
        REP(i, W) {
            cout << i+1 << endl;
            cin >> res[i+1];
        }

        vector<vll> A = {
            {4,   -4,   -2,   -0,    0,    1},
            {-48  , 48,    4 ,   0,    0,   -2},
            {-16,  -24 ,  48 ,   0  ,  0 ,  -4},
            {64 , -64 , -32 ,  40,    0  , -4},
            {-64 ,  64 ,  32,  -40,   40 , -16},
            {96  ,-16 , -48 ,   0 , -40  , 24}
        };

        REP(i, 6) {
            ll r = 0;
            REP(j, 6) {
                r += A[i][j] * res[j+1];
            }
            r /= 40;
            cout << r << " ";
        }
        cout << endl;

        int ans;
        cin >> ans;
        if (ans == -1) break;
    }
}
