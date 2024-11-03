#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

// Fungsi untuk menambah data di akhir circular linked list
void tambahDiAkhir(struct Node** head_ref, int new_data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    struct Node* last = *head_ref;
    new_node->data = new_data;
    
    if (*head_ref == NULL) {
        *head_ref = new_node;
        new_node->next = new_node; // Menghubungkan node ke dirinya sendiri
        return;
    }

    // Mencari node terakhir yang menunjuk ke head
    while (last->next != *head_ref) {
        last = last->next;
    }

    last->next = new_node;
    new_node->next = *head_ref; // Menghubungkan node baru ke head
}

// Fungsi untuk menghapus data di awal circular linked list
void hapusDiAwal(struct Node** head_ref) {
    if (*head_ref == NULL) {
        printf("Circular Linked List kosong.\n");
        return;
    }

    struct Node* temp = *head_ref;
    struct Node* last = *head_ref;

    if (temp->next == *head_ref) {
        *head_ref = NULL; // Hanya satu node, hapus node tersebut
        free(temp);
        return;
    }

    // Mencari node terakhir yang menunjuk ke head
    while (last->next != *head_ref) {
        last = last->next;
    }

    *head_ref = temp->next;
    last->next = *head_ref; // Update node terakhir agar menunjuk ke node baru pertama
    free(temp);
}

// Fungsi untuk menghapus data di tengah circular linked list
void hapusDiTengah(struct Node** head_ref, int posisi) {
    if (*head_ref == NULL) {
        printf("Circular Linked List kosong.\n");
        return;
    }

    struct Node* temp = *head_ref;

    if (posisi == 0) {
        hapusDiAwal(head_ref);
        return;
    }

    for (int i = 0; i < posisi - 1 && temp->next != *head_ref; i++) {
        temp = temp->next;
    }

    if (temp->next == *head_ref) {
        printf("Posisi tidak valid.\n");
        return;
    }

    struct Node* next = temp->next->next;
    free(temp->next);
    temp->next = next;
}

// Fungsi untuk menghapus data di akhir circular linked list
void hapusDiAkhir(struct Node** head_ref) {
    if (*head_ref == NULL) {
        printf("Circular Linked List kosong.\n");
        return;
    }

    struct Node* temp = *head_ref;

    if (temp->next == *head_ref) {
        free(temp);
        *head_ref = NULL; // Hanya ada satu node
        return;
    }

    struct Node* prev = NULL;
    while (temp->next != *head_ref) {
        prev = temp;
        temp = temp->next;
    }

    prev->next = *head_ref; // Update node terakhir agar menunjuk ke head
    free(temp);
}

// Fungsi untuk mencari data di circular linked list
int cariData(struct Node* head, int key) {
    if (head == NULL) return -1;

    struct Node* current = head;
    int posisi = 0;

    do {
        if (current->data == key)
            return posisi;
        current = current->next;
        posisi++;
    } while (current != head);

    return -1; // Jika data tidak ditemukan
}

// Fungsi untuk menghitung jumlah data di circular linked list
int hitungData(struct Node* head) {
    if (head == NULL) return 0;

    int count = 0;
    struct Node* current = head;

    do {
        count++;
        current = current->next;
    } while (current != head);

    return count;
}

// Fungsi untuk menjumlahkan semua data di circular linked list
int jumlahkanSemuaData(struct Node* head) {
    if (head == NULL) return 0;

    int total = 0;
    struct Node* current = head;

    do {
        total += current->data;
        current = current->next;
    } while (current != head);

    return total;
}

// Fungsi untuk menampilkan isi circular linked list
void tampilkan(struct Node* head) {
    if (head == NULL) {
        printf("Circular Linked List kosong.\n");
        return;
    }

    struct Node* temp = head;
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);

    printf("(kembali ke awal)\n");
}

int main() {
    struct Node* head = NULL;

    // Menambah data di akhir
    tambahDiAkhir(&head, 10);
    tambahDiAkhir(&head, 20);
    tambahDiAkhir(&head, 30);
    tambahDiAkhir(&head, 40);

    printf("Circular linked list setelah penambahan data: ");
    tampilkan(head);

    // Menghapus data di awal
    hapusDiAwal(&head);
    printf("Circular linked list setelah menghapus data di awal: ");
    tampilkan(head);

    // Menghapus data di tengah
    hapusDiTengah(&head, 1);
    printf("Circular linked list setelah menghapus data di tengah (posisi 1): ");
    tampilkan(head);

    // Menghapus data di akhir
    hapusDiAkhir(&head);
    printf("Circular linked list setelah menghapus data di akhir: ");
    tampilkan(head);

    // Mencari data dalam circular linked list
    int cari = 20;
    int posisi = cariData(head, cari);
    if (posisi != -1)
        printf("Data %d ditemukan di posisi %d\n", cari, posisi);
    else
        printf("Data %d tidak ditemukan\n", cari);

    // Menampilkan jumlah data
    int jumlah = hitungData(head);
    printf("Jumlah data dalam circular linked list: %d\n", jumlah);

    // Menampilkan hasil penjumlahan semua data
    int total = jumlahkanSemuaData(head);
    printf("Jumlah semua data dalam circular linked list: %d\n", total);

    return 0;
}
