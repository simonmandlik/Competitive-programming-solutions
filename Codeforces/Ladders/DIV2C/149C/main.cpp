#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    int N, a; cin >> N;
    vector<pair<int, int>> players(N);
    for(int i = 0; i < N; ++i) {
    	cin >> a;
    	players[i] = {a, i+1};
    }
    sort(players.rbegin(), players.rend());
    int teamA = 1 + 2*((N-1)/4) + (((N-1) % 4 == 3) ? 1:0);
    int teamB = N - teamA;
    cout << teamA << endl;
    cout << players[0].second << " ";
    for(int i = 3; i < N; i += 4) {
    	cout << players[i].second << " ";
    	if (i + 1 < N) {
    		cout << players[i+1].second << " ";
    	}
    }
    cout << endl;
    cout << teamB << endl;
    for(int i = 1; i < N; i += 4) {
    	cout << players[i].second << " ";
    	if (i + 1 < N) {
    		cout << players[i+1].second << " ";
    	}
    }
    return 0;
}