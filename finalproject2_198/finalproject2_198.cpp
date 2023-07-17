#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    string namaProduk;
    int jumlahProduk;
    string tipeProduk;
    Node* next;

    Node(string nama, int jumlah, string tipe) {
        namaProduk = nama;
        jumlahProduk = jumlah;
        tipeProduk = tipe;
        next = NULL;
    }
};

class ManajemenProduk {
private:
    Node* head;

public:
    ManajemenProduk() {
        head = NULL;
    }

    void tambahProduk() {
        string nama;
        int jumlah;
        string tipe;

        cout << "========== TAMBAH PRODUK ==========" << endl;
        cout << "Nama Produk : ";
        getline(cin, nama);
        cout << "Jumlah Produk : ";
        cin >> jumlah;
        cin.ignore();
        cout << "Tipe Produk : ";
        getline(cin, tipe);

        Node* newNode = new Node(nama, jumlah, tipe);
        if (head == NULL) {
            head = newNode;
        }
        else {
            Node* current = head;
            while (current->next != NULL) {
                current = current->next;
            }
            current->next = newNode;
        }

        cout << "Produk berhasil ditambahkan!" << endl;
    }

    void tampilkanSemuaProduk() {
        cout << "========== SEMUA DATA PRODUK ==========" << endl;
        if (head == NULL) {
            cout << "Belum ada data produk yang tersimpan." << endl;
        }
        else {
            Node* current = head;
            while (current != NULL) {
                cout << "Nama Produk  : " << current->namaProduk << endl;
                cout << "Jumlah Produk: " << current->jumlahProduk << endl;
                cout << "Tipe Produk  : " << current->tipeProduk << endl;
                cout << "-------------------------" << endl;
                current = current->next;
            }
        }
    }

    void cariProdukByNama() {
        cout << "========== CARI PRODUK BERDASARKAN NAMA ==========" << endl;
        if (head == NULL) {
            cout << "Belum ada data produk yang tersimpan." << endl;
        }
        else {
            string targetNama;
            cout << "Nama Produk yang dicari: ";
            getline(cin, targetNama);

            Node* current = head;
            int posisi = 1;
            bool found = false;

            while (current != NULL) {
                if (current->namaProduk == targetNama) {
                    cout << "Produk ditemukan pada posisi ke-" << posisi << endl;
                    cout << "Nama Produk  : " << current->namaProduk << endl;
                    cout << "Jumlah Produk: " << current->jumlahProduk << endl;
                    cout << "Tipe Produk  : " << current->tipeProduk << endl;
                    found = true;
                    break;
                }
                current = current->next;
                posisi++;
            }

            if (!found) {
                cout << "Nama produk " << targetNama << " TIDAK DITEMUKAN" << endl;
            }
        }
    }

    void algoritmaSortByJumlahProduk() {
        if (head == NULL || head->next == NULL) {
            return; // Tidak perlu sorting jika hanya terdapat 0 atau 1 node
        }

        Node* current;
        Node* last = NULL;
        bool sorted = false;

        while (!sorted) {
            sorted = true;
            current = head;

            while (current->next != last) {
                if (current->jumlahProduk > current->next->jumlahProduk) {
                    // Tukar posisi node
                    string tempNama = current->namaProduk;
                    int tempJumlah = current->jumlahProduk;
                    string tempTipe = current->tipeProduk;

                    current->namaProduk = current->next->namaProduk;
                    current->jumlahProduk = current->next->jumlahProduk;
                    current->tipeProduk = current->next->tipeProduk;

                    current->next->namaProduk = tempNama;
                    current->next->jumlahProduk = tempJumlah;
                    current->next->tipeProduk = tempTipe;

                    sorted = false;
                }

                current = current->next;
            }

            last = current;
        }

        cout << "Produk berhasil diurutkan berdasarkan jumlah!" << endl;
    }
};

int main() {
    ManajemenProduk manajemenProduk;
    int pilihan;

    do {
        cout << "========== APLIKASI MANAJEMEN DATA PRODUK ==========" << endl;
        cout << "1. Tambah Produk" << endl;
        cout << "2. Tampilkan Semua Produk" << endl;
        cout << "3. Cari Produk berdasarkan Nama" << endl;
        cout << "4. Urutkan Produk berdasarkan Jumlah" << endl;
        cout << "5. Keluar" << endl;
        cout << "Pilihan: ";
        cin >> pilihan;
        cin.ignore();

        switch (pilihan) {
        case 1:
            manajemenProduk.tambahProduk();
            break;
        case 2:
            manajemenProduk.tampilkanSemuaProduk();
            break;
        case 3:
            manajemenProduk.cariProdukByNama();
            break;
        case 4:
            manajemenProduk.algoritmaSortByJumlahProduk();
            break;
        case 5:
            cout << "Terima kasih! Program selesai." << endl;
            break;
        default:
            cout << "Pilihan tidak valid. Silakan coba lagi." << endl;
        }

        cout << endl;

    } while (pilihan != 5);

    return 0;
}

// 2. linked list dan bubble sort
// 3. * buatlah array dengan ukuran tertentu sebagai wadah untuk menyimpan elemen-elemen dalam queue
//    * tentukan 2 pointer yaitu 'front' dan 'rear' diakhir queue
// 4. algoritma stack digunakan saat ingin mengimplementasikan operasi Last-in-first-out(LIFO)
// 5. a. struktur tersebut memiliki kedalaman 4
//    b. struktur tersebut menggunakan metode Preorder Traversal adalah 
//        * membaca nilai akar
//        * membaca semua node anak dari kiri ke kanan
//        * untuk setiap node anak ,ulangi langkah 1-2 secara rekursif