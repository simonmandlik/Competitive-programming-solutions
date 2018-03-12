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
    int T, x, y, N;
    string s; stringstream ss;
    getline(cin, s); ss = stringstream(s);
    ss >> T; getline(cin, s);
    while(T-- > 0) {
        vector<Point> p;
        while(getline(cin, s) && s.length() > 0) {
            ss = stringstream(s);
            ss >> x >> y;
            p.push_back({x, y});            
        }
        N = p.size();
        int res, m = 2;
        for(int i = 0; i < N; ++i) {
            for(int j = i+1; j < N; ++j) {
                res = 0;
                for(int k = 0; k < N; ++k) {
                    if ((p[k].x-p[i].x)*(p[j].y-p[i].y) - (p[k].y-p[i].y)*(p[j].x-p[i].x) == 0) {
                        ++res;
                    }
                }
                m = max(m, res);
            }
        }
        cout << m << endl;
        if (T != 0) cout << endl;
    }

}