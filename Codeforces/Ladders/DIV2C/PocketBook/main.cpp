#include <bits/stdc++.h>
using namespace std;

long long MOD = 1000000007;

int main() {
    ios::sync_with_stdio(false);
    int N, M;
    cin >> N >> M;
    vector<string> lines(N);
    for(int i = 0; i < N; ++i) {
    	cin >> lines[i];
    }
    long long res = 1;
    bool used[30];
    long long count;
    for(int letter = M-1; letter >= 0; --letter) {
    	memset(used, false, 30); count = 0;
    	for(int word = 0; word < N; ++word) {
    		if (!used[lines[word][letter] - 'A']) {
    			used[lines[word][letter] - 'A'] = true;
				++count;
    		}
    	}
    	res = (res * count) % MOD;
    }
    cout << res << endl;
    return 0;
}