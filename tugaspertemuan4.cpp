#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* kiri;
    Node* kanan;
};

// Membuat node baru
Node* buatNode(int nilai) {
    Node* baru = new Node;

    baru->data = nilai;
    baru->kiri = NULL;
    baru->kanan = NULL;

    return baru;
}

// Menambahkan data ke binary tree
Node* insert(Node* root, int nilai) {

    // Jika tree masih kosong
    if (root == NULL) {
        return buatNode(nilai);
    }

    // Jika lebih kecil, masuk ke kiri
    if (nilai < root->data) {
        root->kiri = insert(root->kiri, nilai);
    }

    // Jika lebih besar, masuk ke kanan
    else if (nilai > root->data) {
        root->kanan = insert(root->kanan, nilai);
    }

    return root;
}

// Pre-order: Root -> Kiri -> Kanan
void preorder(Node* root) {
    if (root != NULL) {
        cout << root->data << " ";
        preorder(root->kiri);
        preorder(root->kanan);
    }
}

// In-order: Kiri -> Root -> Kanan
void inorder(Node* root) {
    if (root != NULL) {
        inorder(root->kiri);
        cout << root->data << " ";
        inorder(root->kanan);
    }
}

// Post-order: Kiri -> Kanan -> Root
void postorder(Node* root) {
    if (root != NULL) {
        postorder(root->kiri);
        postorder(root->kanan);
        cout << root->data << " ";
    }
}

int main() {
    system("cls");
    Node* root = NULL;
    int angka;

    cout << "Masukkan angka (0 untuk berhenti):" << endl;

    while (true) {
        cout << "Input: ";
        cin >> angka;

        if (angka == 0) {
            break;
        }

        root = insert(root, angka);
    }

    cout << "\nHasil Traversal:" << endl;

    cout << "Pre-order  : ";
    preorder(root);

    cout << "\nIn-order   : ";
    inorder(root);

    cout << "\nPost-order : ";
    postorder(root);

    cout << endl;

    return 0;
}