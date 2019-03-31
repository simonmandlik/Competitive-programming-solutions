#include <bits/stdc++.h>
#pragma GCC optimize ("Ofast")
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

struct Trip {
    int dh, dm, ah, am;
};

Trip read_trip(int turn) {
    int tm = turn % 60, th = turn / 60;
    char x;
    int dh = 0, dm = 0, ah = 0, am = 0;
    cin >> x;
    dh += 10*(x-'0');
    cin >> x;
    dh += (x-'0');
    cin >> x;
    cin >> x;
    dm += 10*(x-'0');
    cin >> x;
    dm += (x-'0');
    cin >> x;
    ah += 10*(x-'0');
    cin >> x;
    ah += (x-'0');
    cin >> x;
    cin >> x;
    am += 10*(x-'0');
    cin >> x;
    am += (x-'0');
    am += tm;
    ah += th + am/60;
    am %= 60;
    return {dh, dm, ah, am};
}

int solve (vector<Trip> &tA, vector<Trip> &tB) {
    sort(tA.begin(), tA.end(), [](const Trip &a, const Trip &b) {
            if (a.dh == b.dh) return a.dm < b.dm;
            else return a.dh < b.dh; });
    sort(tB.begin(), tB.end(), [](const Trip &a, const Trip &b) {
            if (a.ah == b.ah) return a.am < b.am;
            else return a.ah < b.ah; });
    int i = 0, j = 0, trains = 0, res = 0;
    while (i < tA.size()) {
        if (j == tB.size() ||
                tA[i].dh < tB[j].ah ||
                (tA[i].dh == tB[j].ah && tA[i].dm < tB[j].am)) {
            if (trains == 0) { ++res; ++trains; }
            --trains; ++i;
        } else { ++trains; ++j; }
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    int T; cin >> T;
    REP(t, T) {
        int NA, NB, A, B, turn;
        cin >> turn >> NA >> NB;
        vector<Trip> tA(NA), tB(NB);
        REP(i, NA) tA[i] = read_trip(turn);
        REP(i, NB) tB[i] = read_trip(turn);
        A = solve(tA, tB); 
        B = solve(tB, tA); 
        cout << "Case #" << t+1 << ": " << A << " " << B << endl;
    }
}
