#include <stdio.h>
#include <stdlib.h>

int main(int argc, const char * argv[]) {
    int choix_user;
    int nombre_de_base = 42;
    
    printf("Choisis un nombre sans auccune limite de taille :");
    scanf("%d", &choix_user);
    
    if (choix_user < nombre_de_base){
        printf("Votre nombre est inférieur a %d\n", nombre_de_base);
    }else if (choix_user == nombre_de_base) {
        printf("Le nombre est egale\n");
    }
    else {
        printf("votre nombre est plus grand que %d\n", nombre_de_base);
    }
    exit(0); 
}

