#include <bits/stdc++.h>
using namespace std;
#define EPS (1e-10)
#define DEBUG(x) cout << "> " << #x << ": " << x << endl;
#define REP(i, n) for (int i = 0; i < (n); i++)
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define FORD(i, a, b) for (int i = (a); i >= (b); i--)
#define BE(c) c.begin(), c.end()
#define PB(v, i) v.push_back(i)
typedef long double ld;
typedef long long ll;
typedef pair<int, int> ii;
typedef pair<double, double> dd;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<double> vd;
typedef vector<bool> vb;
typedef vector<vector<int>> vvi;
typedef vector<ii> vii;

int main() {
    ios::sync_with_stdio(false);
    int w, n, i, j;
	vector<string> words(100); string s;
	while(cin >> s && s != "#") {
		w = 0;
		while(s != "*") {
			words[w++] = s;
			cin >> s;
		}
		sort(words.begin(), words.begin() + w);
		vector<vector<bool>> contains(w, vb(26, false));
		REP(i, w) for(char c : words[i]) contains[i][c - 'a'] = true;
		while(cin >> s && s != "**") {
			n = s.length();
			vb qm(w, false);
			i = 0;
			while(i < n) {
				vb tm(w, true);
				j = i+1;
				while (j < n && isalnum(s[j])) ++j;
				for(int l = 0; l < w; ++l) {
					if (!tm[l]) continue;
					bool cont = false;
					for(int k = i; k < j; ++k) {
						if (contains[l][s[k] - 'a']) {
							cont = true;
							break;
						}
					}
					if (!cont) {
						tm[l] = false;
					}
				}
				i = j;
				while(i < n && s[i] == '+' || s[i] == '-') {
					for(int l = 0; l < w; ++l) {
						if (s[i] == '+' ^ contains[l][s[i+1] - 'a']) {
								tm[l] = false;
						}
					}
					i += 2;
				}
				REP(i, w) qm[i] = qm[i] || tm[i];
				++i;
			}
			int i = 0;
			for(; i < w; ++i) if (qm[i]) break;
			cout << (i == w ? "NONE" : words[i]) << endl;
		}
		cout << "$" << endl;
	}
}