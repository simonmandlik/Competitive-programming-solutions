#include <iostream>

using namespace std;

int main() {
	int T;
	cin >> T;
	string s;
	string::iterator a, b;
	bool wrong;
	while(T-- > 0) {
		wrong = false;
		cin >> s;
		a = s.begin();
		b = s.end() - 1;
		while(a < b) {
			if (*a == '.' && *b != '.') *a = *b;
			else if (*b == '.' && *a != '.') *b = *a;
			else if (*a == '.' && *b == '.') *a = *b = 'a';
			else if (*a != *b) {
				cout << "-1" << endl;
				wrong = true;
				break;
			}
			a++; b--;
		}
		if (s.size() % 2 == 1 && *a == '.') *a = 'a';
		if (!wrong) cout << s << endl;
	}
	return 0;
}
