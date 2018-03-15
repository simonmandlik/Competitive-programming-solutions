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
	int u, w;
};

bool legible(int s, int d, int w, vector<vector<Edge>> &graph) {
	stack<int> q; vb visited(graph.size(), false);
	q.push(s);
	visited[s] = true;
	while(!q.empty()) {
		int u = q.top(); q.pop();
		if (u == d) return true;
		for(Edge &e : graph[u]) {
			if(!visited[e.u] && e.w >= w)  {
				visited[e.u] = true;
				q.push(e.u);
			}
		}
	}
	return false;
}

int bin_search(int s, int d, vector<vector<Edge>> &graph) {
	int a = 0, b = MAXW;
	int res = 0;
	while(a <= b) {
		int mid = (a+b)/2;
		if (legible(s, d, mid, graph)) {
			res = max(res, mid);
			a = mid+1;
		}
		else {
			b = mid-1;
		}
	}
	return res;
}

int main() {
    ios::sync_with_stdio(false);
    int n, m, c, w, t=1;
    unordered_map<string, int> hash;
    string a, b;
    while (cin >> n >> m) {
    	if (n == 0 && m == 0) continue;
   		vector<vector<Edge>> graph(n, vector<Edge>());
    	hash.clear();
    	c = 0;
    	REP(i, m) {
    		cin >> a >> b >> w;
    		if (hash.find(a) == hash.end()) hash[a] = c++;
    		if (hash.find(b) == hash.end()) hash[b] = c++;
    		graph[hash[a]].push_back({hash[b], w});
    		graph[hash[b]].push_back({hash[a], w});
    	}
    	cin >> a >> b;
    	cout << "Scenario #" << t++ << endl;
    	cout << bin_search(hash[a], hash[b], graph) << " tons" << endl << endl;
    }	
}