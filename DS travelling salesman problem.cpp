#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

#define MAX_CITIES 10

int graph[MAX_CITIES][MAX_CITIES];
int numCities;

bool visited[MAX_CITIES];
int currentPath[MAX_CITIES];
int bestPath[MAX_CITIES];
int bestDistance = INT_MAX;

int distance(int city1, int city2) {
    return graph[city1][city2];
}

bool allVisited() {
    for (int i = 0; i < numCities; i++) {
        if (!visited[i]) {
            return false;
        }
    }
    return true;
}

int calculatePathDistance(int path[]) {
    int totalDistance = 0;
    for (int i = 0; i < numCities - 1; i++) {
        totalDistance += distance(path[i], path[i + 1]);
    }

    totalDistance += distance(path[numCities - 1], path[0]);
    return totalDistance;
}

void tsp(int level) {
    if (level == numCities) {
        int currentDistance = calculatePathDistance(currentPath);
        if (currentDistance < bestDistance) {
            bestDistance = currentDistance;
            for (int i = 0; i < numCities; i++) {
                bestPath[i] = currentPath[i];
            }
        }
        return;
    }

    for (int i = 0; i < numCities; i++) {
        if (!visited[i]) {
            visited[i] = true;
            currentPath[level] = i;
            tsp(level + 1);
            visited[i] = false;
        }
    }
}

int main() {
    printf("Enter the number of cities: ");
    scanf("%d", &numCities);

    printf("Enter the distance matrix (row by row):\n");
    for (int i = 0; i < numCities; i++) {
        for (int j = 0; j < numCities; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    for (int i = 0; i < numCities; i++) {
        visited[i] = false;
        currentPath[i] = 0;
    }

    visited[0] = true; 
    tsp(1);

    printf("Shortest path: ");
    for (int i = 0; i < numCities; i++) {
        printf("%d ", bestPath[i]);
    }
    printf("\n");

    printf("Shortest distance: %d\n", bestDistance);

    return 0;
}

