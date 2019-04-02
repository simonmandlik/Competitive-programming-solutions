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
        int N, M, k, x, y; cin >> N >> M;
        vector<set<int>> unmalted(M);
        vi malted(M, -1), sol(N, 0), vis(M, 0);
        bool poss = true;
        queue<int> q;
        REP(i, M) {
            cin >> k;
            REP(j, k) {
                cin >> x >> y; --x;
                if (y == 1) malted[i] = x;
                else unmalted[i].insert(x);
            }
            if (unmalted[i].size() == 0) {
                q.push(i);
                vis[i] = 1;
            }
        }
        while(poss && !q.empty()) {
            int i = q.front(); q.pop();
            if (malted[i] == -1) poss = false;
            else if (sol[malted[i]] == 0) {
                sol[malted[i]] = 1;
                REP(j, M) {
                    if (vis[j]) continue;
                    auto it = unmalted[j].find(malted[i]);
                    if (it != unmalted[j].end()) {
                        unmalted[j].erase(it);

                        if (unmalted[j].size() == 0) {
                            vis[j] = 1;
                            q.push(j);
                        }
                    }
                }
            }
        }
        cout << "Case #" << t+1 << ":";
        if (poss) {
            for(int i : sol) cout << " " << i;
        } else {
            cout << " IMPOSSIBLE";
        }
        cout << endl;
    }
}
