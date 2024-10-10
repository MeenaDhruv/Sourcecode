#include <iostream>
#include <vector>
#define INF 99999
using namespace std;

void floydWarshall(vector<vector<int>>& dist, int V) {
    for (int k = 0; k < V; k++) {
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                if (dist[i][k] + dist[k][j] < dist[i][j])
                    dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    }
}

int main() {
    int V = 4;
    vector<vector<int>> dist = { {0, 3, INF, 7},
                                 {8, 0, 2, INF},
                                 {5, INF, 0, 1},
                                 {2, INF, INF, 0} };
    floydWarshall(dist, V);
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (dist[i][j] == INF)
                cout << "INF" << " ";
            else
                cout << dist[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
