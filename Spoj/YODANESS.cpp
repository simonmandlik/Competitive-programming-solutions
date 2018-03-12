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
typedef pair<double, double> pdd;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<double> vd;
typedef vector<bool> vb;
typedef vector<vector<int>> vvi;
typedef vector<ii> vii;

void add(int i, vll &fw) {
    while(i < fw.size()) {
        ++fw[i];
        i += i&(-i);
    }
}

ll query(int i, vll &fw) {
    ll res = 0;
    while (i > 0) {
        res += fw[i];
        i -= i&(-i);
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    int T, N; cin >> T; string s;
    while(T-- > 0) {
        cin >> N;
        unordered_map<string, int> m;
        vll fw(N+1, 0);
        vi a(N);
        REP(i, N) {
            cin >> s;
            m[s] = i;
        }
        REP(i, N) {
            cin >> s;
            a[i] = m[s]+1;
        }
        ll res = 0;
        FORD(i, N-1, 0) {
            res += query(a[i], fw);
            add(a[i], fw);
        }
        cout << res << endl;
    }
}