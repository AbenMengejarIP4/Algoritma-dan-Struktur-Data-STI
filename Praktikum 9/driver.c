#include <stdio.h>
#include "listlinier.h"
#include "oddevenlist.h"

int main() {
    List L, Odd, Even;

    // Inisialisasi list kosong
    CreateEmpty(&L);

    // Input elemen ke dalam list L
    InsVFirst(&L, 5);
    InsVFirst(&L, 4);
    InsVFirst(&L, 1);
    InsVFirst(&L, 3);
    InsVFirst(&L, 0);

    printf("List L: ");
    PrintInfo(L); // Output: [0,3,1,4,5]

    // Pisahkan elemen ganjil dan genap
    OddEvenList(L, &Odd, &Even);

    // Tampilkan hasil
    printf("List Odd: ");
    PrintInfo(Odd); // Output: [1,3,5]

    printf("List Even: ");
    PrintInfo(Even); // Output: [0,4]

    return 0;
}
