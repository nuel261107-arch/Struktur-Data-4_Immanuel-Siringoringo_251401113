#include <iostream>
#include <string>

using namespace std;

void masukkanNilai() {
    int data[5][4];
    // cout << "masukkan nilai : ";
    for (int i = 0; i < 5; i++){
        for(int j = 0; j < 4; j++){
            cin >> data [i][j];
            system("cls");
        }
    }
}

void tampilkanNilai() {
    int data[5][4];
    for (int i = 0; i < 5; i++){
        for (int j = 0; j < 4; j++){
            cout << data [i][j] << " ";
        }
        cout << endl;
    }
}

void rataNilai(){

}

int main(){
    int data [5][4];
    int i,j;
    int pilih;

    // cout << "masukkan nilai : ";
    // for (int i = 0; i < 5; i++){
    //     for(int j = 0; j < 4; j++){
    //         cin >> data [i][j];
    //         system("cls");
    //     }
    // }

    // for (int i = 0; i < 5; i++){
    //     for (int j = 0; j < 4; j++){
    //         cout << data [i][j] << " ";
    //     }
    //     cout << endl;
    // }

    // for (int i = 0; i++;){
    //     for (int j = 0; j < 4; j++){
    //         cout << "Rata rata 1" << j ;
    //     }
    //     cout << endl;
    // }

do{
    cout << "Opsi : \n 1.Masukkan Nilai \n 2.Tampilkan Nilai \n 3.Rata-Rata \n 0.Keluar" << endl;
    cout << ":";
    cin >> pilih;

    if (pilih == 1){
        int i, j;
        cout << "Masukkan Nilai : ";
        masukkanNilai();
    }else if(pilih == 2){
        tampilkanNilai();
    }else if(pilih ==3){
        rataNilai();
    }

}while (pilih != 0);

return 0;

}