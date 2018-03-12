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

ll res;

void mergesort(int i, int j, vi &a, vi &b) {
    if (i+1 >= j) return;
    int m = i + (j-i)/2;
    mergesort(i, m, b, a);
    mergesort(m, j, b, a);
    int ii = i, ji = m, k = i;
    while(ii < m && ji < j) {
        if (b[ii] < b[ji]) {
            a[k++] = b[ii++];
        } else {
            a[k++] = b[ji++];
            res += m - ii;
        }
    }
    while(ii < m) {
        a[k++] = b[ii++];
    }
    while(ji < j) {
        a[k++] = b[ji++];
    }
}

int main() {
    ios::sync_with_stdio(false);
    int T, N; cin >> T; string s;
    while(T-- > 0) {
        cin >> N;
        unordered_map<string, int> m;
        vi a(N), b(N);
        REP(i, N) {
            cin >> s;
            m[s] = i;
        }
        REP(i, N) {
            cin >> s;
            a[i] = b[i] = m[s];
        }
        res = 0;
        mergesort(0, N, a, b);
        cout << res << endl;        
    }
}