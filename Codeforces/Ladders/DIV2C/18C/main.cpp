#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    int N; cin >> N;
    int prefix[N+1], suffix[N+1];
    int sum = 0, a;
    prefix[0] = 0;
    for(int i = 1; i <= N; ++i) {
    	cin >> a; sum += a;
    	prefix[i] = a + prefix[i-1];
    }
    suffix[N] = 0;
    for(int i = N-1; i >= 0; --i) {
    	suffix[i] = sum - prefix[i];
    }

    int count = 0;
    for(int i = 1; i < N; ++i) {
    	if (prefix[i] == suffix[i]) ++count;
    }
    cout << count << endl;
    return 0;
}