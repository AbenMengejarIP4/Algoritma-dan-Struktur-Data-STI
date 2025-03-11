#include "listdp.h"
#include <stdio.h>
#include <stdlib.h>

/****************** TEST LIST KOSONG ******************/
boolean IsEmpty(List L) {
    return (First(L) == Nil && Last(L) == Nil);
}

/****************** PEMBUATAN LIST KOSONG ******************/
void CreateEmpty(List *L) {
    First(*L) = Nil;
    Last(*L) = Nil;
}

/****************** Manajemen Memori ******************/
address Alokasi(infotype X) {
    address P = (address)malloc(sizeof(ElmtList));
    if (P != Nil) {
        Info(P) = X;
        Next(P) = Nil;
        Prev(P) = Nil;
    }
    return P;
}

void Dealokasi(address P) {
    free(P);
}

/****************** PENCARIAN SEBUAH ELEMEN LIST ******************/
address Search(List L, infotype X) {
    address P = First(L);
    while (P != Nil) {
        if (Info(P) == X) {
            return P;
        }
        P = Next(P);
    }
    return Nil;
}

/****************** PRIMITIF BERDASARKAN NILAI ******************/
void InsVFirst(List *L, infotype X) {
    address P = Alokasi(X);
    if (P != Nil) {
        InsertFirst(L, P);
    }
}

void InsVLast(List *L, infotype X) {
    address P = Alokasi(X);
    if (P != Nil) {
        InsertLast(L, P);
    }
}

void DelVFirst(List *L, infotype *X) {
    address P;
    DelFirst(L, &P);
    *X = Info(P);
    Dealokasi(P);
}

void DelVLast(List *L, infotype *X) {
    address P;
    DelLast(L, &P);
    *X = Info(P);
    Dealokasi(P);
}

/****************** PRIMITIF BERDASARKAN ALAMAT ******************/
void InsertFirst(List *L, address P) {
    if (IsEmpty(*L)) {
        First(*L) = P;
        Last(*L) = P;
    } else {
        Next(P) = First(*L);
        Prev(First(*L)) = P;
        First(*L) = P;
    }
}

void InsertLast(List *L, address P) {
    if (IsEmpty(*L)) {
        InsertFirst(L, P);
    } else {
        Prev(P) = Last(*L);
        Next(Last(*L)) = P;
        Last(*L) = P;
    }
}

void InsertAfter(List *L, address P, address Prec) {
    if (Prec != Nil) {
        Next(P) = Next(Prec);
        Prev(P) = Prec;
        if (Next(Prec) != Nil) {
            Prev(Next(Prec)) = P;
        } else {
            Last(*L) = P;
        }
        Next(Prec) = P;
    }
}

void InsertBefore(List *L, address P, address Succ) {
    if (Succ != Nil) {
        Prev(P) = Prev(Succ);
        Next(P) = Succ;
        if (Prev(Succ) != Nil) {
            Next(Prev(Succ)) = P;
        } else {
            First(*L) = P;
        }
        Prev(Succ) = P;
    }
}

void DelFirst(List *L, address *P) {
    *P = First(*L);
    if (Next(*P) == Nil) {
        First(*L) = Nil;
        Last(*L) = Nil;
    } else {
        First(*L) = Next(*P);
        Prev(First(*L)) = Nil;
    }
}

void DelLast(List *L, address *P) {
    *P = Last(*L);
    if (Prev(*P) == Nil) {
        First(*L) = Nil;
        Last(*L) = Nil;
    } else {
        Last(*L) = Prev(*P);
        Next(Last(*L)) = Nil;
    }
}

void DelP(List *L, infotype X) {
    address P = Search(*L, X);
    if (P != Nil) {
        if (P == First(*L)) {
            DelFirst(L, &P);
        } else if (P == Last(*L)) {
            DelLast(L, &P);
        } else {
            Next(Prev(P)) = Next(P);
            Prev(Next(P)) = Prev(P);
        }
        Dealokasi(P);
    }
}

void DelAfter(List *L, address *Pdel, address Prec) {
    *Pdel = Next(Prec);
    if (*Pdel != Nil) {
        Next(Prec) = Next(*Pdel);
        if (Next(*Pdel) != Nil) {
            Prev(Next(*Pdel)) = Prec;
        } else {
            Last(*L) = Prec;
        }
    }
}

void DelBefore(List *L, address *Pdel, address Succ) {
    *Pdel = Prev(Succ);
    if (*Pdel != Nil) {
        Prev(Succ) = Prev(*Pdel);
        if (Prev(*Pdel) != Nil) {
            Next(Prev(*Pdel)) = Succ;
        } else {
            First(*L) = Succ;
        }
    }
}

/****************** PROSES SEMUA ELEMEN LIST ******************/
void PrintForward(List L) {
    printf("[");
    address P = First(L);
    while (P != Nil) {
        printf("%d", Info(P));
        P = Next(P);
        if (P != Nil) {
            printf(",");
        }
    }
    printf("]\n");
}

void PrintBackward(List L) {
    printf("[");
    address P = Last(L);
    while (P != Nil) {
        printf("%d", Info(P));
        P = Prev(P);
        if (P != Nil) {
            printf(",");
        }
    }
    printf("]\n");
}
