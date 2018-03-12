#include <bits/stdc++.h>

using namespace std;

class BinaryIndexedTree {
private:
    long long *data;
    long long N;

public:
    BinaryIndexedTree(long long N): N(N) {
        data = new long long[N + 1];
        memset(data, 0, (N + 1) * sizeof(long long));
        this->N = N + 1;
    }

    BinaryIndexedTree(long long N, long long array[]) {
        for (long long i = 1; i <= N; ++i) {
            add(i, array[i - 1]);
        }
        this->N = N + 1;
    }

    ~BinaryIndexedTree() {
        delete[] data;
    }

    void add(long long i, long long c) {
        while(i <= N) {
            data[i] += c;
            i += (i & -i); // getting up one level until N 1--2--4
        }
    }

    long long sum(long long i) {
        long long r = 0;
        while(i > 0) {
            r += data[i];
            i = i & (i - 1); // getting to zero and cumulating (7->7--6--4--0)
        }
        return r;
    }

    long long query(long long i, long long j) {
        return sum(j) - sum(i);
    }

};

int main() {
    ios::sync_with_stdio(false);
    long long T, N, m, count;
    cin >> T;
    while(T-- > 0) {
        cin >> N;
        long long a[N];
        count = 0;
        m = 0;
        for (long long i = 0; i < N; ++i) {
            cin >> a[i];
            m = max(m, a[i]);
        }
        BinaryIndexedTree t(m);
        for (long long j = N - 1; j >= 0 ; --j) {
            count += t.sum(a[j] - 1);
            t.add(a[j], 1);
        }
        cout << count << '\n';
    }
    cout.flush();
}