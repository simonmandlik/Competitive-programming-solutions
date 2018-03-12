#include <bits/stdc++.h>
using namespace std;

// a == '.', b == '#'

int main() {
    ios::sync_with_stdio(false);
    int n,m,x,y; cin >> n >> m >> x >> y; y = min(y, m);
    int a[m+1], b[m+1], a_pre[m+1], b_pre[m+1], a_res[m+1], b_res[m+1];
    for(int i = 0; i <= m; ++i) a[i] = b[i] = 0;
    char c;
    for(int i = 0; i < n; ++i) {
    	for(int j = 1; j <= m; ++j) {
    		cin >> c;
    		if (c == '.') {
    			++a[j];
    		} else {
    			++b[j];
    		}
    	}
    }

    a_pre[0] = b_pre[0] = 0;
    for(int i = 1; i <= m; ++i) a_pre[i] = a_pre[i-1] + a[i];
    for(int i = 1; i <= m; ++i) b_pre[i] = b_pre[i-1] + b[i];

    for(int i = 0; i < x; ++i) a_res[i] = b_res[i] = -1;
    for(int i = x; i <= y; ++i) {
    	a_res[i] = a_pre[i];
    	b_res[i] = b_pre[i];
    }
    for(int i = y+1; i <= m; ++i) a_res[i] = b_res[i] = m*n;
    for(int i = x+1; i <= m; ++i) {
    	for(int j = i - y; j <= i - x; ++j) {
    		if (j >= x)
    			a_res[i] = min(a_res[i], b_res[j] + a_pre[i] - a_pre[j]);
    	}
    	for(int j = i - y; j <= i - x; ++j) {
    		if (j >= x)
    			b_res[i] = min(b_res[i], a_res[j] + b_pre[i] - b_pre[j]);
    	}
    }

 //    cout << endl;
 //    for(int i = 0; i <=m ; ++i) cout << a_res[i] << " ";
 //    cout << endl;
	// for(int i = 0; i <=m ; ++i) cout << b_res[i] << " ";
	//     cout << endl;
	// for(int i = 0; i <=m ; ++i) cout << a_pre[i] << " ";
	//     cout << endl;
	// for(int i = 0; i <=m ; ++i) cout << b_pre[i] << " ";
	//     cout << endl;
	// 	for(int i = 0; i <=m ; ++i) cout << a[i] << " ";
	//     cout << endl;
	// for(int i = 0; i <=m ; ++i) cout << b[i] << " ";
	//     cout << endl;

    cout << min(a_res[m], b_res[m]) << endl;    
}