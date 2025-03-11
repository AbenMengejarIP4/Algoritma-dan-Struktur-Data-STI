#include <stdio.h>
#include "set.h"

int main() {
    Set S;
    CreateEmpty(&S);

    printf("=== Testing Modul Set ===\n");

    // Tes kondisi awal
    printf("Set awal:\n");
    printf("Apakah kosong? %s\n", IsEmpty(S) ? "Ya" : "Tidak");

    // Menambahkan elemen ke dalam set
    printf("\nMenambahkan elemen ke dalam set...\n");
    Insert(&S, 10);
    Insert(&S, 20);
    Insert(&S, 30);

    printf("Set setelah menambahkan elemen: ");
    for (int i = 0; i < S.Count; i++) {
        printf("%d ", S.Elements[i]);
    }
    printf("\n");

    // Tes penambahan elemen yang sudah ada
    printf("\nMenambahkan elemen 20 (sudah ada)...\n");
    Insert(&S, 20);
    printf("Set setelah mencoba menambahkan elemen 20 lagi: ");
    for (int i = 0; i < S.Count; i++) {
        printf("%d ", S.Elements[i]);
    }
    printf("\n");

    // Menghapus elemen
    printf("\nMenghapus elemen 20 dari set...\n");
    Delete(&S, 20);
    printf("Set setelah menghapus elemen 20: ");
    for (int i = 0; i < S.Count; i++) {
        printf("%d ", S.Elements[i]);
    }
    printf("\n");

    // Tes apakah elemen ada di dalam set
    printf("\nApakah 10 anggota set? %s\n", IsMember(S, 10) ? "Ya" : "Tidak");
    printf("Apakah 20 anggota set? %s\n", IsMember(S, 20) ? "Ya" : "Tidak");

    // Tes kondisi penuh
    printf("\nMengisi set hingga penuh...\n");
    for (int i = S.Count; i < MaxEl; i++) {
        Insert(&S, i + 1); // Tambahkan elemen unik
    }
    printf("Apakah set penuh? %s\n", IsFull(S) ? "Ya" : "Tidak");

    // Coba menambahkan elemen ke set yang penuh
    printf("\nMenambahkan elemen ke set yang sudah penuh...\n");
    Insert(&S, 101);
    printf("Set setelah mencoba menambahkan elemen baru ke set penuh: ");
    for (int i = 0; i < S.Count; i++) {
        printf("%d ", S.Elements[i]);
    }
    printf("\n");

    printf("\n=== Selesai Testing ===\n");
    return 0;
}
