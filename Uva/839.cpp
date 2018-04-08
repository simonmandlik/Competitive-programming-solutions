#include <bits/stdc++.h>
using namespace std;

int balanced() {
	int Wl, Dl, Wr, Dr;
	cin >> Wl >> Dl >> Wr >> Dr;
	if (Wl == 0) Wl = balanced();
	if (Wr == 0) Wr = balanced();
	return (Wl*Dl == Wr*Dr && Wl != -1 && Wr != -1 ? Wl + Wr : -1);
}

int main() {
    ios::sync_with_stdio(false);
	int T; cin >> T;
	while(T-- > 0) {
		cout << (balanced() == -1 ? "NO" : "YES") << endl;
		if (T > 0) cout << endl;
	}
}