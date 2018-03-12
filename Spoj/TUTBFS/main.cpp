#include <bits/stdc++.h>

using namespace std;

int xValues[] = {1, -1, 1, -1, 0, 0, -1, 1};
int yValues[] = {1, -1, 0, 0, -1, 1, 1, -1};
int N, M;

struct Point {
    int a, b;
};

inline int hash_point(int x, int y) { return x * M + y; }

inline int hash_point(Point &p) { return p.a * M + p.b; }

int main() {
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    while (T-- > 0) {
        cin >> N >> M;
        int dist[(N + 2) * (M + 2)];
        bool visited[(N + 2) * (M + 2)];
        char board[N + 2][M + 2];
        for (int i = 1; i <= N; ++i) {
            board[i][0] = board[i][M + 1] = '#';
            for (int j = 1; j <= M; ++j) {
                dist[hash_point(i, j)] = 0;
                visited[hash_point(i, j)] = false;
                cin >> board[i][j];
            }
        }
        for (int j = 1; j <= M; ++j) {
            board[0][j] = board[N + 1][j] = '#';
        }
        board[0][0] = board[N + 1][0] = board[0][M + 1] = board[N + 1][M + 1] = '#';

        int m = 0;
        queue<Point> q;
        visited[M + 1] = true;
        q.push(Point{1, 1});
        while (!q.empty()) {
            Point &curr = q.front();
            m = max(m, dist[hash_point(curr)]);
            q.pop();
            for (int x : xValues) {
                for (int y : yValues) {
                    int n_x = curr.a + x;
                    int n_y = curr.b + y;
                    int n = hash_point(n_x, n_y);
                    if (board[n_x][n_y] == '.' && !visited[n]) {
                        visited[n] = true;
                        dist[n] = dist[hash_point(curr)] + 1;
                        q.push(Point{n_x, n_y});
                    }
                }
            }
        }
        cout << m << endl;
    }
    return 0;
}