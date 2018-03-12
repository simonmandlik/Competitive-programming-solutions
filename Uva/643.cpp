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

int main() {
    ios::sync_with_stdio(false);
    int N, x, y, last_x, last_y, tx, ty, y1, y2; bool found;
    while(cin >> N && N != 0) {
        vii points; set<int> active;
        REP(i, N) {
            cin >> x >> y;
            points.push_back({x, y});
        }
        cin >> tx >> ty;
        sort(points.begin(), points.end());
        if (tx < points[0].first || tx > points[points.size()-1].first) {
            cout << "F" << endl;
            continue;
        }
        for(auto &p : points) {
            if (last_x <= tx && tx <= p.first) {
                found = false;
                for(int k = 0; !found && k < active.size(); k+=2) {
                    y1 = *active.begin(); active.erase(active.begin());
                    y2 = *active.begin(); active.erase(active.begin());
                    if (y1 <= ty && ty <= y2) found = true; 
                }
                cout << (found ? "T":"F") << endl;
                break;
            }
            if (active.count(p.second) > 0) {
                active.erase(p.second);
            } else {
                active.insert(p.second);
            }
            last_x = p.first;
        }
    }
    
}