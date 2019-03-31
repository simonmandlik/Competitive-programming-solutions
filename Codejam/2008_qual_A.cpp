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
        int S, Q; cin >> S;
        vb v(S, false);
        string s, q;
        unordered_map<string, int> m;
        getline(cin, s);
        REP(i, S) {
            getline(cin, s);
            m[s] = i;
        }
        int res = 0, k = 0;
        cin >> Q;
        getline(cin, q);
        REP(i, Q) {
            getline(cin, q);
            int l = m[q];
            if (!v[l]) {
                if (k+1 == S) {
                    res++;
                    fill(v.begin(), v.end(), false);
                    k = 0;
                }
                v[l] = true;
                ++k;
            }
        }
        cout << "Case #" << t+1 << ": " << res << endl;
    }
}
