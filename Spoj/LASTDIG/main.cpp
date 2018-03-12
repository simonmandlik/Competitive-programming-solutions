#include <stdio.h>

int power(int a, int p) {
	if (p == 0) return 1;
	int r = power(a, p/2);
	r*=r;
	if (p&1) r*=a;
	return r%10;
}

int main() {
	int a,b,T;
	scanf("%d", &T);
	while(T-- > 0) {
		scanf("%d%d", &a, &b);
		printf("%d\n", power(a%10, b));
	}
	return 0;
}