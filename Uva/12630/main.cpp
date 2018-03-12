#include <bits/stdc++.h>

using namespace std;

int main() {
    unsigned long long n, m, sum;
    cin >> n;
    while (n > 0) {
        sum = 0;
        for(int k = 2; k <= n; ++k) {
            sum += (k - 1) * (n - k + 1) * (n - k + 2) / 2;
        }
        cout << sum << endl;
        cin >> n;
    }
    return 0;
}