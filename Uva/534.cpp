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
    cout << fixed << setprecision(3);
	int t=1, n, u, v; double d;
	while(cin >> n) {
		if (n == 0) continue;
		vector<dd> points(n);
		vd dist(n, DBL_MAX);
		vb visited(n, false);
		REP(i, n) cin >> points[i].first >> points[i].second;

		set<pair<double, int>> q;
		q.insert({0.0, 0});
		dist[0] = 0.0;
		while(!q.empty()) {
			u = q.begin()->second;
			q.erase(q.begin());
			visited[u] = true;
			if (u == 1) break;
			for(v = 0; v < n; ++v) {
				if (u == v) continue;
				d = max(dist[u], pow(points[u].first - points[v].first, 2) + pow(points[u].second - points[v].second, 2));
				if (!visited[v] && d < dist[v]) {
					q.erase({dist[v], v});
					dist[v] = d;
					q.insert({dist[v], v});
				}
			}
		}
		cout << "Scenario #" << t++ << endl << "Frog Distance = " << sqrt(dist[1]) << endl << endl;
	}
}