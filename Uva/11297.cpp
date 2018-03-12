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

void recalc(int i, int j, int d, int N, vvi &rmi, vvi &rma, vvi &pop) {
    rma[i][j] = -1;
    rmi[i][j] = INT_MAX;
    for(int a = i*d; a < (i+1)*d; ++a) {
        for(int b = j*d; b < (j+1)*d; ++b) {
            rma[i][j] = max(rma[i][j], pop[a][b]);
            rmi[i][j] = min(rmi[i][j], pop[a][b]);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    int N, Q, d, ds;
    cin >> N;
    d = sqrt(N); ds = N/d;
    vvi rmi(ds, vi(ds, INT_MAX)), rma(ds, vi(ds, INT_MIN)), pop(N, vi(N, 0));
    REP(i, N) REP(j, N) {
        cin >> pop[i][j];
    }
    REP(i, ds) REP(j, ds) {
        recalc(i, j, d, N, rmi, rma, pop);
    }
    cin >> Q;
    string q; int x1, y1, x2, y2, v, m, M;
    REP(i, Q) {
        cin >> q;
        if (q == "q") {
            cin >> x1 >> y1 >> x2 >> y2; --x1; --x2; --y1; --y2;
            m = INT_MAX; M = -1;
            if (!(x2 - x1 < 2*d || y2 - y1 < 2*d)) {
                for(int a = (x1 + d - 1) / d; a < x2/d; ++a) {
                    for(int b = (y1 + d-1) / d; b < y2/d; ++b) {
                        M = max(M, rma[a][b]);
                        m = min(m, rmi[a][b]);
                    }
                }
                for(int a = x1; a <= x2; ++a) {
                    for(int b = y1; b < ((y1 + d - 1)/d)*d; ++b) {
                        M = max(M, pop[a][b]);
                        m = min(m, pop[a][b]);
                    }
                    for(int b = (y2/d)*d; b <= y2; ++b) {
                        M = max(M, pop[a][b]);
                        m = min(m, pop[a][b]);
                    }
                }
                for(int a = y1; a <= y2; ++a) {
                    for(int b = x1; b < ((x1 + d - 1)/d)*d; ++b) {
                        M = max(M, pop[b][a]);
                        m = min(m, pop[b][a]);
                    }
                    for(int b = (x2/d)*d; b <= x2; ++b) {
                        M = max(M, pop[b][a]);
                        m = min(m, pop[b][a]);
                    }
                }
            } else {
                for(int a = x1; a <= x2; ++a) {
                    for(int b = y1; b <= y2; ++b) {
                        M = max(M, pop[a][b]);
                        m = min(m, pop[a][b]);   
                    }
                }    
            }
            cout << M << " " << m << endl;
        } else {
            cin >> x1 >> y1 >> v; --x1; --y1; 
            pop[x1][y1] = v;
            if (x1 < ds*d && y1 < ds*d)
                recalc(x1/d, y1/d, d, N, rmi, rma, pop);
        }
    }
}