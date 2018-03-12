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

double det (double x1, double y1, double x2, double y2) {
	return x1 * y2 - x2 * y1;
}

double solve(int n, vii &vectors) {
	sort(vectors.begin(), vectors.begin() + n);
	int m = -1;
	int X, Y;
	double x, y; // normal equation
	for (int i = 0; i < n; ++i) {
		x = vectors[i].first;
		y = vectors[i].second;
		X = x; Y = y;
		for(int j = 0; j < n; ++j) {
			if (i != j) {
				if (det(x, y, vectors[j].first, vectors[j].second) > 0) {
					X += vectors[j].first;
					Y += vectors[j].second;
				} else {
					X -= vectors[j].first;
					Y -= vectors[j].second;
				}
			}
		}
		m = max(m, X*X + Y*Y);
	}
	return m;
}

int main() {
    ios::sync_with_stdio(false);
    int N, f, s;
    vii vectors(101);
    cin >> N;
    cout << fixed << setprecision(3);
    while (N > 0) {
    	for(int i = 0; i < N; ++i) {
    		cin >> f >> s;
    		vectors[i].first = f;
    		vectors[i].second = s;
    	}
    	cout << "Maximum distance = ";
    	cout << sqrt(solve(N, vectors)) << " meters." << endl;
    	cin >> N;
    }
    return 0;
}