#include <bits/stdc++.h>
using namespace std;

#define DEBUG(x) cout << '>' << #x << ':' << x << endl;
#define REP(i, n) for(int i=0;i<(n);i++)
#define FOR(i, a, b) for(int i=(a);i<=(b);i++)
#define FORD(i, a, b) for(int i=(a);i>=(b);i--)

inline bool EQ(double a, double b) { return fabs(a - b) < 1e-9; }

const int INF = 1 << 29;
typedef long long ll;

inline int two(int n) { return 1 << n; }

inline int test(int n, int b) { return (n >> b) & 1; }

inline void set_bit(int &n, int b) { n |= two(b); }

inline void unset_bit(int &n, int b) { n &= ~two(b); }

inline int last_bit(int n) { return n & (-n); }

inline int ones(int n) {
    int res = 0;
    while (n && ++res) n -= n & (-n);
    return res;
}

template<class T>
void chmax(T &a, const T &b) { a = max(a, b); }

template<class T>
void chmin(T &a, const T &b) { a = min(a, b); }

int *leftBr;
int *rightBr;

int leaves;
void update(int l, int bracket) {
	int index = leaves + l;
	if (bracket == -1) {
        leftBr[index] = 1;
        rightBr[index] = 0;
    } else {
        leftBr[index] = 0;
        rightBr[index] = 1;    
    }
	
	index /= 2;
	int lChild, rChild;
	while(index > 0) {
		lChild = index * 2;
		rChild = index * 2 + 1;
		int closed = min(leftBr[lChild], rightBr[rChild]);
        leftBr[index] = leftBr[lChild] + leftBr[rChild] - closed;
        rightBr[index] = rightBr[lChild] + rightBr[rChild] - closed;
		index /= 2;
	}
}


int main() {
    ios::sync_with_stdio(false);
    int T = 10, N, Q, q, bracket;
    char br;
    while (T-- > 0) {
    	cin >> N;
    	leaves = 1;
    	while (leaves < N + 2) leaves *= 2;
    	leftBr = new int[2 * leaves];
    	rightBr = new int[2 * leaves];
        for (int i = 0; i < 2 * leaves; ++i) {
            rightBr[i] = leftBr[i] = 0;
        }
    	for (int i = 1; i <= N; ++i) {
    		cin >> br;
    		bracket = (br == '(') ? -1 : 1;
    		update(i, bracket);
    	}

        cout << "Test " << 10 - T << ':' << endl;
    	cin >> Q;
    	for (int i = 0; i < Q; ++i) {
    		cin >> q;
    		if (q == 0) cout << ((leftBr[1] == 0 && rightBr[1] == 0) ? "YES" : "NO") << endl;
    		else {
    			update(q, (leftBr[leaves + q] == 1) ? 1 : -1);
    		}
    	}
    	delete[] leftBr;
    	delete[] rightBr;
    }
    return 0;
}