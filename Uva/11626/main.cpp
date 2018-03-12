#include <bits/stdc++.h>
using namespace std;

#define DEBUG(x) cout << '>' << #x << ':' << x << endl;
#define REP(i, n) for(int i=0;i<(n);i++)
#define FOR(i, a, b) for(int i=(a);i<=(b);i++)
#define FORD(i, a, b) for(int i=(a);i>=(b);i--);

struct Point {
	double x, y;
};

Point centroid;
Point start;

double polar_ang(Point p) {
	return atan2(p.y-centroid.y, p.x - centroid.x) + 2*M_PI;
}

bool operator <(Point p1, Point p2) {
	return polar_ang(p1) < polar_ang(p2);
}

bool operator ==(Point p1, Point p2) {
    return p1.x == p2.x && p1.y == p2.y;
}

bool operator !=(Point p1, Point p2) {
    return !(p1 == p2);
}

int main() {
    ios::sync_with_stdio(false);
    int T, N, x, y; string yes;
    cin >> T;
    int test = 1;
    double mean_x, mean_y;
    while (test <= T) {
    	cin >> N;
    	vector<Point> points;
    	start = {INT_MAX, INT_MAX};
        centroid = {0, 0};
    	Point next;
    	for(int i = 0; i < N; ++i) {
    		cin >> next.x >> next.y >> yes;
    		if (yes == "Y") {
    			if(start.x > next.x || start.x == next.x && start.y > next.y) {
    				start = next;
    			}
                centroid.x += next.x;
                centroid.y += next.y;
    			points.push_back(next);
    		}
    	}

        centroid.x /= points.size();
        centroid.y /= points.size();

    	sort(points.begin(), points.end());
    	cout << points.size() << endl;
        int s_i = 0;
        while(points[s_i] != start) {
            ++s_i;
        }

        for(int i = s_i; i < points.size(); ++i) {
            cout << (int)points[i].x << ' ' << (int)points[i].y << endl;
        }
    	for(int i = 0; i < s_i; ++i) {
    		cout << (int)points[i].x << ' ' << (int)points[i].y << endl;
    	}
    	test++;
    }
    return 0;
}