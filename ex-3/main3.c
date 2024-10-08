#include <stdio.h>
#include <stdlib.h>

int main(int argc, const char * argv[]) {
    char mot_a_affich[100];
    int i = 0;
    
    printf("Peut tu me donner un mot\n");
    scanf("%s", mot_a_affich);
    
    while (i < 5) {
        printf("%s\n", mot_a_affich);
        i++;
    }
    exit(0);
}
