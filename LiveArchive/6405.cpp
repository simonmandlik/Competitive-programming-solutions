#include <bits/stdc++.h>
using namespace std;

int main() {
	cout << fixed << setprecision(1);
    ios::sync_with_stdio(false);
	double G, ch, p, b, bch, bp;
	while(cin >> G && G > 0) {
		b = bp = bch = 0;
		for(double ch = 0; ch <= G/5; ch += 0.5) {
			for(double p : vector<double>{ch, max(0.0, ch-0.5), ch+0.5})
				if (2*p + 5*ch <= G && 2*p+5*ch > b) {
					b = 2*p + 5*ch;
					bch = ch;
					bp = p;
				}
		}
		// cout << G <<": ";
		cout << G-b << " " << bp << " " << bp << " " << bch << endl;
	}
}