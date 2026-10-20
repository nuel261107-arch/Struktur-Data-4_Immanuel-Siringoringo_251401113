#include <iostream>
using namespace std;

int interpolationSearch(int data[], int n, int target) {
    int low = 0;
    int high = n - 1;

    while (low <= high && target >= data[low] && target <= data[high]) {
        if (data[low] == data[high]) {
            if (data[low] == target) {
                return low; // 8
            }
            return -1;
        }

        int pos = low + (int)(
            (double)(target - data[low]) / (data[high] - data[low]) * (high - low)
        );

        if (data[pos] == target) {
            return pos;
        } else if (data[pos] < target) {
            low = pos + 1;
        } else {
            high = pos - 1;
        }
    }
    return -1;
}

int main() {
    int data[] = {3, 6, 9, 12, 15, 18, 21};
    int n = 7;
    int target = 15;

    int hasil = interpolationSearch(data, n, target);

    if (hasil != -1) {
        cout << "Data ditemukan pada indeks : " << hasil << endl;
    } else {
        cout << "Data tidak ditemukan" << endl;
    }

}