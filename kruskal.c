#include <stdio.h>

#define MAX 10
#define INF 999

int parent[MAX];

int find(int i);
void uni(int i, int j);
void kruskal(int n, int cost[MAX][MAX]);

int main() {
    int cost[MAX][MAX], n;

    printf("Enter the number of nodes: ");
    scanf("%d", &n);
    
    printf("Enter the cost matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &cost[i][j]);
            if (cost[i][j] == 0) {
                cost[i][j] = INF;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        parent[i] = -1;
    }

    kruskal(n, cost);

    return 0;
}

void kruskal(int n, int cost[MAX][MAX]) {
    int a, b, u, v, i, j, ne = 1, min, mincost = 0;

    printf("The edges of minimum cost spanning tree are:\n");

    while (ne < n) {
        for (i = 0, min = INF; i < n; i++) {
            for (j = 0; j < n; j++) {
                if (cost[i][j] < min) {
                    min = cost[i][j];
                    a = u = i;
                    b = v = j;
                }
            }
        }

        u = find(u);
        v = find(v);

        if (u != v) {
            uni(u, v);
            ne++;
            printf("Edge (%d, %d) = %d\n", a, b, min);
            mincost += min;
        }

        cost[a][b] = cost[b][a] = INF;
    }

    printf("\nMinimum cost = %d\n", mincost);
}

int find(int i) {
    while (parent[i] > 0) {
        i = parent[i];
    }
    return i;
}

void uni(int i, int j) {
    parent[j] = i;
}
