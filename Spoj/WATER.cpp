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

const int MAXN = 101, MAXM = 101;

struct Cuboid {
	int x, y, h;
};

bool operator<(const Cuboid &a, const Cuboid &b) { return a.h >= b.h; }

int main() {
    ios::sync_with_stdio(false);
	int n, m, t, x, y; cin >> t; int h[MAXN][MAXM];
	ll res;
	while(t-- > 0) {
		cin >> n >> m;
		res = 0;
		priority_queue<Cuboid> pq; queue<ii> q;
		vector<vb> vis(n, vb(m, false));
		REP(i, n) REP(j, m) cin >> h[i][j];
		if (n == 1 || m == 1) {
			cout << 0 << endl;
			continue;
		}
		REP(i, n) {
			pq.push({i, 0, h[i][0]}); vis[i][0] = true;
			pq.push({i, m-1, h[i][m-1]}); vis[i][m-1] = true;
		}
		FOR(i, 1, m-1) {
			pq.push({0, i, h[0][i]}); vis[0][i] = true;
			pq.push({n-1, i, h[n-1][i]}); vis[n-1][i] = true;
		}
		while(!pq.empty()) {
			Cuboid c = pq.top(); pq.pop();
			q.push({c.x, c.y});
			while(!q.empty()) {
				x = q.front().first; y = q.front().second; q.pop();
				if (x-1 >= 0) {
					if (!vis[x-1][y]) {
						vis[x-1][y] = true;
						if (h[x-1][y] <= h[c.x][c.y]) {
							res += h[c.x][c.y] - h[x-1][y];
							q.push({x-1, y});
						} else {
							pq.push({x-1, y, h[x-1][y]});
						}
					}
				}
				if (x+1 < n) {
					if (!vis[x+1][y]) {
						vis[x+1][y] = true;
						if (h[x+1][y] <= h[c.x][c.y]) {
							res += h[c.x][c.y] - h[x+1][y];
							q.push({x+1, y});
						} else {
							pq.push({x+1, y, h[x+1][y]});
						}
					}
				}
				if (y-1 >= 0) {
					if (!vis[x][y-1]) {
						vis[x][y-1] = true;
						if (h[x][y-1] <= h[c.x][c.y]) {
							res += h[c.x][c.y] - h[x][y-1];
							q.push({x, y-1});
						} else {
							pq.push({x, y-1, h[x][y-1]});
						}
					}
				}
				if (y+1 < m) {
					if (!vis[x][y+1]) {
						vis[x][y+1] = true;
						if (h[x][y+1] <= h[c.x][c.y]) {
							res += h[c.x][c.y] - h[x][y+1];
							q.push({x, y+1});
						} else {
							pq.push({x, y+1, h[x][y+1]});
						}
					}
				}
			}
		}
		cout << res << endl;
	}
}