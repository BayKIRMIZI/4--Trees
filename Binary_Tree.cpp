#include <stdio.h>
#include <stdlib.h>

struct Dugum {
    int veri;
    struct Dugum *sol;
    struct Dugum *sag;
};

typedef struct Dugum dgm;
dgm *kok = NULL;

void dugumEkle(int i, dgm **n) {
    if(*n == NULL) {
        *n = (dgm*)malloc(sizeof(dgm));
        (*n)->sol = NULL;
        (*n)->sag = NULL;
        (*n)->veri = i;
    }
    else 
    if((*n)->veri == i)
        printf("\nBu deger zaten mevcut!");
    else
    if(i > (*n)->veri)
        dugumEkle(i, &((*n)->sag));
    else
        dugumEkle(i, &((*n)->sol));
    }

void dugumAra(int i, dgm *n) {
    if(n == NULL)
        printf("Bu deger agacta yer almiyor!\n\n");
    else
    if(n->veri == i)
        printf("Deger bulundu!\n\n");
    else
    if(i > n->veri)
        dugumAra(i, n->sag);
    else
        dugumAra(i, n->sol);
    }



int main(void) {
    int secim, deger;
    do {
        printf("1. Dugum Ekle");
        printf("\n2. Dugum Ara.");        
        printf("\n3. Cikis.");
        printf("\nSecim: ");
        scanf("%d", &secim);
        switch(secim) {
            case 1: printf("\nDeger girin: ");
                    scanf("%d", &deger);printf("\n");
                    dugumEkle(deger, &kok);
                    break;

            case 2: printf("\nAranacak degeri girin: ");
                    scanf("%d", &deger);printf("\n");
                    dugumAra(deger, kok);
                    break;

            case 3: exit(0);
            }
    } while(secim != '3');

    return 0;
}
