#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    while(N > 0) {
        if(N == 2 || N % 2 == 1) {
            cout << "Impossible" << endl;
            cin >> N;
            continue;
        }
        cout << (N * 3) / 2 << endl;
        for (int i = 1; i < N; ++i) {
            cout << to_string(i) + " " + to_string((i + 1)) << endl;
            if (i <= N / 2) {
                cout << to_string(i) + " " + to_string(i + N/2) << endl;
            }
        }
        cout << N << " " << 1 << endl;

        cin >> N;
    }
    return 0;
}