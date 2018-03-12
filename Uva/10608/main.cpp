#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    int T;
    int N, M, u , v;
    cin >> T;
    while(T-- > 0) {
        cin >> N >> M;
        vector<vector<int>> neighList(N);
        vector<bool> visited(N);
        for (int i = 0; i < M; ++i) {
            cin >> u >> v; u--, v--;
            neighList[u].push_back(v);
            neighList[v].push_back(u);
        }
        int m = 0, size, curr;
        queue<int> q;
        for(int i = 0; i < N; ++i) {
            if (!visited[i]) {
                size = 1;
                q.push(i);
                visited[i] = true;
                while (!q.empty()) {
                    curr = q.front();
                    q.pop();
                    for (int n : neighList[curr]) {
                        if (!visited[n]) {
                            ++size;
                            q.push(n);
                            visited[n] = true;
                        }
                    }
                }
            }
            m = max(size, m);
        }
        cout << m << endl;

    }
    return 0;
}