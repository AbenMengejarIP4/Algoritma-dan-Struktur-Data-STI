#include <stdio.h>
#include <stdlib.h>
#include "listlinier.h"

/****************** TEST LIST KOSONG ******************/
boolean IsEmpty(List L) {
    return First(L) == Nil;
}

/****************** PEMBUATAN LIST KOSONG ******************/
void CreateEmpty(List *L) {
    First(*L) = Nil;
}

/****************** Manajemen Memori ******************/
address Alokasi(infotype X) {
    address P = (address) malloc(sizeof(ElmtList));
    if (P != Nil) {
        Info(P) = X;
        Next(P) = Nil;
    }
    return P;
}

void Dealokasi(address *P) {
    free(*P);
    *P = Nil;
}

/****************** PENCARIAN SEBUAH ELEMEN LIST ******************/
address Search(List L, infotype X) {
    address P = First(L);
    while (P != Nil && Info(P) != X) {
        P = Next(P);
    }
    return P;
}

/****************** PRIMITIF BERDASARKAN NILAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void InsVFirst(List *L, infotype X) {
    address P = Alokasi(X);
    if (P != Nil) {
        Next(P) = First(*L);
        First(*L) = P;
    }
}

void InsVLast(List *L, infotype X) {
    address P = Alokasi(X);
    if (P != Nil) {
        if (IsEmpty(*L)) {
            First(*L) = P;
        } else {
            address Last = First(*L);
            while (Next(Last) != Nil) {
                Last = Next(Last);
            }
            Next(Last) = P;
        }
    }
}

/*** PENGHAPUSAN ELEMEN ***/
void DelVFirst(List *L, infotype *X) {
    address P = First(*L);
    *X = Info(P);
    First(*L) = Next(P);
    Dealokasi(&P);
}

void DelVLast(List *L, infotype *X) {
    address P = First(*L), Prec = Nil;
    while (Next(P) != Nil) {
        Prec = P;
        P = Next(P);
    }
    *X = Info(P);
    if (Prec == Nil) {
        First(*L) = Nil;
    } else {
        Next(Prec) = Nil;
    }
    Dealokasi(&P);
}

/****************** PRIMITIF BERDASARKAN ALAMAT ******************/
void InsertFirst(List *L, address P) {
    Next(P) = First(*L);
    First(*L) = P;
}

void InsertAfter(List *L, address P, address Prec) {
    Next(P) = Next(Prec);
    Next(Prec) = P;
}

void InsertLast(List *L, address P) {
    if (IsEmpty(*L)) {
        First(*L) = P;
    } else {
        address Last = First(*L);
        while (Next(Last) != Nil) {
            Last = Next(Last);
        }
        Next(Last) = P;
    }
}

/*** PENGHAPUSAN SEBUAH ELEMEN ***/
void DelFirst(List *L, address *P) {
    *P = First(*L);
    First(*L) = Next(*P);
    Next(*P) = Nil;
}

void DelP(List *L, infotype X) {
    address P = First(*L), Prec = Nil;
    while (P != Nil && Info(P) != X) {
        Prec = P;
        P = Next(P);
    }
    if (P != Nil) {
        if (Prec == Nil) {
            First(*L) = Next(P);
        } else {
            Next(Prec) = Next(P);
        }
        Dealokasi(&P);
    }
}

void DelLast(List *L, address *P) {
    address Prec = Nil;
    *P = First(*L);
    while (Next(*P) != Nil) {
        Prec = *P;
        *P = Next(*P);
    }
    if (Prec == Nil) {
        First(*L) = Nil;
    } else {
        Next(Prec) = Nil;
    }
}

void DelAfter(List *L, address *Pdel, address Prec) {
    *Pdel = Next(Prec);
    if (*Pdel != Nil) {
        Next(Prec) = Next(*Pdel);
        Next(*Pdel) = Nil;
    }
}

/****************** PROSES SEMUA ELEMEN LIST ******************/
void PrintInfo(List L) {
    address P = First(L);
    printf("[");
    while (P != Nil) {
        printf("%d", Info(P));
        P = Next(P);
        if (P != Nil) {
            printf(",");
        }
    }
    printf("]\n");
}

int NbElmt(List L) {
    int count = 0;
    address P = First(L);
    while (P != Nil) {
        count++;
        P = Next(P);
    }
    return count;
}

infotype Max(List L) {
    address P = First(L);
    infotype max = Info(P);
    while (P != Nil) {
        if (Info(P) > max) {
            max = Info(P);
        }
        P = Next(P);
    }
    return max;
}

address AdrMax(List L) {
    address P = First(L), maxAdr = P;
    infotype max = Info(P);
    while (P != Nil) {
        if (Info(P) > max) {
            max = Info(P);
            maxAdr = P;
        }
        P = Next(P);
    }
    return maxAdr;
}

infotype Min(List L) {
    address P = First(L);
    infotype min = Info(P);
    while (P != Nil) {
        if (Info(P) < min) {
            min = Info(P);
        }
        P = Next(P);
    }
    return min;
}

address AdrMin(List L) {
    address P = First(L), minAdr = P;
    infotype min = Info(P);
    while (P != Nil) {
        if (Info(P) < min) {
            min = Info(P);
            minAdr = P;
        }
        P = Next(P);
    }
    return minAdr;
}

float Average(List L) {
    int sum = 0, count = 0;
    address P = First(L);
    while (P != Nil) {
        sum += Info(P);
        count++;
        P = Next(P);
    }
    return (float)sum / count;
}

void InversList(List *L) {
    address P = First(*L), Prec = Nil, Succ;
    while (P != Nil) {
        Succ = Next(P);
        Next(P) = Prec;
        Prec = P;
        P = Succ;
    }
    First(*L) = Prec;
}

void Konkat1(List *L1, List *L2, List *L3) {
    CreateEmpty(L3);
    First(*L3) = First(*L1);
    if (!IsEmpty(*L1)) {
        address Last = First(*L1);
        while (Next(Last) != Nil) {
            Last = Next(Last);
        }
        Next(Last) = First(*L2);
    } else {
        First(*L3) = First(*L2);
    }
    CreateEmpty(L1);
    CreateEmpty(L2);
}
