#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;

#define INF 1000000000 // 1 billion, safer than 2B for Floyd Warshall’s
#define DEBUG(x) cout << '>' << #x << ':' << x << endl;
#define REP(i, n) for(int i=0;i<(n);i++)
#define FOR(i, a, b) for(int i=(a);i<=(b);i++)
#define FORD(i, a, b) for(int i=(a);i>=(b);i--)

inline bool EQ(double a, double b) { return fabs(a-b) < 1e-9; }

struct Point {
	double x, y;

	bool operator<(Point &X) {
		return x < X.x || (x == X.x && y < X.y);
	}
};

double wedge_product(Point &A, Point &B, Point &X) {
	return (X.x - A.x)*(B.y - A.y) - (X.y - A.y)*(B.x - A.x);
}

vector<Point> graham_scan(vector<Point> points) {
	int n = points.size(), k = 0;
	vector<Point> res(2 * n);

	sort(points.begin(), points.end());

	for(int i = 0; i < n; ++i) {
		while(k > 1 && wedge_product(res[k - 2], res[k - 1], points[i]) >= 0) --k;
		res[k++] = points[i];
	}

	for(int i = n-2, t=k; i >= 0; --i) {
		while(k > t && wedge_product(res[k - 2], res[k - 1], points[i]) >= 0) --k;
		res[k++] = points[i];
	}

	res.resize(k - 1);
	return res;
}

double polygon_area(vector<Point> points) {
	double area = 0;
	int j = points.size() - 1;
	for(int i = 0; i < points.size(); ++i) {
		area += ((points[j].x + points[i].x) * (points[j].y - points[i].y));
		j = i;
	}
	return abs(area) / 2;

}

int main() {
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(2);
    int N;
    double x, y;
    cin >> N;
    vector<Point> points;
    int k = 0;
    while (N > 0) {
    	++k;
    	points.resize(N);
    	for(int i = 0; i < N; ++i) {
    		cin >> x >> y;	
    		points[i] = {x, y};
    	}
    	
    	cout << "Tile #" << k << "\nWasted Space = ";
    	cout << 100 * (1 - polygon_area(points) / polygon_area(graham_scan(points)));
    	cout << " %\n\n";
    	cin >> N;
    }
    return 0;
}