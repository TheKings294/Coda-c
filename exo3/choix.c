#include "exo3.h"

void choix(int a, int *b, number **list) {
    int number;
    switch (a) {
        case 1:
            printf("Quelle est le nombre que vous voulez ajouter\n");
        scanf("%d",&number);
        add_to_end(list, number);
        break;
        case 2:
            affichlist(list);
        break;
        case 3:
            *b = 1;
        break;
        break;
        case 4:
            system("clear");
        break;
        default:
            printf("Choix invalide\n");
        break;
    }
}