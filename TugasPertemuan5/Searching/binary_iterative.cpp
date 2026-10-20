#include <iostream>
using namespace std;

int binarySearch(int data[], int n, int target) {
    int low = 0;
    int high = n-1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (data[mid] == target) {
            return mid;
        } else if (target < data[mid]) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    return -1;
}

int main() {
    int data[] = {4, 8, 12, 16, 20, 24, 28};
    int n = 7;
    int target = 20;

    int hasil = binarySearch(data, n, target);

    if (hasil != -1) {
        cout << "Data ditemukan pada indeks : " << hasil << endl;
    } else {
        cout << "Data tidak ditemukan" << endl;
    }

    return 0;
}