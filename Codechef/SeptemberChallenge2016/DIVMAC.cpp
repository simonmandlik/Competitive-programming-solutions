#include <cstdio>
#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int leastPrimeDivisor(int k) {
    if (k < 4) return k;
    else {
        for (int i = 2; i <= sqrt(k); ++i) {
            if (k % i == 0) return i;
        }
        return k;
    }

}

void fillDivisor(int i, int n, vector<int> &LPD) {
    while (n > 1 && n % 2 == 0) {
        LPD.push_back(2);
        n >>= 1;
    }
    int lpd;
    do {
        lpd = leastPrimeDivisor(n);
        LPD.push_back(lpd);
        n /= lpd;
    } while (lpd != 1);

}

void update(int L, int R, vector<vector<int> > &LPD, vector<int> &index) {
    while (L <= R) {
        if (LPD[L][index[L]] != 1) {
            ++index[L];
        }
        L++;
    }

}

int get(int L, int R, vector<vector<int> > &LPD, vector<int> &index) {
    int maximum = LPD[L][index[L]];
    L++;
    while (L <= R) {
        maximum = max(LPD[L][index[L]], maximum);
        ++L;
    }
    return maximum;
}


int main() {
    int T;
    scanf("%d", &T);
    int N, M;
    int L, R, A;
    int a;
    vector<vector<int> > LPD;
    vector<int> index;
    while (T-- > 0) {
        scanf("%d %d", &N, &M);
        LPD.resize(N);
        index.resize(N);
        for (int i = 0; i < N; ++i) {
            index[i] = 0;
            LPD[i].clear();
            scanf("%d", &a);
            fillDivisor(i, a, LPD[i]);
        }

        while (M-- > 0) {
            scanf("%d %d %d", &A, &L, &R);
            L--; R--;
            if (A == 0) {
                update(L, R, LPD, index);
            } else {
                cout << get(L, R, LPD, index) << " ";
            }
        }
        cout << endl;
    }
    return 0;
}