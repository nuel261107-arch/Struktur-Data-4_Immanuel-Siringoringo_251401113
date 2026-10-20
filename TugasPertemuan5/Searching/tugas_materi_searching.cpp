#include <iostream>
using namespace std;

int binarySearch(int arr[], int n, int target) {
    int kiri = 0;
    int kanan = n - 1;

    while (kiri <= kanan) {
        int tengah = kiri + (kanan - kiri) / 2;

        if (arr[tengah] == target) {
            return tengah;
        } else if (arr[tengah] < target) {
            kiri = tengah + 1;
        } else {
            kanan = tengah - 1;
        }
    }
    return -1;
}

int main() {
    system("cls");
    int n;
    cout << "Jumlah data: ";
    cin >> n;

    int nilai[100];
    cout << "Masukkan nilai (urut ascending):\n";
    for (int i = 0; i < n; i++) {
        cin >> nilai[i];
    }

    int target;
    cout << "Nilai yang ditarget: ";
    cin >> target;

    int hasil = binarySearch(nilai, n, target);

    if (hasil != -1) {
        cout << "Data ditemukan pada indeks " << hasil << endl;
    } else {
        cout << "Data tidak ditemukan" << endl;
    }

    return 0;
}