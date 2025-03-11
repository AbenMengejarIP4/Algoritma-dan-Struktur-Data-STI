#include <stdio.h>
#include "listlinier.h"

int main(){
    List L, Copy;
    address P;
    infotype x;

    CreateEmpty(&L);
    CreateEmpty(&Copy);

    scanf("%d", &x);
    
    while (x >= 0 && x <= 100){
        InsVFirst(&L, x);
        scanf("%d", &x);  
    }

    if (IsEmpty(L)){
        printf("Daftar nilai kosong\n");
    } else {
        printf("%d\n", NbElmt(L));
        printf("%d\n", Max(L));
        printf("%d\n", Min(L));
        printf("%0.2f\n", Average(L));

        
        P = First(L);
        while (P != Nil) {
            InsVLast(&Copy, Info(P));
            P = Next(P);
        }
        InversList(&Copy);
        PrintInfo(Copy);
        printf("\n");
        PrintInfo(L);
        printf("\n");

        return 0;
    }
}