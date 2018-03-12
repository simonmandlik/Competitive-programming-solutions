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
typedef pair<double, double> dd;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<double> vd;
typedef vector<bool> vb;
typedef vector<vector<int>> vvi;
typedef vector<ii> vii;

struct Point { int x, y; };

int main() {
    ios::sync_with_stdio(false);
    int N, tx, ty, x, y; double r;
    while(cin >> tx >> ty >> r >> N) {
        if (r < 0) break;
        vector<Point> p;
        REP(i, N) {
            cin >> x >> y;
            x -= tx; y -= ty;
            if (x*x + y*y <= r*r) p.push_back({x, y});
        }
        int res = 0, m = 0;
        N = p.size();
        REP(i, N) {
            res = 1;
            REP(j, N) {
                if (i != j && p[i].x*p[j].y - p[i].y*p[j].x >= 0) {
                    ++res;
                }
            }
            m = max(res, m);
        }
        cout << m << endl;
    }
}