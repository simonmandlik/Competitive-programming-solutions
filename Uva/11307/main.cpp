#include <bits/stdc++.h>
using namespace std;

typedef long long ll; // comments that are mixed in with code
typedef pair<int, int> ii; // are aligned to the right like this
typedef vector<ii> vii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;

#define INF 1000000000 // 1 billion, safer than 2B for Floyd Warshall’s
#define DEBUG(x) cout << '>' << #x << ':' << x << endl;
#define REP(i, n) for(int i=0;i<(n);i++)
#define FOR(i, a, b) for(int i=(a);i<=(b);i++)
#define FORD(i, a, b) for(int i=(a);i>=(b);i--)

inline bool EQ(double a, double b) { return fabs(a - b) < 1e-9; }

inline int two(int n) { return 1 << n; }

inline int test(int n, int b) { return (n >> b) & 1; }

inline void set_bit(int &n, int b) { n |= two(b); }

inline void unset_bit(int &n, int b) { n &= ~two(b); }

inline int last_bit(int n) { return n & (-n); }

template<class T>
void chmax(T &a, const T &b) { a = max(a, b); }

template<class T>
void chmin(T &a, const T &b) { a = min(a, b); }

vvi nL;
vvi DP(10005, vector<int>(10));
vector<bool> visited;
int maxD;

void solve(int k, int prev) {
	visited[k] = true;
	for(int ch : nL[k]) {
		if (ch == prev) continue;
		if (!visited[ch]) solve(ch, k);
		for (int i = 0; i < maxD; ++i)
		{
			int s = INF;
			for (int j = 0; j < maxD; ++j)
			{
				if (i != j) {
					s = min(s, DP[ch][j]);
				}
			}
			DP[k][i] += s;
		}
	}
}

int main() {
    ios::sync_with_stdio(false);
    int N;
    cin >> N;
    while (N > 0) {
    	nL.resize(N);
    	nL.clear();
    	visited.resize(N);
    	visited.clear();

    	string ws, n;
    	int v;
    	for (int i = 0; i < N; ++i)
    	{
    		getline(cin >> ws, n);
    		stringstream ss(n);
    		while(ss >> v) {
    			// cout << v << " " << i << endl;
				nL[i].push_back(v);
				nL[v].push_back(i);    			
    		}
    	}
    	if (N == 1) {
    		cout << 1 << endl;
    		cin >> N;
    		continue;
    	}
    	maxD = 0;
    	for (int i = 0; i < N; ++i)
    	{
    		maxD = max(maxD, (int)nL[i].size());
    	}   	
    	maxD = min(10, ++maxD);

		for (int i = 0; i < maxD; ++i)
		{	
			for (int j = 0; j < N; ++j)
			{
				DP[j][i] = i + 1;
			}

		}

    	solve(0, -1);
    	
    	int res = INF;
    	for (int i = 0; i < maxD; ++i)
    	{
    		res = min(res, DP[0][i]);
    	}
    	cout << res << endl;
    	cin >> N;
    }
    return 0;
}