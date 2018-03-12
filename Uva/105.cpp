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

struct E {
    int p, i, c;
};

bool operator<(E &lhs, E &rhs) { 
    return lhs.p < rhs.p;
}

int main() {
    ios::sync_with_stdio(false);
    int L, H, R, i = 0, last_h, last_x; bool first = true;
    vector<int> h; vector<E> events; set<ii, std::greater<ii>> active;
    while(cin >> L >> H >> R) {
        events.push_back({L, i, 0});
        events.push_back({R, i, 1});
        h.push_back(H);
        ++i;
    }
    sort(events.begin(), events.end());
    i = 0; last_h = -1;
    while(i < events.size()) {
        last_x = events[i].p;
        while(i < events.size() && events[i].p == last_x) {
            if (events[i].c == 1) {
                active.erase({h[events[i].i], events[i].i});
            } else {
                active.insert({h[events[i].i], events[i].i});
            }
            ++i;
        }
        if (active.begin()->first != last_h) {
            if (!first) {
                cout << " ";
            }
            first = false;
            cout << last_x << " " << active.begin()->first;        
            last_h = active.begin()->first;
        }
    }
    cout << endl;
}