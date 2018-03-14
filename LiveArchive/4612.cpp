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
    cout << fixed << setprecision(10);
    int c, n, D; double x, y, f, scale, theta, r; cin >> c;
    while(c-- > 0) {
    	cin >> n;
    	vector<complex<double>> points;
    	REP(i, n) {
    		cin >> x >> y;
    		points.push_back({x, y});
    	}
    	cin >> D >> f;
    	vector<double> lens({0});
    	REP(i, n-1) lens.push_back(lens[i] + abs(points[i+1] - points[i]));
    	r = lens[n-1] / (abs(points[n-1] - points[0]));
    	REP(i, n) lens[i] /= lens[n-1];

    	complex<double> res(points[0]);
    	theta = 0; scale = 1.0;
    	REP(d, D) {
    		REP(i, n-1) {
    			if (f >= lens[i] && f <= lens[i+1]) {
    				f = (f-lens[i])/(lens[i+1]-lens[i]);
    				if (d+1 == D) {
    					res += polar(f*scale, theta)*(points[i+1]-points[i]);	
    				}
    				scale *= r*(lens[i+1]-lens[i]);
    				theta += arg((points[i+1] - points[i]) / (points[n-1] - points[0]));
    				break;
    			} else {
    				res +=  polar(scale, theta)*(points[i+1]-points[i]);
    			}
    		}
    	}
    	cout << res << endl;
    }
}