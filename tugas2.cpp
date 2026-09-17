#include <iostream>
using namespace std;

struct Node{
    int data;
    Node *next;
};

int main(){
    system("cls");

    // membuat 10 node data nilai mahasiswa
    Node* node1 = new Node();  node1->data = 100; node1->next = nullptr;
    Node* node2 = new Node();  node2->data = 92;  node2->next = nullptr;
    Node* node3 = new Node();  node3->data = 45;  node3->next = nullptr;
    Node* node4 = new Node();  node4->data = 87;  node4->next = nullptr;
    Node* node5 = new Node();  node5->data = 71;  node5->next = nullptr;
    Node* node6 = new Node();  node6->data = 99;  node6->next = nullptr;
    Node* node7 = new Node();  node7->data = 95;  node7->next = nullptr;
    Node* node8 = new Node();  node8->data = 60;  node8->next = nullptr;
    Node* node9 = new Node();  node9->data = 55;  node9->next = nullptr;
    Node* node10 = new Node(); node10->data = 88; node10->next = nullptr;

    // menghubungkan setiap node
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;
    node5->next = node6;
    node6->next = node7;
    node7->next = node8;
    node8->next = node9;
    node9->next = node10;

    // menentukan head dan tail
    Node* head = node1;
    Node* tail = node10;

    Node* temp = head;
    cout << "Data awal: ";
    while (temp != nullptr){
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;

    //  tambahkan 70 di depan 
    Node* nodeBaru1 = new Node();
    nodeBaru1->data = 70;
    nodeBaru1->next = head;

    head = nodeBaru1;

    temp = head;
    cout << "Setelah tambah 70 di depan: ";
    while (temp != nullptr){
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;

    //  tambahkan 50 di belakang 
    Node* nodeBaru2 = new Node();
    nodeBaru2->data = 50;
    nodeBaru2->next = nullptr;

    tail->next = nodeBaru2;
    tail = nodeBaru2;

    temp = head;
    cout << "Setelah tambah 50 di belakang: ";
    while (temp != nullptr){
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;

    //  tambahkan 0 setelah nilai 45 
    temp = head;
    while (temp->data != 45){
        temp = temp->next;
    }

    Node* nodeBaru3 = new Node();
    nodeBaru3->data = 0;
    nodeBaru3->next = temp->next;

    temp->next = nodeBaru3;

    temp = head;
    cout << "Setelah tambah 0 setelah 45: ";
    while (temp != nullptr){
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;

    //  hapus nilai 99 
    temp = head;
    while (temp->next->data != 99){
        temp = temp->next;
    }

    Node* hapus1 = temp->next;
    temp->next = hapus1->next;
    delete hapus1;

    temp = head;
    cout << "Setelah hapus 99: ";
    while (temp != nullptr){
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;

    //  hapus nilai 60 
    temp = head;
    while (temp->next->data != 60){
        temp = temp->next;
    }

    Node* hapus2 = temp->next;
    temp->next = hapus2->next;
    delete hapus2;

    temp = head;
    cout << "Setelah hapus 60: ";
    while (temp != nullptr){
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;

    return 0;
}