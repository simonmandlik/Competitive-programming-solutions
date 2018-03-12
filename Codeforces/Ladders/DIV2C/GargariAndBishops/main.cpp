#include <bits/stdc++.h>
using namespace std;


const int right_down = 0, left_down = 1, right_up = 2, left_up = 3, value = 4;

int main() {
    ios::sync_with_stdio(false);
 	int N;
 	cin >> N;
 	long long dp[N+2][N+2][5];
 	memset(dp, 0, sizeof(dp));
 	for(int j = 0; j <= N+1; ++j) {
 		dp[0][j][left_down] = dp[0][j][right_down] = 0;
 		dp[N+1][j][left_up] = dp[N+1][j][right_up] = 0;
 	}
 	for(int i = 0; i <= N+1; ++i) {
 		dp[i][0][right_down] = dp[i][0][right_up] = 0;
 		dp[i][N+1][left_down] = dp[i][N+1][left_up] = 0;
 	}
 	for(int i = 1; i <= N; ++i) {
 		for(int j = 1; j <= N; ++j) {
 			cin >> dp[i][j][value];
 		}
 	}

 	// solve
 	for(int i = 1; i <= N; ++i) {
 		for(int j = 1; j <= N; ++j) {
 			dp[i][j][right_down] = dp[i-1][j-1][right_down] + dp[i][j][value];
 			dp[i][j][left_down] = dp[i-1][j+1][left_down] + dp[i][j][value];
 		}
 	}
 	for(int i = N; i >= 1; --i) {
 		for(int j = N; j >= 1; --j) {
 			dp[i][j][right_up] = dp[i+1][j-1][right_up] + dp[i][j][value];
 			dp[i][j][left_up] = dp[i+1][j+1][left_up] + dp[i][j][value];
 		}
 	}
 	long long best1 = -1, best2 = -1, v;
 	int x1, y1, x2, y2;
	for(int i = 1; i <= N; ++i) {
 		for(int j = 2 -(i&1); j <= N; j += 2) {
 			v = dp[i][j][right_down] + dp[i][j][right_up] + dp[i][j][left_down] + dp[i][j][left_up] - 3 * dp[i][j][value];
 			if(v > best1) {
 				best1 = v;
 				x1 = i, y1 = j;
 			}
 		}
 	}
	for(int i = 1; i <= N; ++i) {
 		for(int j = 1 + (i&1); j <= N; j += 2) {
 			v = dp[i][j][right_down] + dp[i][j][right_up] + dp[i][j][left_down] + dp[i][j][left_up] - 3 * dp[i][j][value];
 			if(v > best2) {
 				best2 = v;
 				x2 = i, y2 = j;
 			}
 		}
 	}
 	cout << best1 + best2 << endl << x1 << " " << y1 << " " << x2 << " " << y2 << endl;

 	// for(int k = 0; k < 5; ++k){
 	// for(int i = 0; i <= N+1; ++i) {
 	// 	for(int j = 0; j <= N+1; ++j) {
 	// 		 cout << dp[i][j][k] << " ";
 	// 	}
 	// 	cout << endl;
 	// } cout << endl << endl;}
    return 0;
}