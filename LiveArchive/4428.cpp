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
typedef pair<ld, ld> dd;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<ld> vd;
typedef vector<bool> vb;
typedef vector<vector<int>> vvi;
typedef vector<ii> vii;

struct Circle {
	ld x, y, R;
};

ld dist(ld x1, ld y1, ld x2, ld y2) {
	return sqrt((x2-x1)*(x2-x1) + (y2-y1)*(y2-y1));
}

bool conforms(ld x, ld y, ld R, Circle &c) {
	return (x-c.x)*(x-c.x)+(y-c.y)*(y-c.y) > 4*R*R - (1e-8);
}

bool conforms(ld x, ld y, ld R, vector<Circle> &circles) {
	for(Circle &c : circles) {
		if (!conforms(x, y, R, c)) return false;
	}
	return true;
}

int main() {
    int n; ld x, y, R, distance, d, dx, dy, ang;
    bool first = true;
    cout << fixed << setprecision(6);
    while(cin >> n >> R) {
    	if (n == 0) break;
    	if (!first) cout << endl;
    	first = false;
    	vector<Circle> circles(n);
    	REP(i, n) {
    		cin >> x >> y;
    		circles[i].x = x; circles[i].y = y; circles[i].R = R;
    	}
    	ld bx, by, bd = DBL_MAX;
    	x = y = 0;
    	if (conforms(x, y, R, circles)) {
    		cout << "0.000000";
    		continue;
    	}
    	for(Circle &c : circles) {
    		ang = atan2(c.y, c.x);
    			x = c.x + 2.0*cos(ang)*R;
    			y = c.y + 2.0*sin(ang)*R;
    			if (conforms(x, y, R, circles) && dist(0, 0, x, y) < bd)
    				bd = dist(0, 0, x, y); bx = x; by = y;
    			x = c.x - 2.0*cos(ang)*R;
    			y = c.y - 2.0*sin(ang)*R;
    			if (conforms(x, y, R, circles) && dist(0, 0, x, y) < bd)
    				bd = dist(0, 0, x, y); bx = x; by = y;
    	}
    	REP(i, n) FOR(j, i+1, n) {
			Circle &c1 = circles[i]; Circle &c2 = circles[j];	
			distance = dist(c1.x, c1.y, c2.x, c2.y);
			if (distance >= 4*R) continue;
			d = sqrt(4*R*R - distance*distance/4.0);
			x = (c1.x + c2.x) / 2.0;
			y = (c1.y + c2.y) / 2.0;
			dx = c1.x - c2.x;
			dy = c1.y - c2.y;
			dx /= distance;
			dy /= distance;
			x += d*dy;
			y += -d*dx;
			if (conforms(x, y, R, circles) && dist(0, 0, x, y) < bd)
				bd = dist(0, 0, x, y); bx = x; by = y;
			x += -2.0*d*dy;
			y += 2.0*d*dx;
			if (conforms(x, y, R, circles) && dist(0, 0, x, y) < bd)
				bd = dist(0, 0, x, y); bx = x; by = y;
    	}
    	cout << bd;
    }	
}