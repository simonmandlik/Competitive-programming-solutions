#include <bits/stdc++.h>
#pragma GCC optimize ("Ofast")
using namespace std;
#define EPS (1e-10)
#define DBG(x) cout << "> " << #x << ": " << x << endl;
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
typedef vector<string> vs;
typedef vector<vector<int>> vvi;
typedef vector<ii> vii;
////////////////////////////////////////////////////////////////////////////////

constexpr int X = 0;
constexpr int x = 1;
constexpr int F = 2;
constexpr int T = 3;

bool op(char ch) {
    return ch == '^' || ch == '|' || ch == '&';
}

int solve(string &s, int i, int j) {
    // cout << i << " " << j << endl;
    if (j - i == 1) {
        if (s[i] == 'X') return X;
        if (s[i] == 'x') return x;
        if (s[i] == '0') return F;
        if (s[i] == '1') return T;
    } else {
        int from = i+1, to;
        int b = 0;
        for(to = from; b != 0 || !op(s[to]); ++to) {
            if (s[to] == '(') ++b;
            if (s[to] == ')') --b;
        }
        char o = s[to];
        int resA = solve(s, from, to);
        from = to+1;
        to = j - 1;
        int resB = solve(s, from, to);
        if (o == '&') {
            if (resA == F || resB == F) return F;
            if (resA == T) return resB;
            if (resB == T) return resA;
            if (resA == resB) return resA;
            return F;
        } else if (o == '|') {
            if (resA == T || resB == T) return T;
            if (resA == F) return resB;
            if (resB == F) return resA;
            if (resA == resB) return resA;
            return T;
        } else {
            if (resA == resB) return F;
            if (resA == T && resB == F) return T;
            if (resA == F && resB == T) return T;
            if (resA == X && resB == x) return T;
            if (resA == x && resB == X) return T;
            if (resA == F) return resB;
            if (resB == F) return resA;
            if (resA == T) return 1-resB;
            if (resB == T) return 1-resA;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    int Ts; cin >> Ts;
    string s;
    getline(cin, s);
    for(int t = 1; t <= Ts; ++t) {
        getline(cin, s);
        int res = solve(s, 0, s.length());
        cout << "Case #" << t << ": ";
        cout << ((res == F || res == T) ? 0 : 1) << endl;
    }
}
