#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

// Fungsi untuk menambah data di akhir linked list
void tambahDiAkhir(struct Node** head_ref, int new_data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    struct Node* last = *head_ref;
    new_node->data = new_data;
    new_node->next = NULL;
    
    if (*head_ref == NULL) {
        *head_ref = new_node;
        return;
    }

    while (last->next != NULL) {
        last = last->next;
    }

    last->next = new_node;
}

// Fungsi untuk menghapus data di awal linked list
void hapusDiAwal(struct Node** head_ref) {
    if (*head_ref == NULL) {
        printf("Linked List kosong.\n");
        return;
    }

    struct Node* temp = *head_ref;
    *head_ref = (*head_ref)->next;
    free(temp);
}

// Fungsi untuk menghapus data di tengah linked list
void hapusDiTengah(struct Node** head_ref, int posisi) {
    if (*head_ref == NULL) {
        printf("Linked List kosong.\n");
        return;
    }

    struct Node* temp = *head_ref;

    if (posisi == 0) {
        *head_ref = temp->next;
        free(temp);
        return;
    }

    for (int i = 0; temp != NULL && i < posisi - 1; i++) {
        temp = temp->next;
    }

    if (temp == NULL || temp->next == NULL) {
        printf("Posisi tidak valid.\n");
        return;
    }

    struct Node* next = temp->next->next;
    free(temp->next);
    temp->next = next;
}

// Fungsi untuk menghapus data di akhir linked list
void hapusDiAkhir(struct Node** head_ref) {
    if (*head_ref == NULL) {
        printf("Linked List kosong.\n");
        return;
    }

    struct Node* temp = *head_ref;

    if (temp->next == NULL) {
        free(temp);
        *head_ref = NULL;
        return;
    }

    struct Node* prev = NULL;
    while (temp->next != NULL) {
        prev = temp;
        temp = temp->next;
    }

    prev->next = NULL;
    free(temp);
}

// Fungsi untuk mencari data di linked list
int cariData(struct Node* head, int key) {
    struct Node* current = head;
    int posisi = 0;

    while (current != NULL) {
        if (current->data == key)
            return posisi;
        current = current->next;
        posisi++;
    }

    return -1; // Jika data tidak ditemukan
}

// Fungsi untuk menampilkan jumlah data dalam linked list
int hitungData(struct Node* head) {
    int count = 0;
    struct Node* current = head;
    while (current != NULL) {
        count++;
        current = current->next;
    }
    return count;
}

// Fungsi untuk menampilkan hasil penjumlahan dari semua data di linked list
int jumlahkanSemuaData(struct Node* head) {
    int total = 0;
    struct Node* current = head;
    while (current != NULL) {
        total += current->data;
        current = current->next;
    }
    return total;
}

// Fungsi untuk menampilkan isi linked list
void tampilkan(struct Node* node) {
    while (node != NULL) {
        printf("%d -> ", node->data);
        node = node->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = NULL;

    // Menambah data di akhir
    tambahDiAkhir(&head, 10);
    tambahDiAkhir(&head, 20);
    tambahDiAkhir(&head, 30);
    tambahDiAkhir(&head, 40);

    printf("Linked list setelah penambahan data: ");
    tampilkan(head);

    // Menghapus data di awal
    hapusDiAwal(&head);
    printf("Linked list setelah menghapus data di awal: ");
    tampilkan(head);

    // Menghapus data di tengah
    hapusDiTengah(&head, 1);
    printf("Linked list setelah menghapus data di tengah (posisi 1): ");
    tampilkan(head);

    // Menghapus data di akhir
    hapusDiAkhir(&head);
    printf("Linked list setelah menghapus data di akhir: ");
    tampilkan(head);

    // Mencari data dalam linked list
    int cari = 20;
    int posisi = cariData(head, cari);
    if (posisi != -1)
        printf("Data %d ditemukan di posisi %d\n", cari, posisi);
    else
        printf("Data %d tidak ditemukan\n", cari);

    // Menampilkan jumlah data
    int jumlah = hitungData(head);
    printf("Jumlah data dalam linked list: %d\n", jumlah);

    // Menampilkan hasil penjumlahan semua data
    int total = jumlahkanSemuaData(head);
    printf("Jumlah semua data dalam linked list: %d\n", total);

    return 0;
}