#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    int N, K; cin >> N >> K;
    vector<long long> arr(N+1), prefix(N+1);
    for(int i = 1; i <= N; ++i) cin >> arr[i];
    sort(arr.begin() + 1, arr.end());
    prefix[0] = 0;
    for(int i = 1; i <= N; ++i) prefix[i] = prefix[i-1] + arr[i];
    int best = -1, best_value = -1;
    int a, b, m, s;
    for(int r = 1; r <= N; ++r) {
    	a = 0; b = r; s = r;
    	while(a <= b) {
    		m = (a+b)/2;
    		if (arr[r]*(r-m+1) - (prefix[r] - prefix[m-1]) <= K) {
    			s = min(s, m);
    			b = m-1;
    		} else {
    			a = m+1;
    		}
    	}
    	if (r-s+1 > best) {
    		best = r-s+1;
    		best_value = arr[r];
    	} 
    }
    cout << best << " " << best_value << endl;

    return 0;
}