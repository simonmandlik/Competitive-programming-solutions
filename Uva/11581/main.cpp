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

int grow(vector<vector<int>> &board, vector<vector<int>> &boardAux) {
    int sum = 0;
    int p = 0;
    for (int i = 1; i <= 3; ++i) {
        for (int j = 1; j <= 3; ++j) {
            boardAux[i][j] = 0;
            boardAux[i][j] ^= board[i - 1][j];
            boardAux[i][j] ^= board[i][j - 1];
            boardAux[i][j] ^= board[i + 1][j];
            boardAux[i][j] ^= board[i][j + 1];
            sum += boardAux[i][j] * pow(2, p++);
        }
    }
    for (int i = 1; i <= 3; ++i) {
        for (int j = 1; j <= 3; ++j) {
            board[i][j] = boardAux[i][j];
        }
    }

    return sum;
}

int main() {
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    char ch;
    vector<vector<int>> board(5, vector<int>(5, 0));
    vector<vector<int>> boardAux(5, vector<int>(5, 0));
    while (T-- > 0) {
        vector<int> DP(pow(2, 9), -1);
        for (int i = 1; i <= 3; ++i) {
            for (int j = 1; j <= 3; ++j) {
                cin >> ch;
                board[i][j] = (ch == '0') ? 0 : 1;
            }
        }
        int r = 0, s;
        int p = 0;
        for (int i = 1; i <= 3; ++i) {
            for (int j = 1; j <= 3; ++j) {
                r += board[i][j] * pow(2, p++);
            }
        }
        if (r == 0) {
            cout << -1 << endl;
            continue;
        }
        s = grow(board, boardAux);
        int it = 1;
        while (s != 0) {
            s = grow(board, boardAux);
            ++it;
        }
        cout << it - 1 << endl;
    }
    return 0;
}

//3
//111
//100
//001
//101
//000
//101
//000
//000
//000