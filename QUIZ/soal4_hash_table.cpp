#include <iostream>
#include <string>
using namespace std;

const int SIZE = 20;
// status: 0 = kosong, 1 = terisi, 2 = sudah dihapus
int keys[SIZE];
string values[SIZE];
int status[SIZE];

int hash1(int key) { return key % 20; }
int hash2(int key) { return 19 - (key % 19); }

void insertData(int nim, string nama) {
    int h1 = hash1(nim);
    int h2 = hash2(nim);

    for (int i = 0; i < SIZE; i++) {
        int idx = (h1 + i * h2) % SIZE;
        if (status[idx] != 1) {
            keys[idx] = nim;
            values[idx] = nama;
            status[idx] = 1;
            if (i > 0) cout << "Collision! " << nim << " dipindah ke indeks " << idx << " (percobaan ke-" << i + 1 << ")\n";
            else cout << nim << " disimpan di indeks " << idx << endl;
            return;
        }
        if (keys[idx] == nim) {
            cout << "NIM sudah ada\n";
            return;
        }
    }
    cout << "Gagal menyimpan, table penuh\n";
}

int cariIndex(int nim) {
    int h1 = hash1(nim);
    int h2 = hash2(nim);

    for (int i = 0; i < SIZE; i++) {
        int idx = (h1 + i * h2) % SIZE;
        if (status[idx] == 0) return -1;   // slot kosong, berarti tidak ada
        if (status[idx] == 1 && keys[idx] == nim) return idx;
    }
    return -1;
}

void searchData(int nim) {
    int idx = cariIndex(nim);
    if (idx == -1) cout << "Data tidak ditemukan\n";
    else cout << "Ditemukan di indeks " << idx << ": " << values[idx] << endl;
}

void removeData(int nim) {
    int idx = cariIndex(nim);
    if (idx == -1) {
        cout << "Data tidak ditemukan\n";
    } else {
        status[idx] = 2;   // tandai dihapus agar pencarian tidak terputus
        cout << "Data " << nim << " dihapus dari indeks " << idx << endl;
    }
}

void display() {
    for (int i = 0; i < SIZE; i++) {
        cout << "[" << i << "] ";
        if (status[i] == 1) cout << keys[i] << " - " << values[i];
        else if (status[i] == 2) cout << "(dihapus)";
        else cout << "-";
        cout << endl;
    }
}

void isiDataUji() {
    int nim[15] = {2024001, 2024002, 2024003, 2024021, 2024041, 2024004, 2024005, 2024006,
                   2024025, 2024007, 2024008, 2024009, 2024010, 2024011, 2024012};
    string nama[15] = {"Andi", "Budi", "Citra", "Dewi", "Eka", "Fajar", "Gita", "Hana",
                       "Indra", "Joko", "Kiki", "Lina", "Maya", "Nando", "Oka"};
    for (int i = 0; i < 15; i++) insertData(nim[i], nama[i]);
}

int main() {
    for (int i = 0; i < SIZE; i++) status[i] = 0;

    int pilih, nim;
    string nama;
    do {
        cout << "\n=== HASH TABLE MAHASISWA ===\n";
        cout << "1. Insert\n2. Search\n3. Remove\n4. Display\n5. Isi 15 data uji\n0. Keluar\nPilih: ";
        cin >> pilih;

        if (pilih == 1) {
            cout << "NIM: "; cin >> nim;
            cout << "Nama: "; cin >> nama;
            insertData(nim, nama);
        } else if (pilih == 2) {
            cout << "NIM: "; cin >> nim;
            searchData(nim);
        } else if (pilih == 3) {
            cout << "NIM: "; cin >> nim;
            removeData(nim);
        } else if (pilih == 4) {
            display();
        } else if (pilih == 5) {
            isiDataUji();
        }
    } while (pilih != 0);

    return 0;
}
