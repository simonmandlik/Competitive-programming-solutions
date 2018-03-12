#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    unsigned long long n, m, s;
    unsigned long long sum, t;
    cin >> n >> m;
    while(n > 0) {
        ++m; ++n;
        sum = 0;
        s = min(m, n);
        for (int k = 2; k <= s; k += 2) {
            t = (k - 1) * (n - k + 1) * (m - k + 1);
            sum += t;
        }
        cout << sum << endl;
        cin >> n >> m;
    }
    return 0;
}