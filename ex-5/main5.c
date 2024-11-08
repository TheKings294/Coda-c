#include <stdio.h>
#include <stdlib.h>

int main(int argc, const char * argv[]) {
    char symbole;
    int i = 0;
    int nb_user;
    int nb_null = 0;
    
    printf("Choisis entre + (Montant) ou - (descendant)");
    scanf("%c", &symbole);
    printf("Choisis un nombre aléatoire différant de 0");
    scanf("%d", &nb_user);
    
    if (symbole == '+'){
        while (i <= nb_user) {
            printf("%d\n", i);
            i++;
        }
    }else if (symbole == '-') {
        i = nb_user;
        while (i != 0) {
            printf("%d\n", i);
            i--;
        }
        printf("%d\n", nb_null);
    }else {
        printf("Frere c'est pas un symbole\n");
    }
}
