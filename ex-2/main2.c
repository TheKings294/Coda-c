#include <stdio.h>
#include <stdlib.h>

int main(int argc, const char * argv[]) {
    char opperation;
    
    printf("Choisis une operation parmis les toutes : \n");
    scanf("%c", &opperation);
    
    switch (opperation) {
        case '+':
            printf("Vous avez choisis l'opération +\n");
            break;
        case '-':
            printf("Vous avez choisis l'opération -\n");
            break;
        case '*':
            printf("Vous avez choisis l'opération *\n");
            break;
        case '/':
            printf("Vous avez choisis l'opération /\n");
            break;
        case '%':
            printf("Vous avez choisis l'opération modulo\n");
            break;
            
        default:
            printf("L'opération n'existe pas\n");
            break;
    }
}
