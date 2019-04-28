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

void build(vi &a, vvi &st) {
    int m = floor(log2(a.size()));
    int n = a.size() - 1;
    st.resize(m+1);
    for(int i = 0; i <= m; ++i) st[i].resize(n+1);

    for(int i = 0; i <= n; ++i) st[0][i] = a[i];
    for(int j = 1; j <= m; ++j)
        for(int i = 0; i + (1 << (j-1)) <= n; ++i)
            st[j][i] = max(st[j-1][i], st[j-1][i + (1 << (j-1))]);
}

int query(int l, int r, vvi &st) {
    int k = floor(log2(r-l+1));
    return max(st[k][l], st[k][r-(1 << k)+1]);
}

bool satisfies1_left(int l, int r, int c, int K, vvi &stC, vvi &stD) {
    return (l==r || query(l, r-1, stC) < c) && query(l, r, stD) <= c + K;
}

bool satisfies1_right(int l, int r, int c, int K, vvi &stC, vvi &stD) {
    return query(l, r, stC) <= c && query(l, r, stD) <= c + K;
}

bool satisfies2_left(int l, int r, int c, int K, vvi &stC, vvi &stD) {
    return (l == r || query(l, r-1, stC) < c) && query(l, r, stD) < c - K;
}

bool satisfies2_right(int l, int r, int c, int K, vvi &stC, vvi &stD) {
    return query(l, r, stC) <= c && query(l, r, stD) < c - K;
}

int main() {
    ios::sync_with_stdio(false);
    int T; cin >> T ;
    for(int t = 1; t <= T; ++t) {
        int N, K; cin >> N >> K;
        vi C(N), D(N);
        vvi stC, stD;
        REP(i, N) cin >> C[i];
        REP(i, N) cin >> D[i];
        build(C, stC); build(D, stD);
        ll res1 = 0, res2 = 0;

        REP(i, N) {
            ll l = 0, r = i, L, R;
            L = satisfies1_left(i, i, C[i], K, stC, stD) ? i : -1;
            R = satisfies1_right(i, i, C[i], K, stC, stD) ? i : -1;
            while (l <= r) {
                int m = (l+r)/2; 
                if (satisfies1_left(m, i, C[i], K, stC, stD)) {
                    L = m;
                    r = m-1;
                }
                else l = m+1;
            }

            l = i, r = N-1;
            while (l <= r) {
                int m = (l+r)/2; 
                if (satisfies1_right(i, m, C[i], K, stC, stD)) {
                    R = m;
                    l = m+1;
                }
                else r = m-1;
            }
            if (R > -1 && L > -1) res1 += (i-L+1)*(R-i+1);
        }
        REP(i, N) {
            ll l = 0, r = i, L, R;
            L = satisfies2_left(i, i, C[i], K, stC, stD) ? i : -1;
            R = satisfies2_right(i, i, C[i], K, stC, stD) ? i : -1;
            while (l <= r) {
                int m = (l+r)/2; 
                if (satisfies2_left(m, i, C[i], K, stC, stD)) {
                    L = m;
                    r = m-1;
                }
                else l = m+1;
            }

            l = i, r = N-1;
            while (l <= r) {
                int m = (l+r)/2; 
                if (satisfies2_right(i, m, C[i], K, stC, stD)) {
                    R = m;
                    l = m+1;
                }
                else r = m-1;
            }
            if (R > -1 && L > -1) res2 += (i-L+1)*(R-i+1);
        }

        cout << "Case #" << t << ": " << res1 - res2 << endl;
    }
}
