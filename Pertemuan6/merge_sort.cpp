#include <iostream>
#include <vector>
using namespace std;

//fungsi untuk menggabungkan kelompok array
void merge (int data[], int left, int mid, int right) {
    vector<int> temp;
    int i = left;
    int j = mid + 1;

    //membandingkan angka dari kedua kelompok
    while (i <= mid && j <= right) {
        if (data[i] < data[j]) {
            temp.push_back(data[i]);
            i++;
        } else {
            temp.push_back(data[j]);
            j++;
        }
    }
    
    //memasukkan sisa angka di kiri
    while (i <= mid) {
        temp.push_back(data[i]);
        i++;
    }
    
    //memasukkan sisa angka di kanan
    while (j <= right) {
        temp.push_back(data[j]);
        j++;
    }
    
    for (int k = left; k <= right; k++) {
        data[k] = temp[k - left];
    }
}

//fungsi untuk memecah kelompok array
void mergeSort(int data[], int left, int right) {
    if (left >= right) {
        return;
    }
    
    int mid = (left + right) / 2;
    mergeSort(data, left, mid);
    mergeSort(data, mid + 1, right);

    merge(data, left, mid, right);
}

int main() {
    system("cls");
    int data[] = {5, 2, 4, 1, 3};
    int n = 5;

    mergeSort(data, 0, n - 1);

    cout << "Hasil Merge Sort: ";
    for (int i = 0; i < n; i++) {
        cout << data[i] << " ";
    }
    
    return 0;
}
