#include <bits/stdc++.h>

using namespace std;
int main() {
    ios::sync_with_stdio(false);
    int N;
    cin >> N;
    if (N % 10 == 0) cout << 2 << endl;
    else {
        cout << 1 << '\n' << N % 10 << endl;
    }
    return 0;
}