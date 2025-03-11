#include <stdio.h>
#include "map.h"

int main() {
    Map M;
    CreateEmpty(&M);

    // Insert elemen
    Insert(&M, 1, 100);
    Insert(&M, 2, 200);
    Insert(&M, 3, 300);

    // Tampilkan nilai berdasarkan key
    printf("Value dengan key 2: %d\n", Value(M, 2)); // Output: 200

    // Cek anggota
    printf("Apakah key 3 ada? %s\n", IsMember(M, 3) ? "Ya" : "Tidak"); // Output: Ya

    // Hapus elemen
    Delete(&M, 2);

    // Tampilkan elemen setelah penghapusan
    printf("Value dengan key 2 setelah dihapus: %d\n", Value(M, 2)); // Output: Undefined
    printf("Apakah key 2 ada? %s\n", IsMember(M, 2) ? "Ya" : "Tidak"); // Output: Tidak

    return 0;
}
