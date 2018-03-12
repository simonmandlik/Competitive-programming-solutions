#include<iostream>
#include <cstdio>
#include <cstring>
#include <climits>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <cassert>
using namespace std;

int main() {
	int n, m;
	cin >> n;
	vector<int> h(n);
	for (int i = 0; i < n; ++i) {
		cin >> h[i];
	}
	cin >> m;
	vector<int> x(m+1);
	for (int i = 0; i < m; ++i) {
		cin >> x[i];
		--x[i];
	}
	x.push_back(INT_MAX);
	sort(x.begin(), x.end());

	long long ans = 0;
	for (int i = 0; i < n; i++) {
		ans += min(h[i], *upper_bound(x.begin(), x.end(), i) - i);
	}
	cout << ans << endl;
	return 0;
}


