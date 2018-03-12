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



int main() {
    int T, M, N;
    cin >> T;
    int wall[9][9];
    while (T-- > 0) {
        for(int i = 0; i < 9; i += 2) {
            for (int j = 0; j <= i; j += 2) {
                cin >> wall[i][j];
            }
        }
        for(int i = 6; i >= 0; i -= 2) {
            for(int j = 0; j <= i; j += 2) {
                wall[i + 2][j + 1] = (wall[i][j] - wall[i + 2][j] - wall[i + 2][j + 2]) / 2;
                wall[i + 1][j] = wall[i + 2][j] + wall[i + 2][j + 1];
                wall[i + 1][j+1] = wall[i + 2][j+1] + wall[i + 2][j + 2];

            }
        }
        for (int k = 0; k < 9; ++k) {
            cout << wall[k][0];
            for (int i = 1; i <= k; ++i) {
                cout << " " << wall[k][i];
            }
            cout << endl;
        }

    }
    return 0;
}