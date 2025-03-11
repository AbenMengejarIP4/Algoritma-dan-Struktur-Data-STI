#include <stdio.h>
#include "listsirkuler.h"

int ElemenKeN(List L, int r) {
    address P = First(L);

    for(int i = 0; i < r; i++) {
        P = Next(P);
    }
    return Info(P);
}

int main () {
  List L;
  int r, input = 1;

  CreateEmpty(&L);
  while (input != 0){
    scanf("%d", &input);
    if (input != 0){
        InsVLast(&L, input);
    }
  }

  scanf("%d", &r);

  if (!IsEmpty(L)){
    printf("%d\n", ElemenKeN(L, r));
  } else {
    printf("List Kosong\n");
  }
  
  return 0;
}