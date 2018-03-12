#include <cstdio>
#include <vector>
#include <algorithm>
#include <iostream>
#include <string>
#include <stack>
#include <set>

using namespace std;

const int MAX_N = 1000;

int main() {
	int T, N, M, a, b, curr, p, neigh;
	scanf("%d", &T);
    vector<set<int> > neighbours;
    vector<int> partites;
    bool solved;
	while (T-- > 0) {
		scanf("%d %d", &N, &M);
        solved = false;
        neighbours.resize(N);
        for (int j = 0; j < N; ++j) {
            neighbours[j].clear();
            for (int i = 0; i < N; ++i) {
                if (i != j) neighbours[j].insert(i);
            }
        }
		for(int i = 0; i < M; ++i) {
			scanf("%d %d", &a, &b); a--; b--;
            if (a != b) {
                if (neighbours[a].count(b) > 0)
                    neighbours[a].erase(b);
                if (neighbours[b].count(a) > 0)
                    neighbours[b].erase(a);
            }
		}
        partites.clear();
        partites.resize(N, 0);
        for (int k = 0; k < N; ++k) {
            if (partites[k] == 0 && !solved) {
//                cout << endl << k << " ";
                stack<int> dfs;
                dfs.push(k);
                p = 1;
                partites[k] = p;
                while (!dfs.empty() && !solved) {
                    curr = dfs.top();
                    dfs.pop();
                    p *= -1;
                    for (set<int>::iterator it = neighbours[curr].begin(); it != neighbours[curr].end(); ++it) {
                        neigh = *it;
//                        cout << neigh << " " << partites[neigh] << endl;
                        if (partites[neigh] != 0) {
                            if (partites[neigh] == partites[curr]) {
                                printf("NO\n");
                                solved = true;
                                break;
                            }
                        } else {
                            partites[neigh] = p;
                            dfs.push(neigh);
                        }
                    }
                }
            }
        }
//        for (int k = 0; k < partites.size(); ++k) {
//            cout << partites[k] << " ";
//        }
        if (!solved) printf("YES\n");
	}
	return 0;
}

