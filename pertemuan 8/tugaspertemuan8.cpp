#include <iostream>
#include <vector>
#include <string>
using namespace std;

const int TABLE_SIZE = 10;

class HashTable {
private:
    vector<pair<long long, string>> table;
    vector<int> status;

    int hash1(long long key) {
        return key % TABLE_SIZE;
    }

    int hash2(long long key) {
        return 7 - (key % 7);
    }

public:
    HashTable() {
        table.resize(TABLE_SIZE);
        status.resize(TABLE_SIZE, 0);
    }

    void insert(long long key, string value) {
        int index = hash1(key);
        int step = hash2(key);
        int initialIndex = index;
        int deletedIndex = -1;

        while (true) {
            if (status[index] == 1 && table[index].first == key) {
                table[index].second = value; 
                cout << "NIM " << key << " diperbarui" << endl;
                return;
            }

            if (status[index] == 2 && deletedIndex == -1) {
                deletedIndex = index;
            }

            if (status[index] == 0) {
                if (deletedIndex != -1) {
                    index = deletedIndex;
                }
                table[index] = make_pair(key, value);
                status[index] = 1;
                cout << "Insert " << key << " (" << value << ") di index " << index << endl;
                return;
            }

            index = (index + step) % TABLE_SIZE;

            if (index == initialIndex) {
                break;
            }
        }

        if (deletedIndex != -1) {
            table[deletedIndex] = make_pair(key, value);
            status[deletedIndex] = 1;
            cout << "Insert " << key << " (" << value << ") di index " << deletedIndex << endl;
        } else {
            cout << "Tabel penuh, gagal insert " << key << endl;
        }
    }

    void search(long long key) {
        int index = hash1(key);
        int step = hash2(key);
        int initialIndex = index;

        while (status[index] != 0) {
            if (status[index] == 1 && table[index].first == key) {
                cout << "Data ditemukan di index " << index << " : " << table[index].second << endl;
                return;
            }

            index = (index + step) % TABLE_SIZE;

            if (index == initialIndex) {
                break;
            }
        }

        cout << "Data dengan NIM " << key << " tidak ditemukan" << endl;
    }

    void remove(long long key) {
        int index = hash1(key);
        int step = hash2(key);
        int initialIndex = index;

        while (status[index] != 0) {
            if (status[index] == 1 && table[index].first == key) {
                status[index] = 2;
                cout << "Data NIM " << key << " berhasil dihapus" << endl;
                return;
            }

            index = (index + step) % TABLE_SIZE;

            if (index == initialIndex) {
                break;
            }
        }

        cout << "Data dengan NIM " << key << " tidak ditemukan" << endl;
    }

    void display() {
        for (int i = 0; i < TABLE_SIZE; i++) {
            cout << i << " : ";

            if (status[i] == 1) {
                cout << table[i].first << " - " << table[i].second;
            } else if (status[i] == 2) {
                cout << "DELETED";
            } else {
                cout << "EMPTY";
            }

            cout << endl;
        }
    }
};

int main() {
    HashTable ht;

    cout << "=== INSERT ===" << endl;
    ht.insert(2023001, "Andi");
    ht.insert(2023011, "Budi");
    ht.insert(2023021, "Citra");
    ht.insert(2023005, "Dewi");
    ht.insert(2023015, "Eka");

    cout << "\n=== SEARCH ===" << endl;
    ht.search(2023011);
    ht.search(2023099);

    cout << "\n=== REMOVE ===" << endl;
    ht.remove(2023011);
    ht.remove(2023099);

    cout << "\n=== ISI HASH TABLE SETELAH SEMUA OPERASI ===" << endl;
    ht.display();

    return 0;
}
