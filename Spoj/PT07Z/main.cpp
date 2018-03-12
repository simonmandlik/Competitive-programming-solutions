#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    int N, u ,v;
    cin >> N;
    vector<vector<int>> neighList(N);
    vector<bool> visited(N);
    vector<int> dist(N);
    for (int i = 0; i < N - 1; ++i) {
        cin >> u >> v;
        u--, v--;
        neighList[u].push_back(v);
        neighList[v].push_back(u);
    }

    int farthest = 0, curr;

    queue<int> q;
    q.push(0);
    visited[0] = true;
    while (!q.empty()) {
        curr = q.front(); q.pop();
        dist[curr] = -1;
        for (int n : neighList[curr]) {
            if (!visited[n]) {
                visited[n] =  true;
                q.push(n);
            }
        }
    }
    farthest = curr;
    dist[farthest] = 0;
    q.push(farthest);
    while (!q.empty()) {
        curr = q.front(); q.pop();
        for (int n : neighList[curr]) {
            if (dist[n] == -1) {
                dist[n] = dist[curr] + 1;
                q.push(n);
            }
        }
    }
    cout << dist[curr];
    return 0;
}