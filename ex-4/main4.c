#include <stdio.h>
#include <stdlib.h>

int main(int argc, const char * argv[]) {
    int nb_choisis_user;
    int i = 0;
    
    printf("Choisis un nombre differant de 0");
    scanf("%d", &nb_choisis_user);
    
    while (i < nb_choisis_user){
        printf("%d\n", i);
        i++;
        
    }
    exit(0);
}
