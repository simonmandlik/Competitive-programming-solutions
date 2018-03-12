#include <bits/stdc++.h>
using namespace std;

#define DEBUG(x) cout << '>' << #x << ':' << x << endl;

int main() {
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    int a[n], count[n];
    long long sum = 0;
    for(int i = 0; i < n; ++i) {
    	cin >> a[i]; sum += a[i];
    }

    if (sum % 3 != 0) {
    	cout << 0 << endl;
    	return 0;
    }

    sum /= 3;
    long long s = a[n-1];
    if (s == sum) {
        count[n-1] = 1;
    } else {
        count[n-1] = 0;
    }

    for(int i = n - 2; i >= 0; --i) {
        s += a[i];
        if (s == sum) {
            count[i] = count[i + 1] + 1;
        } else {
            count[i] = count[i + 1];
        }
    }
    long long res = 0;
    s = 0;
    for (int i = 0; i < n - 2; ++i) {
        s += a[i];
        if (s == sum) {
            res += count[i + 2];
        }
    }
    cout << res << endl;
    return 0;
}