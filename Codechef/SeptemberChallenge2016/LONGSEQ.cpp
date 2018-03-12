#include <cstdio>

int main() {
	int T;
	scanf("%d ", &T);
	char ch;
	int a, b;
	while (T-- > 0) {
		a = b = 0;
		while((ch = getchar()) != '\n' || ch != EOF) {
			if (ch == '\n' || ch == EOF) break;
			if (ch - '0' == 0) ++a;
			else ++b;
		}

		if (b == 1 || a == 1) puts("Yes");
		else puts("No");

	}
	return 0;

}
