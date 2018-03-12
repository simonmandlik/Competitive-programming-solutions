#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> adjList;
vector<int> vis, deg, dist;
vector<int> best, worst;

void traverse(int node, int root) {
    for (int ch : adjList[node]) {
        if (root != vis[ch]) {
            vis[ch] = root;
            dist[ch] = min(dist[ch], dist[node] + 1);
            traverse(ch, root);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    int N, num, u;
    while(cin >> N) {
//        cin >> N;
        adjList.resize(N);
        vis.resize(N);
        deg.resize(N);
        dist.resize(N);
        for (int j = 0; j < N; ++j) {
            dist[j] = INT_MAX;
            vis[j] = -1;
            deg[j] = 0;
        }
        for (int i = 0; i < N; ++i) {
            cin >> num;
            while (num-- > 0) {
                cin >> u;
                --u;
//                cout << u << " " << i << endl;
                adjList[i].push_back(u);
                adjList[u].push_back(i);
                ++deg[i]; ++deg[u];
            }
        }

        queue<int> q;
        int removed = 0;
        for (int k = 0; k < N; ++k) {
            if (deg[k] == 2) {
                q.push(k);
            }
        }
        int curr;
        vector<int> next;
        while(removed < N - 2) {
            while(!q.empty()) {
                curr = q.front();
                ++removed;
                q.pop();
//                cout << curr << endl;
                for (int n : adjList[curr]) {
//                    cout << n << endl;
                    if (--deg[n] == 2) {
                        next.push_back(n);
                    }
                }
            }
            for(int n : next) {
                q.push(n);
            }
            next.clear();
        }

        while (!q.empty()) {
            curr = q.front();
            best.push_back(curr);
            dist[curr] = 0;
            q.pop();
        }

        for (int r : best) {
            vis[r] = r;
            dist[r] = 0;
            traverse(r, r);
        }

        int res = 0;
        for(int r = 0; r < N; ++r) {
            if (dist[r] >= res) {
                if (dist[r] > res) {
                    res = dist[r];
                    worst.clear();
                    worst.push_back(r + 1);
                } else {
                    worst.push_back(r + 1);
                }
            }
        }

        sort(best.begin(), best.end());
        sort(worst.begin(), worst.end());
        cout << "Best Roots  :";
        for (int r : best) cout << " " << r + 1;
        cout << endl;
        cout << "Worst Roots :";
        for (int r : worst) cout << " " << r;
        cout << endl;
        adjList.clear();
        vis.clear();
        worst.clear();
        best.clear();
    }
    return 0;
}