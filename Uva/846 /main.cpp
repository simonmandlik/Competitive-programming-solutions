#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    int x, y;
    while(T-- > 0) {
        cin >> x >> y;
        long long sol = 0, diff = y - x, l = 0, size = 2;
        while(l < diff) {
            l += (size / 2);
            ++sol;
            ++size;
        }
        cout << sol << endl;
    }
    return 0;
}