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

struct Constraint {
    int x, y, z;
};

bool solve(vector<Constraint> &C, set<int> S, vi &sol, int N, int p) {
    for(int r : S) {
        bool valid = true;
        vi newS(N+1);
        for(int v : S) {
            if (v != r) newS[v] = v;
        }
        for (auto &c : C) {
            if (S.find(c.x) == S.end() || S.find(c.y) == S.end() || S.find(c.z) == S.end()) continue;
            if (c.x != r && c.y != r && c.z != r) {
                int s = min(newS[c.x], min(newS[c.y], newS[c.z]));
                for(int i = 1; i <= N; ++i) {
                    if (newS[i] == newS[c.x] || newS[i] == newS[c.y] || newS[i] == newS[c.z]) {
                        newS[i] = s;

                    }

                }
            }
        }
        for (auto &c : C) {
            if (S.find(c.x) == S.end() || S.find(c.y) == S.end() || S.find(c.z) == S.end()) continue;
            if (c.x == r || c.y == r) {
                if (c.z != r) {
                    valid = false;
                    break;
                }
            }
            if (c.z == r) {
                if (newS[c.x] == newS[c.y]) {
                    valid = false;
                    break;
                }
            }
        }

        if (valid) {
            for(int i : S) {
                if (newS[i] != i) continue;
                set<int> nS;
                for(int j : S) {
                    if (newS[j] == i) {
                        nS.insert(j);
                    }
                }
                if (nS.size() > 1) {
                    if (!solve(C, nS, sol, N, r)) {
                        return false;
                    }
                } else {
                    sol[i] = r;
                }
            }
            sol[r] = p;
            return true;
        }
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    int T, N, M; cin >> T;
    for(int t = 1; t <= T; ++t) {
        cin >> N >> M;
        vector<Constraint> C(M);
        REP(i, M) {
            cin >> C[i].x >> C[i].y >> C[i].z; 
            if (C[i].x > C[i].y) swap(C[i].x, C[i].y);
        }
        set<int> S;
        REP(i, N) S.insert(i+1);
        vi sol(N+1, -1);
        cout << "Case #" << t << ": ";
        if (solve(C, S, sol, N, 0)) {
            for(int i = 1; i <= N; ++i) cout << sol[i] << " ";
            cout << endl;
        } else {
            cout << "Impossible" << endl;
        }
    }
}
