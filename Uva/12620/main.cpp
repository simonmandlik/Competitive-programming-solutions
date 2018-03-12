#include <bits/stdc++.h>

using namespace std;


const long MAX = 1000;

int main() {
    ios::sync_with_stdio(false);
    int x = 1, y = 1, z, len;
    vector<long long> f(MAX);
    f[0] = 0;
    f[1] = 1;
    f[2] = 2;
    for (int i = 3; i < MAX; ++i) {
        if (x == y && x == 1 && i != 3) {
            len = i - 3;
            break;
        }
        z = (x + y) % 100;
        f[i] = z + f[i - 1];
        x = y;
        y = z;
    }

    long long T, i, j;
    cin >> T;
    long long res;
    while (T-- > 0) {
        cin >> i >> j; --i;
        if (i == j) res = j/len * f[len] + f[j % len];
        else res = j/len * f[len] + f[j % len] - (i/len * f[len] + f[i % len]);
        cout << res << endl;
    }

    return 0;
}