#include "listsirkuler.h"
#include <stdio.h>
#include <stdlib.h>

/****************** TEST LIST KOSONG ******************/
boolean IsEmpty(List L) {
    return (First(L) == Nil);
}

/****************** PEMBUATAN LIST KOSONG ******************/
void CreateEmpty(List *L) {
    First(*L) = Nil;
}

/****************** Manajemen Memori ******************/
address Alokasi(infotype X) {
    address P = (address)malloc(sizeof(ElmtList));
    if (P != Nil) {
        Info(P) = X;
        Next(P) = Nil;
    }
    return P;
}

void Dealokasi(address P) {
    free(P);
}

/****************** PENCARIAN SEBUAH ELEMEN LIST ******************/
address Search(List L, infotype X) {
    if (IsEmpty(L)) {
        return Nil;
    }
    address P = First(L);
    do {
        if (Info(P) == X) {
            return P;
        }
        P = Next(P);
    } while (P != First(L));
    return Nil;
}

/****************** PRIMITIF BERDASARKAN NILAI ******************/
void InsVFirst(List *L, infotype X) {
    address P = Alokasi(X);
    if (P != Nil) {
        if (IsEmpty(*L)) {
            First(*L) = P;
            Next(P) = P;
        } else {
            address last = First(*L);
            while (Next(last) != First(*L)) {
                last = Next(last);
            }
            Next(P) = First(*L);
            First(*L) = P;
            Next(last) = First(*L);
        }
    }
}

void InsVLast(List *L, infotype X) {
    address P = Alokasi(X);

    if (P != Nil) {
        if (IsEmpty(*L)) {
            First(*L) = P;
            Next(P) = P; 
        } else {
            address last = First(*L);
            while (Next(last) != First(*L)) { 
                last = Next(last);
            }
            Next(last) = P;
            Next(P) = First(*L);
        }
    }
}

void DelVFirst(List *L, infotype *X) {
    address P = First(*L);

    *X = Info(P);
    if (Next(P) == P) { 
        First(*L) = Nil;
    } else {
        address last = First(*L);
        while (Next(last) != First(*L)) { 
            last = Next(last);
        }
        First(*L) = Next(P);
        Next(last) = First(*L);
    }
    Dealokasi(P);
}

void DelVLast(List *L, infotype *X) {
    if (!IsEmpty(*L)) {
        address last = First(*L), PrecLast = Nil;

        while (Next(last) != First(*L)) {
            PrecLast = last;
            last = Next(last);
        }

        *X = Info(last);

        if (PrecLast == Nil) { 
            First(*L) = Nil;
        } else {
            Next(PrecLast) = First(*L);
        }
        
        Dealokasi(last);
    }
}

/****************** PRIMITIF BERDASARKAN ALAMAT ******************/
void InsertFirst(List *L, address P) {
    if (IsEmpty(*L)) {
        First(*L) = P;
        Next(P) = P;
    } else {
        address Last = First(*L);
        while (Next(Last) != First(*L)) {
            Last = Next(Last);
        }
        Next(P) = First(*L);
        Next(Last) = P;
        First(*L) = P;
    }
}

void InsertLast(List *L, address P) {
    if (IsEmpty(*L)) {
        First(*L) = P;
        Next(P) = P; 
    } else {
        address Last = First(*L);

        while (Next(Last) != First(*L)) {
            Last = Next(Last);
        }
        Next(Last) = P;
        Next(P) = First(*L);
    }
}

void InsertAfter(List *L, address P, address Prec) {
    if (Prec != Nil) {
        Next(P) = Next(Prec);
        Next(Prec) = P;
    }
}

void DelFirst(List *L, address *P) {
    if (!IsEmpty(*L)) {
        *P = First(*L);
        address Last = First(*L);
        while (Next(Last) != First(*L)) {
            Last = Next(Last);
        }

        if (Next(*P) == First(*L)) { // List hanya memiliki 1 elemen
            First(*L) = Nil;
        } else {
            First(*L) = Next(*P);
            Next(Last) = First(*L);
        }
    }
}

void DelLast(List *L, address *P) {
    if (!IsEmpty(*L)) {
        address Last = First(*L);
        address PrecLast = Nil;

        while (Next(Last) != First(*L)) {
            PrecLast = Last;
            Last = Next(Last);
        }

        *P = Last;

        if (PrecLast == Nil) { 
            First(*L) = Nil;
        } else {
            Next(PrecLast) = First(*L);
        }
    }
}

void DelAfter(List *L, address *Pdel, address Prec) {
    if (Prec != Nil && Next(Prec) != Nil) {
        *Pdel = Next(Prec);
        Next(Prec) = Next(*Pdel);
        Next(*Pdel) = Nil;
    }
}

void DelP(List *L, infotype X) {
    if (!IsEmpty(*L)) {
        address P = First(*L), Prec = Nil;
        address Org = First(*L);
        boolean Con = false;

        do {
            if (Info(P) == X) {
                Con = true;
                break;
            }
            Prec = P;
            P = Next(P);
        } while (P != Org);

        if (Con) {
            if (Prec == Nil) {
                address last = First(*L);
                while (Next(last) != First(*L)) {
                    last = Next(last);
                }

                if (last == P) {
                    First(*L) = Nil;
                } else {
                    First(*L) = Next(P);
                    Next(last) = First(*L);
                }
            } else {
                Next(Prec) = Next(P);
            }
            Dealokasi(P);
        }
    }
}

/****************** PROSES SEMUA ELEMEN LIST ******************/
void PrintInfo(List L) {
    printf("[");
    if (!IsEmpty(L)) {
        address P = First(L);
        do {
            printf("%d", Info(P));
            P = Next(P);
            if (P != First(L)) {
                printf(",");
            }
        } while (P != First(L));
    }
    printf("]");
}
