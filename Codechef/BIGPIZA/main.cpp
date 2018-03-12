#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e4;

int main() {
    ios::sync_with_stdio(false);
    int xors[MAXN + 1];
    int grundy[MAXN + 1];
    int g;

    grundy[0] = grundy[1] = 0;
    for (int i = 2; i <= MAXN ; ++i) {
        memset(xors, 0, sizeof(xors));
        for(int j = 0; j <= (i - 2) / 2; ++j) {
            xors[grundy[j] ^ grundy[i - j - 2]] = 1;
        }
        g = 0;
        for(; xors[g]; ++g);
        grundy[i] = g;
    }

    int T, N;
    cin >> T;
    while(T-- > 0) {
        cin >> N;
        cout << (grundy[N] > 0 ? "Arjuna" : "Bhima") << endl;
    }
    return 0;
}