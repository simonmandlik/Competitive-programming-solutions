#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    long long even = 0, odd = 0;
    int n; cin >> n;
    long long count[100001];
    for(int i = 0; i < 100001; ++i) count[i] = 0;
    count[0] = 0;
    int m = -1, curr;
    for(int i = 0; i < n; ++i) {
    	cin >> curr;
    	++count[curr];
    	m = max(m, curr);
    }
    long long fn = 0;
   	long long fnn = count[1];
   	long long next;
    for(int i = 2; i <= m; ++i) {
    	next = max(fnn, fn + count[i] * i);
    	fn = fnn;
    	fnn = next;
    }
    cout << next << endl;
    return 0;
}