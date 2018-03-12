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

struct Edge { int u, v, c;};

bool operator<(Edge e, Edge f) {
	return e.c < f.c;
}

int *r, *parent, *size;

int root(int u) {
	if (parent[u] != u) {
		parent[u] = root(parent[u]);
		return parent[u];
	} else {
		return parent[u];
	}
}

void join(int u, int v) {
	int x = root(u);
	int y = root(v);
	if (x != y) {
		if (r[x] > r[y]) {
			parent[y] = x;
			size[x] += size[y];
		} else if (r[x] < r[y]) {
			parent[x] = y;
			size[y] += size[x];
		} else {
			++r[x];
			size[x] += size[y];
			parent[y] = x;
		}
	}
}

int main() {
    ios::sync_with_stdio(false);
    long long N, S = 0;
    int u, v, c;
    cin >> N;
    r = (int*)malloc(N * sizeof(int));
    parent = (int*)malloc(N * sizeof(int));
    size = (int*)malloc(N * sizeof(int));
    vector<Edge> edges(N-1);
    for(int i = 0; i < N - 1; ++i) {
    	r[0] = 1;
    	parent[i] = i;
    	size[i] = 1;
    	cin >> u >> v >> c; --u; --v;
    	S += c;
    	edges[i] = {u, v, c};
    }

    parent[N-1] = N-1;
	size[N-1] = 1;
	r[N-1] = 1;

	long long T = 0;
	sort(edges.begin(), edges.end());
	for(Edge e : edges) {
		T += e.c * (size[root(e.u)] * size[root(e.v)]);
		join(e.u, e.v);
	}
	cout << fixed << setprecision(11);
	cout << S - ((double)T / ((N * (N - 1)) / 2)); 
	free(r); free(parent); free(size);
    return 0;
}