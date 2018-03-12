#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	vector<int> a(n), left(n), right(n);
	for(int i = 0; i < n; ++i) cin >> a[i];
	left[n-1] = n-1;
	for(int i = n-2; i >= 0; --i) {
		if (a[i] <= a[i+1]) left[i] = left[i+1];
		else left[i] = i;
	}
	right[0] = 0;
	for(int i = 1; i < n; ++i) {
		if (a[i] <= a[i-1]) right[i] = right[i-1];
		else right[i] = i; 
	}

	int l, r;
	for(int i = 0; i < m; ++i) {
		cin >> l >> r; --l; --r;
		cout << ((left[l] >= right[r]) ? "Yes" : "No") << endl;
	}

	// for(int i = 0; i < n; ++i) {
	// 	cout << left[i] << endl;
	// }
	// cout << endl;
	// for(int i = 0; i < n; ++i) {
	// 	cout << right[i] << endl;
	// }
	return 0;
}