#include "OddEvenList.h"

void SortList(List *L) {
    if (!IsEmpty(*L)) {
        address P, Q;
        infotype temp;
        P = First(*L);

        while (P != Nil) {
            Q = Next(P);
            while (Q != Nil) {
                if (Info(P) > Info(Q)) {
                    // Tukar nilai elemen
                    temp = Info(P);
                    Info(P) = Info(Q);
                    Info(Q) = temp;
                }
                Q = Next(Q);
            }
            P = Next(P);
        }
    }
}

void OddEvenList(List L, List *Odd, List *Even){
    CreateEmpty(Odd);
    CreateEmpty(Even);
    address P = First(L);
    infotype x;

    while (P != Nil) {
        x = P->info;
        
        if (x % 2 == 0){
            InsVFirst(Even, x);
        } else {
            InsVFirst(Odd, x);
        }
        P = Next(P);
    }
    SortList(Even);
    SortList(Odd);
}