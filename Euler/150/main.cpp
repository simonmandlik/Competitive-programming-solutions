#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N, K;
    cin >> N; cin >> K;

    int ***max = new int **[N];
    int l;
    vector<int> res;

    for (int i = N - 1; i >= 0; --i) {
        max[i] = new int *[N - i];
        for (int j = 0; j < N - i; ++j) {
            max[i][j] = new int[i + 1];
            cin >> l;
            res.push_back(l);
            max[i][j][0] = l;
        }
    }

    for (int j = 0; j < N - 1; ++j) {
        l = max[1][j][1] = max[0][j][0] + max[0][j + 1][0] + max[1][j][0];
        res.push_back(l);
    }

    for (int i = 2; i < N; ++i) {
        for (int j = 0; j < N - i; ++j) {
            l = max[i][j][1] = max[i][j][0] + max[i - 1][j + 1][0] + max[i - 1][j][0];
            res.push_back(l);
            for (int k = 2; k <= i; ++k) {
                max[i][j][k] = l =  max[i - 1][j][k - 1] +
                                    max[i - 1][j + 1][k - 1] -
                                    max[i - 2][j + 1][k - 2] +
                                    max[i][j][0];
                res.push_back(l);
            }
            delete[] max[i - 2][j];
        }
        delete[] max[i - 2][N - i];
        delete[] max[i - 2][N - i + 1];
        delete[] max[i - 2];
    }

    int l_b = (N - 2) >= 0 ? N - 2 : 0;
    for (int i = N - 1; i >= l_b; --i) {
        for (int j = 0; j < N - i; ++j) {
            delete[] max[i][j];
        }
        delete[] max[i];
    }

    sort(res.begin(), res.end());
    for (int k = 0; k < K; ++k) {
        cout << res[k] << endl;
    }
    delete[] max;
    return 0;
}