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

ll query(int *bit, int i) {
    ++i;
    ll res = 0;
    while(i > 0) {
        res += bit[i];
        i -= (i & -i);
    }
    return res;
}

void add(int *bit, int n, int i, int c) {
    ++i;
    while(i <= n) {
        bit[i] += c;
        i += (i & -i);
    }
}

int main() {
    ios::sync_with_stdio(false);
    int n, x, k = 0; cin >> n; int a[n], l[n], r[n], bit[n+2];
    unordered_map<int, int> m;
    REP(i, n+2) bit[i] = 0;
    REP(i, n) {
        cin >> x;
        if (m.find(x) == m.end()) {
            l[k] = r[k] = 0;
            m[x] = k++;
        }
        a[i] = m[x];
        add(bit, n+1, ++r[a[i]], 1);
    }
    ll res = 0;
    REP(i, n-1) {
        l[a[i]]++;
        add(bit, n+1, r[a[i]]--, -1);
        res += query(bit, l[a[i]] - 1);
    }
    cout << res << endl;
}
