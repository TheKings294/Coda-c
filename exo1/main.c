#include <stdlib.h>
#include <stdio.h>
#include "struct.h"

int main()
{
    character monPersonnage;

    monPersonnage.agility = 10;
    monPersonnage.endurance = 20;
    monPersonnage.intelligence = 200;
    monPersonnage.strength = 50;
    monPersonnage.wisdom = 0;

    printf("Mon personnage a %d en agility, %d en endurance, %d en inteligence, %d en force et %d en sagesse", monPersonnage.agility, monPersonnage.endurance, monPersonnage.intelligence, monPersonnage.strength, monPersonnage.wisdom);
}