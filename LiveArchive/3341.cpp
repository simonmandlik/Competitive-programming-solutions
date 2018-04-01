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
	int t, d, a, b, n; cin >> t; string line;
	getline(cin, line);
	while(t-- > 0) {
		getline(cin, line);
		stringstream ss(line);
		vi dig;
		while(ss >> d) dig.push_back(d);
		n = dig.size();
		a = b = 0;
		if (n == 2) {
			a = dig[1]; b = dig[0];
		} else if (n % 2 == 1) {
			if (dig[0] == 0) a = 10*dig[1];
			else a = 10*dig[0] + dig[1];
			for(int i = 2; i <= n/2; ++i) {
				a *= 10;
				a += dig[i];
			}
			for(int i = n-1; i > n/2; --i) {
				b *= 10;
				b += dig[i];
			}
		} else {
			int bd = 10, c, d; double dist = 1000;
			for(int i = (dig[0] == 0 ? 1 : 0); i+1 < n; ++i) {
				// cout << "i " << i << endl;
				if (dig[i+1] - dig[i] < bd || dig[i+1] - dig[i] == bd && abs((2.0*i+1)/2.0 - (double)(n-1)/2.0) < dist) {
					bd = dig[i+1] - dig[i];
					c = dig[i];
					d = dig[i+1];
					dist= abs((2.0*i+1)/2.0 - (double)(n-1)/2.0);
				}
			}
			a *= 10; a += d;
			b *= 10; b += c;
			int count = 0;
			int i = 0;
			for(; count < n/2 - 1; ++i) {
				if (dig[i] != c && dig[i] != d) {
					a*=10; a+=dig[i];
					count++;
				}
			}
			for(int k = n-1; k >= i; --k) {
				if (dig[k] != c && dig[k] != d) {
					b*=10; b+=dig[k];
				}
			}
		}
		cout << a-b << endl;
	}
}