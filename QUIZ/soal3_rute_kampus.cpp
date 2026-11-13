#include <iostream>
using namespace std;

const int N = 6;
const int INF = 9999;
int graf[N][N];

void tambahSisi(int a, int b, int w) {
    graf[a][b] = w;
    graf[b][a] = w;
}

void isiGraf() {
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            graf[i][j] = 0;

    // A=0, B=1, C=2, D=3, E=4, F=5
    tambahSisi(0, 1, 4);
    tambahSisi(0, 2, 2);
    tambahSisi(1, 2, 1);
    tambahSisi(1, 3, 5);
    tambahSisi(1, 4, 3);
    tambahSisi(2, 3, 8);
    tambahSisi(2, 4, 6);
    tambahSisi(3, 4, 2);
    tambahSisi(3, 5, 4);
    tambahSisi(4, 5, 3);
}

void tampilMatrix() {
    cout << "  A B C D E F\n";
    for (int i = 0; i < N; i++) {
        cout << char('A' + i) << " ";
        for (int j = 0; j < N; j++) cout << graf[i][j] << " ";
        cout << endl;
    }
}

void bfs(int mulai) {
    bool visited[N] = {false};
    int antrean[N];
    int depan = 0, belakang = 0;

    visited[mulai] = true;
    antrean[belakang++] = mulai;

    while (depan < belakang) {
        int cur = antrean[depan++];
        cout << char('A' + cur) << " ";
        for (int i = 0; i < N; i++) {
            if (graf[cur][i] != 0 && !visited[i]) {
                visited[i] = true;
                antrean[belakang++] = i;
            }
        }
    }
    cout << endl;
}

void dfs(int cur, bool visited[]) {
    visited[cur] = true;
    cout << char('A' + cur) << " ";
    for (int i = 0; i < N; i++) {
        if (graf[cur][i] != 0 && !visited[i]) dfs(i, visited);
    }
}

void dijkstra(int awal, int tujuan) {
    int jarak[N];
    int asal[N];
    bool selesai[N];

    for (int i = 0; i < N; i++) {
        jarak[i] = INF;
        asal[i] = -1;
        selesai[i] = false;
    }
    jarak[awal] = 0;

    for (int k = 0; k < N; k++) {
        // cari vertex belum selesai dengan jarak terkecil
        int u = -1;
        for (int i = 0; i < N; i++) {
            if (!selesai[i] && (u == -1 || jarak[i] < jarak[u])) u = i;
        }
        if (jarak[u] == INF) break;
        selesai[u] = true;

        for (int v = 0; v < N; v++) {
            if (graf[u][v] != 0 && jarak[u] + graf[u][v] < jarak[v]) {
                jarak[v] = jarak[u] + graf[u][v];
                asal[v] = u;
            }
        }
    }

    if (jarak[tujuan] == INF) {
        cout << "Rute tidak ditemukan\n";
        return;
    }

    // susun rute dari tujuan mundur ke awal
    int rute[N];
    int n = 0;
    for (int v = tujuan; v != -1; v = asal[v]) rute[n++] = v;

    cout << "Rute: ";
    for (int i = n - 1; i >= 0; i--) {
        cout << char('A' + rute[i]);
        if (i > 0) cout << " -> ";
    }
    cout << "\nTotal jarak: " << jarak[tujuan] << endl;
}

int main() {
    isiGraf();
    int pilih;
    char a, b;

    do {
        cout << "\n=== RUTE KAMPUS ===\n";
        cout << "1. Tampilkan adjacency matrix\n2. BFS\n3. DFS\n4. Dijkstra (rute terpendek)\n0. Keluar\nPilih: ";
        cin >> pilih;

        if (pilih == 1) {
            tampilMatrix();
        } else if (pilih == 2) {
            cout << "Vertex awal (A-F): "; cin >> a;
            cout << "BFS: ";
            bfs(a - 'A');
        } else if (pilih == 3) {
            cout << "Vertex awal (A-F): "; cin >> a;
            bool visited[N] = {false};
            cout << "DFS: ";
            dfs(a - 'A', visited);
            cout << endl;
        } else if (pilih == 4) {
            cout << "Vertex awal (A-F): "; cin >> a;
            cout << "Vertex tujuan (A-F): "; cin >> b;
            dijkstra(a - 'A', b - 'A');
        }
    } while (pilih != 0);

    return 0;
}
