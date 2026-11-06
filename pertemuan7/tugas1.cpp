#include <iostream>
#include <queue>
using namespace std;

int main() {
    int graph[6][6] = {0};
    int jumlah;
    char a, b, awal;

    cout << "Masukkan jumlah edge: ";
    cin >> jumlah;

    for (int i = 0; i < jumlah; i++) {
        cout << "Masukkan edge: ";
        cin >> a >> b;

        int x = a - 'A';
        int y = b - 'A';

        graph[x][y] = 1;
        graph[y][x] = 1;
    }

    cout << "Masukkan vertex awal: ";
    cin >> awal;

    bool visited[6] = {false};
    queue<int> q;

    int start = awal - 'A';

    q.push(start);
    visited[start] = true;

    cout << "Urutan BFS: ";

    while (!q.empty()) {
        int sekarang = q.front();
        q.pop();

        cout << char(sekarang + 'A') << " ";

        for (int i = 0; i < 6; i++) {
            if (graph[sekarang][i] == 1 && visited[i] == false) {
                q.push(i);
                visited[i] = true;
            }
        }
    }

    return 0;
}