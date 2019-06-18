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
    int T; cin >> T;
    string s;
    getline(cin, s);
    for(int t = 1; t <= T; ++t) {
        getline(cin, s);
        int b = 0, l = s.length();
        for(int i = 1; i < l; ++i) {
            if (s[i] == 'B') ++b;
        }
        cout << "Case #" << t << ": ";
        cout << (b < l-1 && 2*b >= l-1 ? 'Y' : 'N') << endl;
    }
}
