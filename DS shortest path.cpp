#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

#define MAX_NODES 100

int graph[MAX_NODES][MAX_NODES];
int numNodes;

void initGraph(int n) {
    numNodes = n;
    for (int i = 0; i < numNodes; i++) {
        for (int j = 0; j < numNodes; j++) {
            graph[i][j] = INT_MAX; 
        }
        graph[i][i] = 0; 
    }
}

void addEdge(int u, int v, int weight) {
    graph[u][v] = weight;

}

int minDistance(int dist[], bool visited[]) {
    int minDist = INT_MAX, minIndex;
    for (int i = 0; i < numNodes; i++) {
        if (!visited[i] && dist[i] <= minDist) {
            minDist = dist[i];
            minIndex = i;
        }
    }
    return minIndex;
}

void printPath(int parent[], int target) {
    if (parent[target] == -1) {
        printf("%d ", target);
        return;
    }
    printPath(parent, parent[target]);
    printf("%d ", target);
}

void dijkstra(int source) {
    int dist[MAX_NODES]; 
    bool visited[MAX_NODES]; 
    int parent[MAX_NODES]; 

    for (int i = 0; i < numNodes; i++) {
        dist[i] = INT_MAX;
        visited[i] = false;
        parent[i] = -1;
    }

    dist[source] = 0;

    for (int count = 0; count < numNodes - 1; count++) {
        int u = minDistance(dist, visited);
        visited[u] = true;

        for (int v = 0; v < numNodes; v++) {
            if (!visited[v] && graph[u][v] != INT_MAX && dist[u] != INT_MAX &&
                dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
                parent[v] = u;
            }
        }
    }

    printf("Shortest paths from node %d:\n", source);
    for (int i = 0; i < numNodes; i++) {
        if (dist[i] == INT_MAX) {
            printf("Node %d is not reachable from the source node.\n", i);
        } else {
            printf("Node %d: Distance = %d, Path = ", i, dist[i]);
            printPath(parent, i);
            printf("\n");
        }
    }
}

int main() {
    int n, m; 
    printf("Enter the number of nodes and edges: ");
    scanf("%d %d", &n, &m);

    initGraph(n);

    printf("Enter the edges (source, target, weight):\n");
    for (int i = 0; i < m; i++) {
        int u, v, weight;
        scanf("%d %d %d", &u, &v, &weight);
        addEdge(u, v, weight);
    }

    int source;
    printf("Enter the source node: ");
    scanf("%d", &source);

    dijkstra(source);

    return 0;
}

