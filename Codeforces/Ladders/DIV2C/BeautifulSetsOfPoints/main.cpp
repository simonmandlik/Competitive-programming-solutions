#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    int M, N, k;
    cin >> M >> N;
    k = min(M, N);
    cout << (k+1) << endl;
    for(int i = 0; i <= k; ++i) {
        cout << i << ' ' << k - i << endl;
    }
    return 0;
}