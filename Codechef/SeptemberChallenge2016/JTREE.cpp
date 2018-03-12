#include <cstdio>
#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <algorithm>
#include <climits>

using namespace std;

class Ticket {
private:
    int price;
    int dist;
public:
    Ticket(int price, int dist) : price(price), dist(dist) {}

    inline int getPrice() const { return price; }

    inline int getDist() const { return dist; }
};

int traverse(int k, int w, int node, int *parents, int *DP) {
    int res = w + DP[node];
    if (k > 0 && parents[node] != -1) {
        res = min(res, traverse(k - 1, w, parents[node], parents, DP));
    }
    return res;
}

int main() {
    int N, M, Q, a, b, v, k, w, f;
    scanf("%d %d", &N, &M);
    int parents[N];
    int DP[N];
    fill_n(DP, N, INT_MAX / 2);
    vector< vector<Ticket> > tickets(N);
    vector< vector<int> > children(N);

    set<int> root;
    for (int m = 0; m < N; ++m) {
        root.insert(m);
    }

    for (int i = 0; i < N - 1; ++i) {
        scanf("%d %d", &a, &b); a--; b--;
        children[b].push_back(a);
        parents[a] = b;
        root.erase(a);
    }

    for (int j = 0; j < M; ++j) {
        scanf("%d %d %d", &v, &k, &w); v--;
        tickets[v].push_back(Ticket(w, k));
    }

    queue<int> q;
    int top = *root.begin();
    q.push(top);
    DP[top] = 0;
//    cout << endl;

    int curr;
    while (!q.empty()) {
//        for (int l = 0; l < N; ++l) {
//            cout << DP[l] << " ";
//        }
//        cout << endl << endl;

        curr = q.front();
        for (int j = 0; j < tickets[curr].size(); ++j) {
            Ticket t = tickets[curr][j];
            DP[curr] = min(DP[curr], traverse(t.getDist(), t.getPrice(), curr, parents, DP));
        }
        for (int i = 0; i < children[curr].size(); ++i) {
            q.push(children[curr][i]);
        }
        q.pop();
    }

    scanf("%d", &Q);
    for (int l = 0; l < Q; ++l) {
        scanf("%d", &f); f--;
        printf("%d\n", DP[f]);
    }

    return 0;
}