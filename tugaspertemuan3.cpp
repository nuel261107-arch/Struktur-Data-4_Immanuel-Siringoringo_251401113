#include <iostream>
#include <string>
using namespace std;

int main() {
    system("cls");
    string nama;
    char stack[100];
    int top = -1;

    cout << "Masukkan nama: ";
    cin >> nama;

    for (int i = 0; i < nama.length(); i++) {
        top++;
        stack[top] = nama[i];
    }

    cout << "Nama setelah dibalik: ";

    while (top >= 0) {
        cout << stack[top];
        top--;
    }

    cout << endl;

    return 0;
}