#include <stdlib.h>
#include <stdio.h>
#include "struct.h"

int main()
{
    character *perso = malloc(sizeof(*perso));

    perso->agility = 10;
    perso->endurance = 10;
    perso->intelligence = 20;
    perso->strength = 5;
    perso->wisdom = 20;

    printf("Mon personnage a %d en agility, %d en endurance, %d en inteligence, %d en force et %d en sagesse", perso->agility, perso->endurance, perso->intelligence, perso->strength, perso->wisdom);

    free(perso);
}