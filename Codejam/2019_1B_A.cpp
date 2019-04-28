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

int optimal(vi &l, vi &r) {
    sort(l.begin(), l.end());
    sort(r.begin(), r.end());
    int best = 0, best_val = l.size();
    int li = 0, ri = 0;
    while(li < l.size() || ri < r.size()) {
        int x;
        if (li == l.size()) x = r[ri];
        else if (ri == r.size()) x = l[li];
        else if (l[li] < r[ri]) x = l[li];
        else x = r[ri];

        while(ri < r.size() && r[ri] == x) {
            int val = l.size() - li + ri + 1;
            if (best_val < val) {
                best_val = val;
                best = x;
            }
            ++ri;
        }
        while(li < l.size() && l[li] == x) {
            int val = l.size() - li + ri;
            if (best_val < val) {
                best_val = val;
                best = x;
            }
            ++li;
        }
    }
    return best;
}

int main() {
    ios::sync_with_stdio(false);
    int T; cin >> T;
    for(int t = 1; t <= T; ++t) {
        int P, Q; cin >> P >> Q;        
        int X, Y; char D;
        vi l, r, u, d;
        REP(i, P) {
            cin >> X >> Y >> D;
            if (D == 'W') l.push_back(X-1);
            if (D == 'E') r.push_back(X+1);
            if (D == 'S') d.push_back(Y-1);
            if (D == 'N') u.push_back(Y+1);
        }
        cout << "Case #" << t << ": " << optimal(l, r) << " " << optimal(d, u);
        cout << endl;
    }
}
