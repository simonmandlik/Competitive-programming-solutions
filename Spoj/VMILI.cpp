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

struct Point { double x, y; int i; };

bool operator<(Point &A, Point &B) {
    if (A.x == B.x) return A.y < B.y;
    else return A.x < B.x;
}

Point operator-(Point &A, Point &B) { return {A.x - B.x, A.y - B.y, -1}; }

double det (Point &A, Point &B, Point &C) {
    Point u = B-A, v = C-B;
    return u.x*v.y - u.y*v.x;
}

int main() {
    ios::sync_with_stdio(false);
    int N, hulls, u, l, r, i; cin >> N;
    vector<Point> p(N); vb used(N, false);
    REP(i, N) {
        cin >> p[i].x >> p[i].y;
    }
    sort(p.begin(), p.end());
    REP(i, N) {
        p[i].i = i;
    }
    vector<Point> hull(2*N);
    hulls = 0;
    u = 0;
    while(u < N - 2) {
        i = 0;
        while(used[i]) ++i;
        hull[0] = p[i]; ++i;
        while(used[i]) ++i;
        hull[1] = p[i]; ++i;
        l = 2;
        for(; i < N; ++i) {
            if (used[i]) continue;
            while (l > 1 && det(hull[l-2], hull[l-1], p[i]) >= 0) --l;
            hull[l++] = p[i];
        }
        i = N-1;
        while(used[i]) --i; --i;
        while(used[i]) --i;
        hull[l] = p[i]; --i;
        r = l+1;
        for(; i >= 0; --i) {
            if (used[i]) continue;
            while (r > l && det(hull[r-2], hull[r-1], p[i]) >= 0) --r;
            hull[r++] = p[i];
        }
        --r; //last point
        REP(j, r) {
            used[hull[j].i] = true; ++u;
        }
        ++hulls;
    }
    cout << hulls << endl;
}
