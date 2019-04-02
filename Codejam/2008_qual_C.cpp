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

double seg(double rad, double th) {
    return rad*rad*(th - sin(th))/2;
}

double solve(double f, double R, double t, double r, double g) {
    // radius of area, where fly could be and not hit the ring
    double rad = R-t-f, area = 0;
    // go through the whole upper right quadrant, the center of the circle is in (0, 0)
    double x1, y1, x2, y2;
    for(x1 = r+f; x1 < rad; x1 += 2*r+g) {
        for(y1 = r+f; y1 < rad; y1 += 2*r+g) { 
            x2 = x1 + g - 2*f; y2 = y1 + g - 2*f;
            if (x1*x1 + y1*y1 >= rad*rad) continue;
            // everything inside the circle
            if (x2*x2 + y2*y2 <= rad*rad) area += (x2-x1)*(y2-y1);
            // only (x1, y1) inside
            else if (x1*x1 + y2*y2 >= rad*rad &&
                    x2*x2 + y1*y1 >= rad*rad)
                area += seg(rad, acos(x1/rad) - asin(y1/rad)) +
                    (sqrt(rad*rad - x1*x1)-y1) * (sqrt(rad*rad - y1*y1)-x1) / 2;
            // (x1, y1) and (x2, y1) inside
            else if (x1*x1 + y2*y2 >= rad*rad)
                area += seg(rad, acos(x1/rad) - acos(x2/rad)) +
                    (x2-x1) * (sqrt(rad*rad - x1*x1)-y1 + sqrt(rad*rad - x2*x2)-y1) / 2;
            // (x1, y1) and (x1, y2) inside
            else if (x2*x2 + y1*y1 >= rad*rad)
                area += seg(rad, asin(y2/rad) - asin(y1/rad)) +
                    (y2-y1) * (sqrt(rad*rad - y1*y1)-x1 + sqrt(rad*rad - y2*y2)-x1) / 2;
            else
                // all but (x2, y2) inside the circle
                area += seg(rad, asin(y2/rad) - acos(x2/rad)) +
                    (x2-x1)*(y2-y1) -
                    (y2-sqrt(rad*rad - x2*x2)) * (x2-sqrt(rad*rad - y2*y2)) / 2;
        }
    }
    double whole_area = M_PI*R*R;
    return 1.0 - 4.0*area / whole_area;
}

int main() {
    ios::sync_with_stdio(false);
    int T; cin >> T;
    cout << fixed << setprecision(7);
    REP(t, T) {
        double f, R, s, r, g;
        cin >> f >> R >> s >> r >> g;
        cout << "Case #" << t+1 << ": " << solve(f, R, s, r, g) << endl;
    }
}
