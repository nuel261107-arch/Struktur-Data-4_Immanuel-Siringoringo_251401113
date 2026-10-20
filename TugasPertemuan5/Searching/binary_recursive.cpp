#include <iostream>
using namespace std;

int binarySearch(int data[], int low, int high, int target) {
    if (low > high) {
        return -1;
    }
    
    int mid = low + (high - low) / 2;

    if (data[mid] == target) {
        return mid;
    } else if (target < data[mid]) {
        return binarySearch (data, low, mid-1, target);
    } else {
        return binarySearch (data, mid+1, high, target);
    }
}

int main() {
    int data[] = {4, 8, 12, 16, 20, 24, 28};
    int n = 7;
    int target = 20;

    int hasil = binarySearch(data, 0, n-1, target);

    if (hasil != -1) {
        cout << "Data ditemukan pada indeks : " << hasil << endl;
    } else {
        cout << "Data tidak ditemukan" << endl;
    }

    return 0;
}