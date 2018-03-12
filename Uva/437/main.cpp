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


#include <bits/stdc++.h>

using namespace std;

// variation of lis
// or shortest path in dag

struct Box {
	double w, d, h;

	bool operator <(Box &b) {
		// strictly increasing base area
		return w * d < b.w * b.d;
	}
};

vector<Box> rotate(vector<Box> &boxes) {
	int n = boxes.size();
	vector<Box> ret(3 * n);

	double w, h, d;
	for(int i = 0; i < n; ++i) {
		w = boxes[i].w;
		h = boxes[i].h;
		d = boxes[i].d;
		// always w >= d, new height at the first height
		ret[i * 3] = {max(w, h), min(w, h), d};
		ret[i * 3 + 1] = {max(d, w), min(d, w), h};
		ret[i * 3 + 2] = {max(d, h), min(d, h), w};
	}
	return ret;
}

double tallest_stack(vector<Box> boxes) {
	sort(boxes.begin(), boxes.end());
	int n = boxes.size();
	vector<double> dp(n);
	double res = 0;
	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < i; ++j) {
			if(boxes[i].w > boxes[j].w && boxes[i].d > boxes[j].d) {
				dp[i] = max(dp[i], dp[j]);
			}
		}
		dp[i] += boxes[i].h;
		res = max(res, dp[i]);
	}
	return res;
}

int main() {
    ios::sync_with_stdio(false);
    int N;
    cin >> N;
    vector<Box> boxes;
    double w, d, h;
    int c = 1;
    while (N > 0) {
    	boxes.resize(N);
    	for(int i = 0; i < N; ++i) {
    		cin >> w >> d >> h;
    		boxes[i] = {w, d, h};
    	}
    	cout << "Case " << c++ << ": maximum height = ";
    	boxes = rotate(boxes);
    	cout << tallest_stack(boxes) << endl;
    	cin >> N;
    }
    return 0;
}