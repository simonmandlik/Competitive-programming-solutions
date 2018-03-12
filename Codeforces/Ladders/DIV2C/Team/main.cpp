#include <bits/stdc++.h>
using namespace std;

void solve(int n, int m) {
	if (n == 0 && m == 0) return;
	if (n > m) {
		cout << '0';
		for(int i = 0; i < m; ++i) cout << "10";
	} else {
		while(m > n) {
			cout << '1';
			--m;
			if (m > 0) {
				cout << '1'; --m;
			}
			if (n > 0) {
				cout << '0'; --n;
			}
		}
		while(m == n && m > 0 && n > 0) {
			cout << "10";
			--m; --n;
		}
	}
}
int main() {
    ios::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    if (n > m + 1 || 2 * (n+1) < m)  {
    	cout << -1 << endl;
    } else {
    	solve(n, m);
    	cout << endl;
    }
    return 0;
}