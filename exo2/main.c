#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char *GetFile(FILE *fp)
{
    char *Contenue;
    char Buffer[1000];

    Contenue = malloc(sizeof(char));
    Contenue[0] = '\0';

    while (fgets(Buffer, 1000, fp) != NULL)
    {
        Contenue = realloc(Contenue, (strlen(Buffer) * sizeof(char) + strlen(Contenue) * sizeof(char)));
        Contenue = strcat(Contenue, Buffer);
    }

    return Contenue;
}

int main()
{
    char *file_Content;
    FILE *fp = fopen("exo2.txt", "r+");

    if (fp == NULL)
    {
        printf("L'ouverture du fichier n'a pas réussi");
        return EXIT_FAILURE;
    }

    file_Content = GetFile(fp);

    printf("%s", file_Content);

    fclose(fp);
    FILE *fp1 = fopen("exo2.txt", "w+");

    if (fp1 == NULL)
    {
        printf("L'ouverture du fichier n'a pas réussi");
        return EXIT_FAILURE;
    }

    fprintf(fp1, "Frêre Jacques, frêre Jacques\nDormez-vous, dormez-vous ?");

    file_Content = GetFile(fp1);
    printf("%s", file_Content);
    fclose(fp1);

    free(file_Content);
    return 0;
}