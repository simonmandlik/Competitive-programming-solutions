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

int main() {
    ios::sync_with_stdio(false);
    int T, K, k, n, a, b; cin >> T; string s;
    while(T-- > 0) {
    	cin >> s >> K;
    	n = s.length();
    	int res = 1;
    	for(int i = 0; i < n-1; ++i) {
    		a = i; b = i + 1;
    		k = K;
    		while(a >= 0 && b < n) {
    			if (s[a] != s[b]) {
    				if (k == 0) break;
    				--k;
    			}
    			res = max(res, b-a+1);
    			--a; ++b;
    		}
    	}
    	for(int i = 1; i < n-1; ++i) {
    		a = i - 1; b = i + 1;
    		k = K;
    		while(a >= 0 && b < n) {
    			if (s[a] != s[b]) {
    				if (k == 0)	break;
    				--k;
    			}
    			res = max(res, b-a+1);
    			--a; ++b;
    		}
    	}
    	cout << res << endl;
    }
	
}