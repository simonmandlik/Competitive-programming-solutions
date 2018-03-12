#include <bits/stdc++.h>
using namespace std;

long long MOD = 1000000007;

int main() {
    ios::sync_with_stdio(false);
    int N, K, d;
    cin >> N >> K >> d;
    long long notD[N+1], D[N+1];
    notD[0] = 1; D[0] = (d == 0) ? 1 : 0;
    for(int i = 1; i <= N; ++i)  {
    	notD[i] = D[i] = 0;
    	for(int k = 1; k < d; ++k) {
    		if(i-k >= 0) {
    			notD[i] = (notD[i] + notD[i - k]) % MOD;
    			D[i] = (D[i] + D[i - k]) % MOD;
    		}
    	}
    	for(int k = d; k <= K; ++k) {
    		if(i-k >= 0) {
    			D[i] = (D[i] + notD[i - k]) % MOD;
    			D[i] = (D[i] + D[i - k]) % MOD;
    		}
    	}
    }
    cout << D[N] << endl;
    return 0;
}