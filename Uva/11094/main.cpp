#include <bits/stdc++.h>

using namespace std;

#define DEBUG(x) cout << '>' << #x << ':' << x << endl;
#define REP(i, n) for(int i=0;i<(n);i++)
#define FOR(i, a, b) for(int i=(a);i<=(b);i++)
#define FORD(i, a, b) for(int i=(a);i>=(b);i--)

inline bool EQ(double a, double b) { return fabs(a - b) < 1e-9; }

const int INF = 1 << 29;
typedef long long ll;

inline int two(int n) { return 1 << n; }

inline int test(int n, int b) { return (n >> b) & 1; }

inline void set_bit(int &n, int b) { n |= two(b); }

inline void unset_bit(int &n, int b) { n &= ~two(b); }

inline int last_bit(int n) { return n & (-n); }

inline int ones(int n) {
    int res = 0;
    while (n && ++res) n -= n & (-n);
    return res;
}

template<class T>
void chmax(T &a, const T &b) { a = max(a, b); }

template<class T>
void chmin(T &a, const T &b) { a = min(a, b); }


const int VIS = 0;
const int MAXN = 25;

string input[MAXN];
bool vis[MAXN][MAXN];
char land;
int m, n, sum;
int offsetx[] = {0, 1, 0, -1};
int offsety[] = {1, 0, -1, 0};


inline bool inbounds(int y, int x) {
    return !(y < 0 || y >= m || x < 0 || x >= n);
}

void bfs(int y, int x) {
    sum++;
    vis[y][x] = true;
    int ny, nx;
    for (int i = 0; i <= 3; ++i) {
        ny = y + offsety[i];
        nx = x + offsetx[i];
        if (inbounds(ny, nx) && input[ny][nx] == land && !vis[ny][nx])bfs(ny, nx);
    }
    if (x == n - 1 && input[y][0] == land && !vis[y][0])bfs(y, 0);
    else if (x == 0 && input[y][n - 1] == land && !vis[y][n - 1])bfs(y, n - 1);
}

int main() {
    string line;
    int ans, cy, cx;
    while (scanf("%d%d", &m, &n) == 2) {
        getline(cin, line);
        for (int i = 0; i <= m - 1; ++i) {
            getline(cin, input[i]);
        }
        scanf("%d%d", &cy, &cx);
        getline(cin, line);
        land = input[cy][cx];
        memset(vis, VIS, sizeof(vis));
        ans = sum = 0;
        bfs(cy, cx);
        for (int i = 0; i <= m - 1; ++i) {
            for (int j = 0; j <= n - 1; ++j) {
                if (input[i][j] == land && !vis[i][j]) {
                    sum = 0;
                    bfs(i, j);
                    ans = max(sum, ans);
                }
            }
        }
        cout << ans << endl;
        getline(cin, line);
    }
    return 0;
}
//5 5
//wwwww
//wwllw
//wwwww
//wllww
//wwwww
//1 3