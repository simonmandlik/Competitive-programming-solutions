#include <cstdio>
#include <iostream>
#include <cmath>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

class IntervalTree {
private:
    int *tree;
    int leaves;
public:
    IntervalTree(int n, vector<int> values) {
        leaves = 1;
        while(leaves < n + 2) leaves <<=1 ;
//        cout << leaves << endl;
        tree = new int[2 * leaves];
        for (int j = 0; j < 2 * leaves; ++j) {
            tree[j] = 0;
        }
        for (int i = 0; i < n; ++i) {
            change(i, values[i]);
        }

    }

    void change(int i, int n) {
//        cout << n << endl;
        int k = leaves + i + 1;
        tree[k] = n;
        k /= 2;
        while (k > 0) {
//            cout << k << endl;
//            cout << k <<  tree[2 * k] << tree[2 * k + 1] << endl;
            tree[k] = max(tree[2 * k], tree[2 * k + 1]);
            k /= 2;
        }
//        for (int j = 0; j < 2 * leaves; ++j) {
//            cout << tree[j] << " ";
//        }
//        cout << endl;
    }

    int query(int L, int R) {
        int ret = 1;
        int l = leaves + L - 1;
        int r = leaves + R + 1;
        while (l != r) {
            if (l % 2 == 0) ret = max(ret, tree[l + 1]);
            if (r % 2 == 1) ret = max(ret, tree[r - 1]);
            l /= 2; r /= 2;
        }
        return ret;
    }

    ~IntervalTree() {
        delete[] tree;
    }
};

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

void update(int L, int R, vector<int> &LPD, vector<int> &index, IntervalTree *t) {
    while (L <= R) {
        if (LPD[L] != 1) {
            index[L] /= LPD[L];
	        LPD[L] = leastPrimeDivisor(index[L]);
            t->change(L, LPD[L]);
        }
        L++;
    }

}

int get(int L, int R, vector<int> &LPD) {
    int maximum = LPD[L];
    L++;
    while (L <= R) {
        maximum = max(LPD[L], maximum);
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
    vector<int> LPD;
    vector<int> index;
    IntervalTree *t;
    while (T-- > 0) {
        scanf("%d %d", &N, &M);
        LPD.resize(N);
        index.resize(N);
        for (int i = 0; i < N; ++i) {
            //index[i] = 0;
            scanf("%d", &index[i]);
		    LPD[i] = leastPrimeDivisor(index[i]);
           // fillDivisor(i, a, LPD[i]);

        }
//        for (int j = 0; j < LPD.size(); ++j) {
//            cout << LPD[j] << " ";
//        }
//        cout << endl;
        t = new IntervalTree(N, LPD);
        while (M-- > 0) {
            scanf("%d %d %d", &A, &L, &R);
            L--; R--;
            if (A == 0) {
                update(L, R, LPD, index, t);
            } else {
//                cout << get(L, R, LPD) << " ";
                cout << t->query(L, R) << " ";
            }
        }
        cout << endl;
        delete t;
    }
    return 0;
}
