#include <iostream>
#include <string>
using namespace std;

// ===== Queue (antrean peminjam, FIFO) =====
const int MAX = 100;
string antrean[MAX];
int depan = 0, belakang = 0;

void enqueue(string nama) {
    if (belakang == MAX) {
        cout << "Antrean penuh\n";
        return;
    }
    antrean[belakang] = nama;
    belakang++;
}

void dequeue() {
    if (depan == belakang) {
        cout << "Antrean kosong\n";
        return;
    }
    cout << antrean[depan] << " dilayani untuk meminjam buku\n";
    depan++;
}

void tampilAntrean() {
    if (depan == belakang) {
        cout << "Antrean kosong\n";
        return;
    }
    cout << "Antrean (depan -> belakang): ";
    for (int i = depan; i < belakang; i++) cout << antrean[i] << " ";
    cout << endl;
}

// ===== Stack (riwayat pengembalian, LIFO) =====
int riwayat[MAX];
int top = -1;

void push(int idBuku) {
    if (top == MAX - 1) {
        cout << "Stack penuh\n";
        return;
    }
    top++;
    riwayat[top] = idBuku;
}

void tampilRiwayat() {
    if (top == -1) {
        cout << "Riwayat kosong\n";
        return;
    }
    cout << "Riwayat pengembalian (terbaru -> terlama): ";
    for (int i = top; i >= 0; i--) cout << riwayat[i] << " ";
    cout << endl;
}

// ===== BST (ID buku) =====
struct Node {
    int id;
    Node* kiri;
    Node* kanan;
};

Node* root = NULL;

Node* insertBST(Node* node, int id) {
    if (node == NULL) {
        Node* baru = new Node;
        baru->id = id;
        baru->kiri = NULL;
        baru->kanan = NULL;
        return baru;
    }
    if (id < node->id) node->kiri = insertBST(node->kiri, id);
    else if (id > node->id) node->kanan = insertBST(node->kanan, id);
    else cout << "ID sudah ada\n";
    return node;
}

bool cariBST(Node* node, int id) {
    if (node == NULL) return false;
    if (node->id == id) return true;
    if (id < node->id) return cariBST(node->kiri, id);
    return cariBST(node->kanan, id);
}

void preOrder(Node* node) {
    if (node == NULL) return;
    cout << node->id << " ";
    preOrder(node->kiri);
    preOrder(node->kanan);
}

void inOrder(Node* node) {
    if (node == NULL) return;
    inOrder(node->kiri);
    cout << node->id << " ";
    inOrder(node->kanan);
}

void postOrder(Node* node) {
    if (node == NULL) return;
    postOrder(node->kiri);
    postOrder(node->kanan);
    cout << node->id << " ";
}

int main() {
    int pilih;
    do {
        cout << "\n=== PERPUSTAKAAN ===\n";
        cout << "1. Tambah buku (ID ke BST)\n2. Masuk antrean peminjaman\n";
        cout << "3. Layani antrean\n4. Kembalikan buku\n5. Tampilkan antrean\n";
        cout << "6. Tampilkan riwayat pengembalian\n7. Cari ID buku\n8. Tampilkan BST (traversal)\n0. Keluar\nPilih: ";
        cin >> pilih;

        if (pilih == 1) {
            int id;
            cout << "ID buku: "; cin >> id;
            root = insertBST(root, id);
        } else if (pilih == 2) {
            string nama;
            cout << "Nama mahasiswa: "; cin >> nama;
            enqueue(nama);
        } else if (pilih == 3) {
            dequeue();
        } else if (pilih == 4) {
            int id;
            cout << "ID buku yang dikembalikan: "; cin >> id;
            push(id);
        } else if (pilih == 5) {
            tampilAntrean();
        } else if (pilih == 6) {
            tampilRiwayat();
        } else if (pilih == 7) {
            int id;
            cout << "ID buku: "; cin >> id;
            if (cariBST(root, id)) cout << "Buku ditemukan\n";
            else cout << "Buku tidak ditemukan\n";
        } else if (pilih == 8) {
            if (root == NULL) {
                cout << "BST kosong\n";
            } else {
                cout << "Pre-Order : "; preOrder(root); cout << endl;
                cout << "In-Order  : "; inOrder(root); cout << endl;
                cout << "Post-Order: "; postOrder(root); cout << endl;
            }
        }
    } while (pilih != 0);

    return 0;
}
