# Tugas Struktur Data & Algoritma (C++)

Kumpulan empat program C++ berbasis menu (console) yang mengimplementasikan berbagai struktur data dan algoritma: **Linked List, Sorting, Searching, Queue, Stack, Binary Search Tree, Graph, dan Hash Table**.

## Daftar Isi

- [Struktur Folder](#struktur-folder)
- [Deskripsi Program](#deskripsi-program)
  - [Soal 1 - Sistem Nilai Mahasiswa](#soal-1---sistem-nilai-mahasiswa)
  - [Soal 2 - Sistem Perpustakaan](#soal-2---sistem-perpustakaan)
  - [Soal 3 - Rute Kampus](#soal-3---rute-kampus)
  - [Soal 4 - Hash Table Mahasiswa](#soal-4---hash-table-mahasiswa)
- [Cara Menjalankan](#cara-menjalankan)
- [Catatan Penggunaan](#catatan-penggunaan)

---

## Struktur Folder

```
.
├── soal1_nilai_mahasiswa.cpp   # Linked List, Insertion Sort, Linear & Binary Search
├── soal2_perpustakaan.cpp      # Queue, Stack, Binary Search Tree
├── soal3_rute_kampus.cpp       # Graph: Adjacency Matrix, BFS, DFS, Dijkstra
├── soal4_hash_table.cpp        # Hash Table dengan Double Hashing
└── README.md
```

---

## Deskripsi Program

### Soal 1 - Sistem Nilai Mahasiswa

**File:** `soal1_nilai_mahasiswa.cpp`

Program untuk mengelola data mahasiswa (NIM, nama, nilai) menggunakan **Single Linked List**. Nilai-nilai mahasiswa dapat disalin ke array dinamis, diurutkan, lalu dicari menggunakan binary search.

**Struktur data & algoritma:**

| Komponen | Kegunaan |
|---|---|
| Single Linked List | Menyimpan data mahasiswa (`nim`, `nama`, `nilai`); data baru ditambahkan di akhir list |
| Array dinamis | Menampung salinan nilai dari linked list untuk diurutkan |
| Insertion Sort | Mengurutkan nilai secara ascending |
| Linear Search | Mencari mahasiswa berdasarkan NIM pada linked list |
| Binary Search | Mencari nilai pada array yang sudah terurut |

**Menu:**

1. Tambah data
2. Tampilkan data (jika nilai sudah diurutkan, nilai terurut ikut ditampilkan)
3. Urutkan nilai (Insertion Sort)
4. Cari mahasiswa berdasarkan NIM (Linear Search)
5. Cari nilai (Binary Search), hanya bisa dilakukan setelah menu 3
0. Keluar

---

### Soal 2 - Sistem Perpustakaan

**File:** `soal2_perpustakaan.cpp`

Simulasi sistem perpustakaan sederhana yang menggabungkan tiga struktur data sekaligus.

**Struktur data:**

| Komponen | Prinsip | Kegunaan |
|---|---|---|
| Queue (array) | FIFO | Antrean mahasiswa yang ingin meminjam buku (kapasitas 100) |
| Stack (array) | LIFO | Riwayat pengembalian buku, ditampilkan dari yang terbaru (kapasitas 100) |
| Binary Search Tree | - | Menyimpan ID buku agar pencarian efisien; ID duplikat ditolak |

**Menu:**

1. Tambah buku (ID dimasukkan ke BST)
2. Masuk antrean peminjaman (`enqueue`)
3. Layani antrean (`dequeue`)
4. Kembalikan buku (`push` ke stack riwayat)
5. Tampilkan antrean
6. Tampilkan riwayat pengembalian
7. Cari ID buku di BST
8. Tampilkan BST dengan traversal **Pre-Order**, **In-Order**, dan **Post-Order**
0. Keluar

---

### Soal 3 - Rute Kampus

**File:** `soal3_rute_kampus.cpp`

Memodelkan lokasi-lokasi di kampus sebagai **graph berbobot tidak berarah** dengan 6 simpul (**A-F**), dengan bobot sisi berupa jarak. Graph disimpan dalam **adjacency matrix** dan sudah terisi otomatis saat program dijalankan.

**Sisi pada graph:**

| Sisi | Jarak | Sisi | Jarak |
|---|---|---|---|
| A - B | 4 | C - D | 8 |
| A - C | 2 | C - E | 6 |
| B - C | 1 | D - E | 2 |
| B - D | 5 | D - F | 4 |
| B - E | 3 | E - F | 3 |

**Algoritma:**

| Algoritma | Kegunaan |
|---|---|
| BFS (Breadth-First Search) | Penelusuran graph per level dengan bantuan queue |
| DFS (Depth-First Search) | Penelusuran graph secara mendalam dengan rekursi |
| Dijkstra | Mencari rute terpendek antara dua simpul beserta total jaraknya |

**Menu:**

1. Tampilkan adjacency matrix
2. BFS (input simpul awal)
3. DFS (input simpul awal)
4. Dijkstra (input simpul awal dan tujuan)
0. Keluar

---

### Soal 4 - Hash Table Mahasiswa

**File:** `soal4_hash_table.cpp`

Hash table berukuran 20 slot untuk menyimpan data mahasiswa (NIM sebagai key, nama sebagai value). Tabrakan (collision) diselesaikan dengan **open addressing menggunakan double hashing**.

**Rumus:**

```
h1(key) = key % 20
h2(key) = 19 - (key % 19)
indeks  = (h1(key) + i * h2(key)) % 20      i = 0, 1, 2, ...
```

**Fitur penting:**

- Setiap slot punya status: `0` kosong, `1` terisi, `2` sudah dihapus (*lazy deletion*), sehingga pencarian tidak terputus setelah ada data yang dihapus.
- Saat terjadi collision, program menampilkan indeks tujuan dan jumlah percobaan.
- Tersedia menu untuk mengisi **15 data uji** yang sengaja dibuat mengalami collision (misalnya NIM `2024001`, `2024021`, dan `2024041` yang sama-sama memiliki `h1 = 1`).

**Menu:**

1. Insert
2. Search
3. Remove
4. Display
5. Isi 15 data uji
0. Keluar

---

## Cara Menjalankan


### 1. Clone repository

```bash
git clone https://github.com/<username>/<nama-repository>.git
cd <nama-repository>
```

### 2. Compile

```bash
g++ soal1_nilai_mahasiswa.cpp -o soal1
g++ soal2_perpustakaan.cpp    -o soal2
g++ soal3_rute_kampus.cpp     -o soal3
g++ soal4_hash_table.cpp      -o soal4
```

### 3. Jalankan

**Windows (CMD / PowerShell):**

```bash
soal1.exe
soal2.exe
soal3.exe
soal4.exe
```

**Linux / macOS:**

```bash
./soal1
./soal2
./soal3
./soal4
```


---

## Catatan Penggunaan

- **Soal 1:** program memanggil `system("cls")` sehingga dirancang untuk **Windows**. Di Linux/macOS, ganti dengan `system("clear")` (dan tambahkan `#include <cstdlib>`) atau hapus baris tersebut. Input `nama` dibaca dengan `cin >>`, jadi tulis tanpa spasi (contoh: `Budi_Santoso`).
- **Soal 1:** pilih menu **3** terlebih dahulu sebelum memakai menu **5** (Binary Search). Setiap menambah data baru, status urut direset dan nilai perlu diurutkan ulang.
- **Soal 2:** nama mahasiswa juga dibaca dengan `cin >>`, jadi tanpa spasi. Antrean bersifat linear (bukan circular), sehingga total `enqueue` dibatasi 100 kali.
- **Soal 3:** input simpul harus berupa **huruf kapital A-F**.
- **Soal 4:** gunakan menu **5** untuk mengisi data uji, lalu menu **4** untuk melihat hasil penempatan dan collision. Jalankan menu 5 sekali saja agar data uji tidak terdeteksi sebagai duplikat.

---

## Link Youtube

https://youtu.be/9piNhbsQBDM
