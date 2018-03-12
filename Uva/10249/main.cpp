#include <bits/stdc++.h>
#include <bits/algorithmfwd.h>

using namespace std;

const int MAX_TEAMS = 70;
const int MAX_TEABLES = 50;

int teams[MAX_TEAMS];
int team_order[MAX_TEAMS];
int tables[MAX_TEABLES];
int tables_order[MAX_TEABLES];

int main() {
    ios::sync_with_stdio(false);
    int P, T;
    cin >> P >> T;
    while (P) {
        for (int k = 0; k < P; ++k) {
            cin >> teams[k];
            team_order[k] = k;
        }
        for (int l = 0; l < T; ++l) {
            cin >> tables[k];
            tables_order[l] = l;
        }

        sort(team_order, team_order+T, [=](int i, int j) { return teams[i] < teams[j]; });
        sort(tables_orders, tables_order+T, [=](int i, int j) { return tables[i] > tables[j]; });


        cin >> P >> T;
    }

    return 0;
}