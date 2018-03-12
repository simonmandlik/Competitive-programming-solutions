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

int main() {
    ios::sync_with_stdio(false);
    int N, n, threes, sums;
    string s;
    cin >> N;
    set<int> digits;
    int t = 1;
    while (t <= N) {
    	cin >> s;
        threes = 0, sums = 0;
        digits.clear();
        
    	for (int i = 0; i < s.length(); ++i) {
            n = s[i] - '0';
            digits.insert(n);
            sums += n;
    		if (n % 3 == 0) {
                ++threes;
            }
    	}

    	int c = sums % 3;
    	if (c != 0 && (digits.count(c) != 0 || digits.count(c + 3) != 0 || digits.count(c + 6) != 0)) {
    		++threes;
    	}
    	//cout << threes << " " << c << endl;
    	cout << "Case " << t << ": ";
    	cout << ((threes & 1) ? 'S' : 'T') << endl;
    	++t;
    }
    return 0;
}
