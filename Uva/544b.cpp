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

const int MAXW = 10000;

struct Edge {
	int u, v, w;
};

bool operator<(Edge &a, Edge &b)  { return a.w > b.w; }

int root(int u, vi &parents) {
	if (parents[u] == -1) return u;
	else return parents[u] = root(parents[u], parents);
}

bool same(int u, int v, vi &parents) {
	return root(u, parents) == root(v, parents);
}

void join(int u, int v, vi &ranks, vi &parents) {
	u = root(u, parents); v = root(v, parents);
	if (u == v) return; // already in the same set
	if (ranks[u] > ranks[v]) {
		parents[v] = u;
	} else if (ranks[u] < ranks[v]) {
		parents[u] = v;
	} else {
		parents[u] = v;
		ranks[u]++;
	}
}

int main() {
    ios::sync_with_stdio(false);
    int n, m, c, w, s, d, t=1;
    unordered_map<string, int> hash;
    string a, b;
    while (cin >> n >> m) {
    	if (n == 0 && m == 0) continue;
    	vector<Edge> edges(m);
    	vi ranks(n, 1), parents(n, -1);
    	hash.clear();
    	c = 0;
    	REP(i, m) {
    		cin >> a >> b >> w;
    		if (hash.find(a) == hash.end()) hash[a] = c++;
    		if (hash.find(b) == hash.end()) hash[b] = c++;
    		edges[i].u = hash[a]; edges[i].v = hash[b]; edges[i].w = w;
    	}
    	cin >> a >> b;
    	s = hash[a]; d = hash[b];
    	sort(edges.begin(), edges.end());
    	int res = MAXW;
    	for(Edge &e : edges) {
    		if (same(s, d, parents)) break;
    		res = e.w;
    		join(e.u, e.v, ranks, parents);
    	}

    	cout << "Scenario #" << t++ << endl << res << " tons" << endl << endl;
    }	
}