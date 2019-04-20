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
        int P, K, L; cin >> P >> K >> L;
        int freq[L];
        REP(i, L) cin >> freq[i];
        sort(freq, freq+L);
        int l = L-1;
        ll res = 0;
        for(int i = 0; l >= 0 && i < P; ++i) {
            for(int j = 0; l >= 0 && j < K; ++j) {
                res += (i+1)*freq[l--]; 
            }
        }
        cout << "Case #" << t+1 << ": " << res << endl;
    }
}
