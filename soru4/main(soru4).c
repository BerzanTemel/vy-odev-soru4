#include <stdio.h>
#include <stdlib.h>

struct Dugum {
    int veri;
    struct Dugum* sonraki;
};

struct Kuyruk {
    struct Dugum* bas;
    struct Dugum* son;
};

struct Dugum* dugumOlustur(int veri) {
    struct Dugum* yeniDugum = (struct Dugum*)malloc(sizeof(struct Dugum));
    yeniDugum->veri = veri;
    yeniDugum->sonraki = NULL;
    return yeniDugum;
}

void ekle(struct Kuyruk* kuyruk, int veri) {
    struct Dugum* yeniDugum = dugumOlustur(veri);
    if (kuyruk->son == NULL) {
        kuyruk->bas = kuyruk->son = yeniDugum;
    } else {
        kuyruk->son->sonraki = yeniDugum;
        kuyruk->son = yeniDugum;
    }
    printf("%d kuyruga eklendi.\n", veri);
}

void cikar(struct Kuyruk* kuyruk) {
    if (kuyruk->bas == NULL) {
        printf("Kuyruk bos.\n");
    } else {
        struct Dugum* temp = kuyruk->bas;
        kuyruk->bas = kuyruk->bas->sonraki;
        if (kuyruk->bas == NULL) {
            kuyruk->son = NULL;
        }
        printf("%d kuyruktan cikarildi.\n", temp->veri);
        free(temp);
    }
}

void goruntule(struct Kuyruk* kuyruk) {
    if (kuyruk->bas == NULL) {
        printf("Kuyruk bos.\n");
    } else {
        struct Dugum* temp = kuyruk->bas;
        printf("Kuyruk: ");
        while (temp != NULL) {
            printf("%d ", temp->veri);
            temp = temp->sonraki;
        }
        printf("\n");
    }
}

int main() {
    struct Kuyruk* kuyruk = (struct Kuyruk*)malloc(sizeof(struct Kuyruk));
    kuyruk->bas = kuyruk->son = NULL;
    int secim, veri;

    while (1) {
        printf("1. Ekle\n");
        printf("2. Cikar\n");
        printf("3. Goruntule\n");
        printf("4. Cikis\n");
        printf("Seciminizi yapin: ");
        scanf("%d", &secim);

        switch (secim) {
            case 1:
                printf("Eklenecek elemani girin: ");
                scanf("%d", &veri);
                ekle(kuyruk, veri);
                break;
            case 2:
                cikar(kuyruk);
                break;
            case 3:
                goruntule(kuyruk);
                break;
            case 4:
                printf("Programdan cikiliyor.\n");
                exit(0);
            default:
                printf("Gecersiz secim.\n");
        }
    }

    return 0;
}
