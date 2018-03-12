#include <bits/stdc++.h>

using namespace std;

const string p1 = "John";
const string p2 = "Brother";

int main() {
    ios::sync_with_stdio(false);
    int T, h;
    cin >> T;
    int res, next;
    bool ones;
    while (T-- > 0) {
        cin >> h;
        cin >> res;
        ones = res == 1;
        for (int i = 1; i < h; ++i) {
            cin >> next;
            if (next != 1) ones = false;
            res ^= next;

        }
        if (h == 1) {
            if (res == 1) cout << p2 << endl;
            else cout << p1 << endl;
            continue;
        }
//        cout << res;
        if (ones) {
            if (h & 1) cout << p2 << endl;
            else cout << p1 << endl;

            continue;
        }
        if (res == 0) cout << p2 << endl;
        else cout << p1 << endl;
    }
    return 0;
}