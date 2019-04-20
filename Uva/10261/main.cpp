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

vector<vector<bool>> left_platform(2001, vector<bool>(10001, false));
vector<vector<int>> backpointer(2001, vector<int>(10001, 0));
vi lenghts(2001);

void print_result(int car, int n) {
	if (car != 0) {
		print_result(car - 1, backpointer[car][n]);
		cout << (backpointer[car][n] == n ? "starboard" : "port") << endl;
	}
}

int main() {
    ios::sync_with_stdio(false);
    int T, L, l;
    cin >> T;
    while(T-- > 0) {
	    cin >> L;
	    L *= 100;
	    for(int i = 0; i <= L / 50; ++i) {
	    	fill(left_platform[i].begin(), left_platform[i].end(), false);
	    }
	    int best = 0, best_l = 0;
	    int car = 1;
	    int length_sum = 0;
	    left_platform[0][0] = true;
	    cin >> l;
	    while(l > 0) {
	    	lenghts[car] = l;
	    	length_sum += lenghts[car];
	    	for(int n = 0; n <= L; ++n) {
	    		//left
	    		if (n - lenghts[car] >= 0 && left_platform[car - 1][n - lenghts[car]]) {
	    			left_platform[car][n] = true;
	    			backpointer[car][n] = n - lenghts[car];
	    			best = car;
	    			best_l = n;
				//right
	    		} else if (length_sum - n <= L && left_platform[car - 1][n]) {
	    			left_platform[car][n] = true;
	    			backpointer[car][n] = n;
	    			best = car;
	    			best_l = n;
	    		}    		
	    	}
	    	++car;
	    	cin >> l;
	    }
	    cout << best << endl;
	    print_result(best, best_l);
	    if (T > 0) cout << endl;
	}
    return 0;
}
