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

inline int ones(int n) {
    int res = 0;
    while (n && ++res) n -= n & (-n);
    return res;
}

template<class T>
void chmax(T &a, const T &b) { a = max(a, b); }

template<class T>
void chmin(T &a, const T &b) { a = min(a, b); }


vector<ll> res(5002);

int main() {
    ios::sync_with_stdio(false);
    string N;
    getline(cin, N);
    
    while (N != "0") {
    	int l = N.length();
    	res[l] = 1;
    	res[l - 1] = (N[l - 1] != '0') ? 1 : 0;
    	for (int i = l - 2; i >= 0; --i)
    	{
    		//cout << N[i] << endl;
    		res[i] = 0;
    		//cout << stoi(N.substr(i, 2)) << endl;
    		//DEBUG(i);

    		if (N[i] != '0') {
    			res[i] += res[i + 1];
	    		if (stoi(N.substr(i, 2)) <= 26) {
	    			res[i] += res[i + 2];	
	    		} 
    		} else {
    			res[i] = 0;
    		}
    		//DEBUG(res[i]);
    	}
    	cout << res[0] << endl;
    	getline(cin, N);
    }
    return 0;
}