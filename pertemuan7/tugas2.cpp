#include <iostream>
#include <vector>
using namespace std;

const int INF = 999999;

void dijkstra(int graph[6][6], int start, int dist[], int parent[]) {
    bool visited[6] = {false};

    for (int i = 0; i < 6; i++) {
        dist[i] = INF;
        parent[i] = -1;
    }

    dist[start] = 0;

    for (int i = 0; i < 6; i++) {
        int u = -1;

        for (int j = 0; j < 6; j++) {
            if (!visited[j] && (u == -1 || dist[j] < dist[u])) {
                u = j;
            }
        }

        if (u == -1 || dist[u] == INF) {
            break;
        }

        visited[u] = true;

        for (int v = 0; v < 6; v++) {
            if (graph[u][v] != INF && !visited[v]) {
                if (dist[u] + graph[u][v] < dist[v]) {
                    dist[v] = dist[u] + graph[u][v];
                    parent[v] = u;
                }
            }
        }
    }
}

void tampilkanRute(int parent[], int tujuan) {
    if (parent[tujuan] == -1) {
        cout << char(tujuan + 'A');
        return;
    }

    tampilkanRute(parent, parent[tujuan]);
    cout << " -> " << char(tujuan + 'A');
}

int main() {
    int graph[6][6];

    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 6; j++) {
            graph[i][j] = (i == j) ? 0 : INF;
        }
    }

    graph[0][1] = graph[1][0] = 4;
    graph[0][2] = graph[2][0] = 2;
    graph[1][2] = graph[2][1] = 1;
    graph[1][3] = graph[3][1] = 5;
    graph[1][4] = graph[4][1] = 3;
    graph[2][3] = graph[3][2] = 8;
    graph[2][4] = graph[4][2] = 6;
    graph[3][4] = graph[4][3] = 2;
    graph[3][5] = graph[5][3] = 4;
    graph[4][5] = graph[5][4] = 3;

    int dist[6], parent[6];

    dijkstra(graph, 0, dist, parent);

    cout << "Jarak Terpendek dari A:\n";

    for (int i = 0; i < 6; i++) {
        cout << "A ke " << char(i + 'A') << " = ";
        tampilkanRute(parent, i);
        cout << " (" << dist[i] << " km)" << endl;
    }

    char asal, tujuan;

    cout << "\nMasukkan lokasi awal (A-F): ";
    cin >> asal;

    cout << "Masukkan lokasi tujuan (A-F): ";
    cin >> tujuan;

    int start = asal - 'A';
    int end = tujuan - 'A';

    dijkstra(graph, start, dist, parent);

    cout << "\nRekomendasi Rute Terpendek:\n";

    if (dist[end] == INF) {
        cout << "Rute tidak ditemukan.";
    } else {
        tampilkanRute(parent, end);
        cout << "\nTotal jarak: " << dist[end] << " km";
    }

    cout << endl;

    return 0;
}