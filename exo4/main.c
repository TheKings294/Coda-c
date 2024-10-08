#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "struc.h"

int main()
{
    character *perso = malloc(sizeof(*perso));
    perso->name = malloc(strlen("Antoine") * sizeof(char));
    perso->name = strcpy(perso->name, "Antoine");

    perso->agility = 10;
    perso->endurance = 10;
    perso->intelligence = 20;
    perso->strength = 5;
    perso->wisdom = 15;

    printf("%s a %d en agility, %d en endurance, %d en inteligence, %d en force et %d en sagesse", perso->name, perso->agility, perso->endurance, perso->intelligence, perso->strength, perso->wisdom);

    free(perso); 
}
