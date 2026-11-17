#include <iostream>

using namespace std;

struct Node{
    int data;
    Node *next;
};

void addNode(){

}

void tampilNode(){

}

void hapusNode(){

}

void balikNode(){

}

int main(){
int pilih;
do{

    cout << "Opsi \n1.Masukkan Data \n2.Tampilkan Data \n3.Hapus Data \n4.Balik Data \n0.Keluar";
    cout << ":";
    if(pilih == 1){
        cout << "Masukkan Data : ";
        addNode();
    }else if(pilih == 2){
        cout << "Data : ";
        tampilNode();
    }else if (pilih == 3){
        cout << "Data yang ingin dihapus : ";
        hapusNode();
    }else if (pilih == 4){
        cout << "Node setelah dibalik : ";
        balikNode();
    }

  }while (pilih != 0);

  return 0;
  
}