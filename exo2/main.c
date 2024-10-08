#include <stdlib.h>
#include <stdio.h>
#include "struct.h"

void fell_struct(character *perso)
{
    perso->agility = 20;
    perso->endurance = 30;
    perso->intelligence = 50;
    perso->strength = 40;
    perso->wisdom = 10;
}

int main()
{
    character Monperso;
    fell_struct(&Monperso);

    printf("Mon personnage a %d en agility, %d en endurance, %d en inteligence, %d en force et %d en sagesse", Monperso.agility, Monperso.endurance, Monperso.intelligence, Monperso.strength, Monperso.wisdom);
}