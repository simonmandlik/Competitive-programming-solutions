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
typedef pair<double, double> pdd;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<double> vd;
typedef vector<bool> vb;
typedef vector<vector<int>> vvi;
typedef vector<ii> vii;

long double solve(int n, int m, int N, int M, vector<vector<long double>> &dp) {
    if (m == 0) return 1;
    if (n == 0) return 0;
    if (dp[n][m] == -1) {
        dp[n][m] = solve(n-1, m-1, N, M, dp) * (((long double)m)/M) + solve(n-1, m, N, M, dp) * (((long double)(M-m)) / M);
    }
    return dp[n][m];
}

int main() {
    ios::sync_with_stdio(false);
    int n, m, t=1;
    while(cin >> n && n != -1) {
        cin >> m;
        vector<vector<long double>> dp(n+1, vector<long double>(m+1, -1));
        cout << fixed << setprecision(7) << "Case " << t++ << ": ";
        cout << 1 - solve(n, m, n, m, dp) << endl;
    }
}