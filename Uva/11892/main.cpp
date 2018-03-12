#include <bits/stdc++.h>
using namespace std;

const string p1 = "poopi";
const string p2 = "piloop";

int main() {
    ios::sync_with_stdio(false);
    int T, h, l;
    cin >> T;
    bool w;
    while(T-- > 0) {
        w = false;
        cin >> h;
        for (int i = 0; i < h; ++i) {
            cin >> l;
            if (l > 1) w = true;
        }
        if (w || h & 1) cout << p1;
        else cout << p2;
        cout << endl;

    }
    return 0;
}