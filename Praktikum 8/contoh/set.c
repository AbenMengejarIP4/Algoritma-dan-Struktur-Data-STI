
#include <stdio.h>
#include "boolean.h"
#include "set.h"

/* MODUL Set
Deklarasi stack yang dengan implementasi array eksplisit-statik rata kiri
*/

/* Definisi Set S kosong : S.Count = Nil */
/* S.Count = jumlah element Set */
/* S.Elements = tempat penyimpanan element Set */

/* ********* Prototype ********* */

/* *** Konstruktor/Kreator *** */
void CreateEmpty(Set *S)
{
    /* I.S. Sembarang */
    /* F.S. Membuat sebuah Set S kosong berkapasitas MaxEl */
    /* Ciri Set kosong : count bernilai Nil */
    S->Count = Nil;
}
/* ********* Predikat Untuk test keadaan KOLEKSI ********* */
boolean IsEmpty(Set S)
{
    /* Mengirim true jika Set S kosong*/
    /* Ciri Set kosong : count bernilai Nil */
    return (S.Count == Nil);
}
boolean IsFull(Set S)
{
    /* Mengirim true jika Set S penuh */
    /* Ciri Set penuh : count bernilai MaxEl */
    return (S.Count == MaxEl);
}
/* ********** Operator Dasar Set ********* */
void Insert(Set *S, infotype Elmt)
{
    /* Menambahkan Elmt sebagai elemen Set S. */
    /* I.S. S mungkin kosong, S tidak penuh
            S mungkin sudah beranggotakan Elmt */
    /* F.S. Elmt menjadi anggota dari S. Jika Elmt sudah merupakan anggota, operasi tidak dilakukan */
    if (!IsFull(*S))
    {
        if (!IsMember(*S, Elmt)) 
        {
            S->Elements[S->Count] = Elmt;
            S->Count++;
        }
    }
}
void Delete(Set *S, infotype Elmt)
{
    /* Menghapus Elmt dari Set S. */
    /* I.S. S tidak kosong
            Elmt mungkin anggota / bukan anggota dari S */
    /* F.S. Elmt bukan anggota dari S */
int index = -1;
    for (int i=0 ; i< S->Count ; i++){
        if (Elmt == S->Elements[i]){
            index = i;
            break;
        }
    }
    if (index != -1){
        for (int j = index; j < S->Count - 1; j++) {
            S->Elements[j] = S->Elements[j + 1];
        }
        S->Count--;
    }
}
boolean IsMember(Set S, infotype Elmt)
{
    /* Mengembalikan true jika Elmt adalah member dari S */
    int i = 0;
    for (i = 0; i < S.Count; i++)
    {
        if (S.Elements[i] == Elmt)
        {
            return true;
        }
    }
    return false;
}
