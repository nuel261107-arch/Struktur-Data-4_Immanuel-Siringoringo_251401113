#include <iostream>
using namespace std;

    //Linear Search
    int linearsearch (int data[], int n, int key) {
        for (int i = 0; i < n; i++) {
            if (data[i] == key) {
                return i;
            }
        }
        return -1;
    }

int main() {
    system("cls");
    int data[] = {70, 49, 0, 7, 5, 10, 23, 21, 28, 45};
    int n = 10;
    int key = 49;

    int hasil=linearsearch(data, n, key);
    if (hasil == -1) {
        cout << "Data tidak ditemukan" << endl;
    } else {
        cout << "Data ditemukan pada indeks ke-" << hasil << endl;
    }
    return 0;
}