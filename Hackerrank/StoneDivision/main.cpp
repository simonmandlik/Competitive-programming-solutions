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

unordered_map<ll, ll> grundy;
vi S;

ll compute_grundy(ll n) {
	if (grundy.find(n) != grundy.end()) return grundy[n];
	unordered_map<ll, ll> g;
	for(int s : S) {		
		if (n % s == 0) {
			if(s & 1) {
				g[compute_grundy(n / s)] = 1;
			} else {
				g[0] = 1;
			}
		}
	}
	ll num;
	for (ll i = 0; i < n; ++i)
	{
		if (g.find(i) == g.end()) {
			num = i;
			break;
		}
	}
	//cout << n << ' ' << num << endl;
	return grundy[n] = num;
}

int main() {
    ios::sync_with_stdio(false);
    ll N, s;
    int M;
    cin >> N >> M;
    for(int i = 0; i < M; ++i) {
    	cin >> s;
    	S.push_back(s);
    }

    grundy[1] = 0;    
    cout << (compute_grundy(N) > 0 ? "First" : "Second") << endl; 

    return 0;
}