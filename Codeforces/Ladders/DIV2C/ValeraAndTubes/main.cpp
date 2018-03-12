#include <bits/stdc++.h>
using namespace std;

#define DEBUG(x) cout << '>' << #x << ':' << x << endl;

int main() {
    ios::sync_with_stdio(false);
    int n, m, k;
    cin >> n >> m >> k;
	vector<pair<int, int>> points;

	int i = 1;
	for(int k = 0; k < n / 2; ++k) {
		for(int j = 1; j <= m; ++j) points.push_back({i, j});
		++i;
		for(int j = m; j > 0; --j) points.push_back({i, j});
		++i;
	}    
	if (n & 1) {
		for(int j = 1; j <= m; ++j) points.push_back({n, j});
	}
	
	int l = 3; int count = 0;
	for(pair<int, int> point : points) {
		if (l >= 2 && k > 0) {
			if (l == 2) cout << endl;
			--k; l = 0;
			if (k > 0) cout << 2;
			else cout << n*m - count;
		}
		cout << " " << point.first << " " << point.second;
		++l;
		++count;
	}
    return 0;
}