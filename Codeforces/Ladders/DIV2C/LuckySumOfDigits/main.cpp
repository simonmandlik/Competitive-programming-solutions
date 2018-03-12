#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    int N;
    cin >> N;
    int j;
    for(int i = N/7; i >= 0; --i) {
        if ((N-7*i) % 4 == 0) {
          for(int k = 0; k < (N-7*i) / 4; ++k) cout << 4;
          for(int k = 0; k < i; ++k) cout << 7;
          exit(0);
        }
    }
    cout << -1 << endl;
    return 0;
}