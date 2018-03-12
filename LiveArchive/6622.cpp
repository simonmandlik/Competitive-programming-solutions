#include <bits/stdc++.h>
using namespace std;
#define EPS (1e-10)
#define DEBUG(x) cout << "> " << #x << ": " << x << endl;
#define REP(i, n) for (int i = 0; i < (n); i++)
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define FORD(i, a, b) for (int i = (a); i >= (b); i--)
#define BE(c) c.begin(), c.end()
#define PB(v, i) v.push_back(i)
typedef long long ll;
typedef pair<int, int> ii;
typedef pair<double, double> pdd;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<double> vd;
typedef vector<bool> vb;
typedef vector<vector<int>> vvi;
typedef vector<ii> vii;

struct Edge {int from, to, w; };

bool operator<(Edge &lhs, Edge &rhs) { return lhs.w < rhs.w; }

int root(int u, vi &parents) { return (parents[u] == -1) ? u : (parents[u] = root(parents[u], parents)); }
int find(int u, int v, vi &parents) {return root(u, parents) == root(v, parents); }
void unite(int u, int v, vi &parents, vi& levels) {
    int x = root(u, parents), y = root(v, parents);
    if (levels[x] < levels[y]) {
        parents[x] = y;
    } else if (levels[x] > levels[y]) {
        parents[y] = x;
    } else {
        parents[y] = x; levels[x]++;
    }
}

void dfs(int n, int u, vvi &neighL, vvi &adjM, vvi &MSTD, int d) {
    MSTD[n][u] = d;
    for(int v : neighL[u]) {
        if (MSTD[n][v] == INT_MAX)
            dfs(n, v, neighL, adjM, MSTD, d + adjM[u][v]);
    }
}

int main() {
    ios::sync_with_stdio(false);
    int N, t = 0;
    while(cin >> N) {
        if (t++ > 0) cout << endl;
        vvi distM(N, vi(N, INT_MAX)), adjM(N, vi(N, INT_MAX)), MSTD(N, vi(N, INT_MAX));
        vvi neighL(N, vi());
        vector<Edge> e((N*(N-1))/2);
        int ei = 0;
        REP(i, N) REP(j, N) {
            cin >> distM[i][j];
            if (i < j) e[ei++] = {i, j, distM[i][j]};
        }

        vi parents(N, -1), levels(N, 1);

        sort(e.begin(), e.end());
        ei = 0;
        for(auto ed : e) {
            if (!find(ed.from, ed.to, parents)) {
                cout << ed.from+1 << " " << ed.to+1 << " " << ed.w << endl;
                unite(ed.from, ed.to, parents, levels);
                adjM[ed.from][ed.to] = adjM[ed.to][ed.from] = ed.w;
                PB(neighL[ed.from], ed.to);
                PB(neighL[ed.to], ed.from);
                if (++ei == N-1) break;
            }
        }

        REP(i, N) dfs(i, i, neighL, adjM, MSTD, 0);

        int b = INT_MAX, u, v;
        REP(i, N) REP(j, N) {
            if (i < j && MSTD[i][j] > distM[i][j] && distM[i][j] < b) {
                u = i; v = j; b = distM[i][j];
            }
        }
        cout << u+1 << " " << v+1 << " " << b << endl;        
    }
}