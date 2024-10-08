#include <stdio.h>

int main(int argc, const char * argv[]) {
    
    char prenom[100];
    int age;
    
    printf("Quel est votre prenom\n");
    scanf("%s",prenom);
    
    printf("Quel est votre age\n");
    scanf("%d", &age);
    
    int annee = 2024 - age;
    int annee2 = annee + 1;
    printf("Vous etes de %d ou de %d\n", annee, annee2); 
}
