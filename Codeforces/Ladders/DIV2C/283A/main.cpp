#include <bits/stdc++.h>
using namespace std;

int main() {
    int N; cin >> N;
    vector<int> increments(200001, 0), A(200001, 0);
    int t, i = 0;
    long a, k;
    double sum = 0;
    while(N-- > 0) {
    	scanf("%d", &t);
    	if (t == 1) {
			scanf("%ld %ld\n", &a, &k);
			increments[a-1] += k;
			sum += k*a;
    	} else if (t == 2) {
			scanf("%ld\n", &k);
			A[++i] = k;
			sum += k;
		} else {
			increments[i-1] += increments[i];
			sum -= increments[i];
			increments[i] = 0;
			sum -= A[i--];
    	}
    	printf("%.9lf\n", sum / (i+1));
    } 

    return 0;
}