#include <iostream>
#include <string>
#include <vector>
using namespace std;

void tampilkanKata(const vector<string>& kata) {
    int n = static_cast<int>(kata.size());
    for (int i = 0; i < n; i++) {
        cout << kata[i] << "  ";
    }
    cout << endl;
}

int main() {
    system("cls");
    int jumlah;
    cout << "Masukkan jumlah kata: ";
    if (!(cin >> jumlah) || jumlah <= 0) {
        cout << "Jumlah kata harus berupa bilangan bulat lebih dari 0.\n";
        return 1;
    }

    vector<string> kata(jumlah);
    cout << "Masukkan " << jumlah << " kata:\n";
    for (int i = 0; i < jumlah; i++) {
        cout << "Kata ke-" << i + 1 << ": ";
        cin >> kata[i];
    }
    
    cout << "\nData awal:  ";
    tampilkanKata(kata);
    cout << "\n";
    
    for (int i = 1; i < jumlah; i++) {
        string key = kata[i];
        int j = i - 1;
        
        cout << "Langkah " << i << ": Ambil \"" << key << "\"\n";
        
        while (j >= 0 && kata[j] > key) {
            cout << "  Geser \"" << kata[j] << "\" ke kanan\n";
            kata[j + 1] = kata[j];
            j--;
        }
        
        kata[j + 1] = key;
        cout << "  Taruh \"" << key << "\" di posisi " << (j + 2) << endl;
        cout << "  Hasil: ";
        tampilkanKata(kata);
        cout << endl;
    }
    
    cout << "Hasil akhir: ";
    tampilkanKata(kata);
    
    return 0;
}