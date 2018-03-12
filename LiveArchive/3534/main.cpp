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
    int n1, n2, s1, s2, i1, i2;
    ll sum;
    vector<int> h1, h2;
    while (true) {
    	cin >> n1;
    	if (n1 == 0) break;
    	h1.resize(n1);
    	for(int i = 0; i < n1; ++i) cin >> h1[i];
    	cin >> n2;
    	h2.resize(n2);
    	for(int i = 0; i < n2; ++i) cin >> h2[i];
		sum = 0;
		s1 = 0, s2 = 0;
		i1 = 0, i2 = 0;
		while(i1 < n1 && i2 < n2) {
			if (h1[i1] == h2[i2]) {
				sum += max(s1, s2);
				sum += h1[i1];
				s1 = s2 = 0;
				++i1; ++i2;
			}
			while(i1 < n1 && h1[i1] < h2[i2]) {s1 += h1[i1]; ++i1;}
			while(i2 < n2 && h1[i1] > h2[i2]) {s2 += h2[i2]; ++i2;}
		}
		while(i1 < n1) {s1 += h1[i1]; ++i1;}
		while(i2 < n2) {s2 += h2[i2]; ++i2;}
		sum += max(s1, s2);
		cout << sum << endl;
    }
    return 0;
}