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
	int k; cin >> k; string s; cin >> s;
	vll gaps;
	int l = -1;
	for(int i = 0; i < s.length(); ++i) {
		if (s[i] == '1') {
			gaps.push_back(i - l - 1);
			l = i;
		}
	}
	gaps.push_back(s.length() - l - 1);
	ll res = 0;
	if (k == 0) {
		for(int i = 0; i < gaps.size(); ++i) {
			if (gaps[i] > 0) res += (gaps[i]*(gaps[i]+1))/2;
		}
	} else {	
		for(int i = k; i < gaps.size(); ++i) {
			res += (gaps[i]+1)*(gaps[i-k]+1);
		}
	}
	cout << res << endl;

}