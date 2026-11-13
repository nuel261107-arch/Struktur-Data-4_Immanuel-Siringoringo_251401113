#include <iostream>
#include <string>
using namespace std;

struct Mahasiswa {
    string nim;
    string nama;
    int nilai;
    Mahasiswa* next;
};

Mahasiswa* head = NULL;
int* arrNilai = NULL;   
int jumlah = 0;
bool sudahUrut = false;

void tambahData(string nim, string nama, int nilai) {
    Mahasiswa* baru = new Mahasiswa;
    baru->nim = nim;
    baru->nama = nama;
    baru->nilai = nilai;
    baru->next = NULL;

    if (head == NULL) {
        head = baru;
    } else {
        Mahasiswa* temp = head;
        while (temp->next != NULL) temp = temp->next;
        temp->next = baru;
    }
    jumlah++;
    sudahUrut = false;
}

void isiArray() {
    delete[] arrNilai;
    arrNilai = new int[jumlah];
    Mahasiswa* temp = head;
    int i = 0;
    while (temp != NULL) {
        arrNilai[i] = temp->nilai;
        i++;
        temp = temp->next;
    }
}

void insertionSort() {
    for (int i = 1; i < jumlah; i++) {
        int key = arrNilai[i];
        int j = i - 1;
        while (j >= 0 && arrNilai[j] > key) {
            arrNilai[j + 1] = arrNilai[j];
            j--;
        }
        arrNilai[j + 1] = key;
    }
}

void tampilData() {
    if (head == NULL) {
        cout << "Data masih kosong\n";
        return;
    }
    Mahasiswa* temp = head;
    cout << "NIM\t\tNama\t\tNilai\n";
    while (temp != NULL) {
        cout << temp->nim << "\t" << temp->nama << "\t\t" << temp->nilai << endl;
        temp = temp->next;
    }
}

void tampilNilaiUrut() {
    cout << "Nilai terurut: ";
    for (int i = 0; i < jumlah; i++) cout << arrNilai[i] << " ";
    cout << endl;
}

void linearSearch(string nim) {
    Mahasiswa* temp = head;
    while (temp != NULL) {
        if (temp->nim == nim) {
            cout << "Ditemukan: " << temp->nama << ", nilai " << temp->nilai << endl;
            return;
        }
        temp = temp->next;
    }
    cout << "NIM tidak ditemukan\n";
}

void binarySearch(int cari) {
    int kiri = 0, kanan = jumlah - 1;
    while (kiri <= kanan) {
        int tengah = (kiri + kanan) / 2;
        if (arrNilai[tengah] == cari) {
            cout << "Nilai " << cari << " ditemukan di indeks " << tengah << endl;
            return;
        } else if (arrNilai[tengah] < cari) {
            kiri = tengah + 1;
        } else {
            kanan = tengah - 1;
        }
    }
    cout << "Nilai tidak ditemukan\n";
}

int main() {
    system("cls");
    int pilih;
    do {
        cout << "\n=== SISTEM NILAI MAHASISWA ===\n";
        cout << "1. Tambah data\n2. Tampilkan data\n3. Urutkan nilai (Insertion Sort)\n";
        cout << "4. Cari mahasiswa by NIM (Linear Search)\n5. Cari nilai (Binary Search)\n0. Keluar\nPilih: ";
        cin >> pilih;

        if (pilih == 1) {
            string nim, nama;
            int nilai;
            cout << "NIM: "; cin >> nim;
            cout << "Nama: "; cin >> nama;
            cout << "Nilai: "; cin >> nilai;
            tambahData(nim, nama, nilai);
        } else if (pilih == 2) {
            tampilData();
            if (sudahUrut) tampilNilaiUrut();
        } else if (pilih == 3) {
            if (jumlah == 0) {
                cout << "Data kosong\n";
            } else {
                isiArray();
                insertionSort();
                sudahUrut = true;
                tampilNilaiUrut();
            }
        } else if (pilih == 4) {
            string nim;
            cout << "NIM yang dicari: "; cin >> nim;
            linearSearch(nim);
        } else if (pilih == 5) {
            if (!sudahUrut) {
                cout << "Urutkan nilai dulu (menu 3)\n";
            } else {
                int cari;
                cout << "Nilai yang dicari: "; cin >> cari;
                binarySearch(cari);
            }
        }
    } while (pilih != 0);

    return 0;
}
