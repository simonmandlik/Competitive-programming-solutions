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

struct Point {
	double x, y; 
	bool operator<(Point &other) { return x < other.x || x == other.x && y < other.y; }
};

struct y_comp {
	bool operator()(Point &a, Point &b) {
		return a.y < b.y || a.y == b.y && a.x <= b.x;
	}
};

double dist(Point &a, Point&b) {
	return sqrt((a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y));
}

double closest_two_points_dist_brute(vector<Point> &p, int k, int l) {
	double res = DBL_MAX;
	FOR(i, k, l) FOR(j, k, l) if (i != j) res = min(res, dist(p[i], p[j]));
	return res;
}

double closest_two_points_dist(vector<Point> &pa, vector<Point> &pb, vector<Point> &ib, int from, int to) {
	if (to-from <= 3) {
		sort(pa.begin() + from, pa.begin() + to, y_comp());
		return closest_two_points_dist_brute(pa, from, to);
	}
	else {
		double lx = (pa[(from+to)/2-1].x + pa[(from+to)/2].x)/2;
		double d = min(closest_two_points_dist(pb, pa, ib, from, (from+to)/2),
					   closest_two_points_dist(pb, pa, ib, (from+to)/2, to));
		int lb = from, ub = (from+to)/2, i = from;
		while(lb < (from+to)/2 && ub < to) {
			if (pb[lb].y < pb[ub].y) pa[i++] = pb[lb++];
			else pa[i++] = pb[ub++];
		}
		while(lb < (from+to)/2) pa[i++] = pb[lb++];
		while(ub < to) pa[i++] = pb[ub++];
		int j = 0;
		for(int i = from; i < to; ++i) if (abs(pa[i].x - lx) <= d) ib[j++] = pa[i]; // inside_belt
		lb = ub = i = 0;
		while(i < j) {
			while(ib[i].y - ib[lb].y > d) ++lb;
			while(ub < j-1 && ib[ub+1].y - ib[i].y <= d) ++ub;
			for(int k = lb; k <= ub; ++k) {
				if (k != i) d = min(d, dist(ib[i], ib[k]));
			}
			++i;
		}
		return d;
	}
}

int main() {
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(4);
    int n;
    while(cin >> n && n > 0) {
    	vector<Point> p1(n), p2(n), ib(n);
    	REP(i, n) cin >> p1[i].x >> p1[i].y;
    	copy(p1.begin(), p1.end(), p2.begin());
    	sort(p1.begin(), p1.end());
    	sort(p2.begin(), p2.end());
    	double d = closest_two_points_dist(p1, p2, ib, 0, n);
    	if (d <= 10000) cout << d << endl;
    	else cout << "INFINITY" << endl;
    }
}