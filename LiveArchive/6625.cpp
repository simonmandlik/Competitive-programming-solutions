#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < (n); i++)
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define FORD(i, a, b) for (int i = (a); i >= (b); i--)

int c(int i, int j1, int j2, int N, int(*a)[8][8]) {
    if (j1 > j2) return 1;
    int s = 0;
    for(int x = max((*a)[i-1][j1]+1, (*a)[i][j1-1]); x <= N; ++x) {
        (*a)[i][j1] = x;
        s += c(i, j1+1, j2, N, a);
    }
    return s;
}
int solve(int i, int j, int L, int N, int (*l)[8], int (*a)[8][8], int (*below)[8][8]) {
    if (i > L) return 1;
    if ((*below)[i][j] == 0) return c(i, j, (*l)[i], N, a)*solve(i+1, 1, L, N, l, a, below);
    else {
        int s = 0;
        for(int k = max((*a)[i-1][j]+1, (*a)[i][j-1]); k <= N-((*below)[i][j]); ++k) {
            (*a)[i][j] = k;
            s += solve(i+j/(*l)[i], j%(*l)[i] + 1, L, N, l, a, below);
        }
        return s;
    }
}

int main() {
    ios::sync_with_stdio(false);
    int L, N, a[8][8], l[8], below[8][8];
    REP(i, 8) a[0][i] = a[i][0] = 0;
    while(cin >> L) {
        REP(i, L) REP(j, L) a[i+1][j+1] = 0;
        REP(i, L) cin >> l[i+1];
        REP(j, 8) below[L][j] = 0;
        FORD(i, L-1, 1) FOR(j, 1, l[i]+1) 
                if (l[i+1] >= j) below[i][j] = 1 + below[i+1][j];
                else below[i][j] = 0;
        cin >> N;
        cout << solve(1, 1, L, N, &l, &a, &below) << endl;
    }
}