#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<pair<int, int>> dates(n);
    for(int i = 0; i < n; ++i) {
    	cin >> dates[i].first;
    	cin >> dates[i].second;
    }
    sort(dates.begin(), dates.end());

    int res = 0;
    for(pair<int, int> p : dates) {
    	if (res > p.second) res = p.first;
    	else res = p.second;
    }
    cout << res << endl;
    return 0;
}