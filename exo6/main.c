#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "exo6.h"

int main()
{
    char *fp = fopen("exo6.txt", "r+");

    if (fp == NULL)
    {
        printf("L'ouverture du fichier n'a pas réussi");
        return EXIT_FAILURE;
    }

    movie titanic;
    titanic.title = "Titanic";
    titanic.director = "James Cameron";
    titanic.year = 1997;

    fprintf(fp, "%s\n", titanic.title);
    fprintf(fp, "%s\n", titanic.director);
    fprintf(fp, "%d\n", titanic.year);

    fclose(fp);
    return 0;
}