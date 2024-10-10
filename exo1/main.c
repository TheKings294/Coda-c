#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char *GetFile(FILE *fp)
{
    char *Contenue;
    char Buffer[100];

    Contenue = malloc(sizeof(char));
    Contenue[0] = '\0';

    while (fgets(Buffer, 100, fp) != NULL)
    {
        Contenue = realloc(Contenue, (strlen(Buffer) * sizeof(char) + strlen(Contenue) * sizeof(char)));
        Contenue = strcat(Contenue, Buffer);
    }

    return Contenue;
}

int main()
{
    char *file_Content;
    FILE *fp = fopen("exo1.txt", "r");

    if (fp == NULL)
    {
        printf("L'ouverture du fichier n'a pas réussi");
        return EXIT_FAILURE;
    }

    file_Content = GetFile(fp);

    printf("%s", file_Content);
    fclose(fp);

    free(file_Content);

    return 0;
}