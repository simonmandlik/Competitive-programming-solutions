#include <bits/stdc++.h>

int *tree;

int root(int i) {
    while (tree[i] != i) i = tree[i];
    return i;
}

int connected(int u, int v) {
    return (root(u) == root(v));
}

void connect(int u, int v) {
    tree[root(u)] = root(v);
}

int main() {
    int nodes, edges, u, v, i, j, temp;

    scanf("%d %d", &nodes, &edges);

    if (edges != nodes - 1) {
        printf("NO\n");
        return 0;
    }

    if (nodes == 1) {
        return 0;
    }

    tree = new int[nodes];

    for (i = 0; i < nodes; i++)
        tree[i] = i;

    for (i = 0; i < edges; i++) {
        scanf("%d %d", &u, &v);
        u--;
        v--;
        if (!connected(u, v))
            connect(u, v);
        else {
            printf("NO\n");
            return 0;
        }
    }

    printf("YES\n");
    return 0;
}
