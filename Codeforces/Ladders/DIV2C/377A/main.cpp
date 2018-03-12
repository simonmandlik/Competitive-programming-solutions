#include <bits/stdc++.h>
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    int N, M, K, E=0; cin >> N >> M >> K;
    char maze[N+2][M+2];
    bool visited[N+2][M+2];

    for(int i = 1; i <= N; ++i) {
    	maze[i][0] = maze[i][M+1] = '#';
    	for(int j = 1; j <= M; ++j) {
    		cin >> maze[i][j];
    		if(maze[i][j] == '.') ++E;
    		visited[i][j] = false;
    	}
    }
    for(int j = 0; j <= M + 1; ++j) {
    	maze[0][j] = maze[N+1][j] = '#';
    }

    queue<pair<int, int>> q;
   	for(int i = 1; i <= N && q.empty(); ++i) {
   		for(int j = 1; j <= M && q.empty(); ++j) {
   			if (maze[i][j] == '.') {
   				visited[i][j] = true;
   				q.push({i,j});
   			}
   		}
   	}

   	pair<int, int> curr;
   	vector<pair<int, int>> dirs = {{1,0}, {-1,0}, {0,1}, {0,-1}};
   	int i, j, k = 1;
   	while(!q.empty()) {
   		curr = q.front(); q.pop();
   		i = curr.first; j = curr.second;
   		if (k++ > E-K)  maze[i][j] = 'X';
   		for(auto d : dirs) {
   			if (maze[i+d.first][j+d.second] == '.' && !visited[i+d.first][j+d.second]) {
   				visited[i+d.first][j+d.second] = true;
   				q.push({i+d.first,j+d.second});
   			}
   		}
   	}

   	for(int i = 1; i <= N; ++i) {
   		for(int j = 1; j <= M; ++j) {
   			cout << maze[i][j];
   		}
   		cout << endl;
   	}
   	cout << endl;

    return 0;
}