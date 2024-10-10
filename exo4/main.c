#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "exo4.h"

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
    FILE *fp = fopen("exo4.txt", "r+");
    char **lines;
    char *file_Content;
    user UserData;
    char *token;

    if (fp == NULL)
    {
        printf("L'ouverture du fichier n'a pas réussi");
        return EXIT_FAILURE;
    }

    file_Content = GetFile(fp);

    UserData.first_name = malloc(100 * sizeof(char));
    UserData.last_name = malloc(100 * sizeof(char));
    UserData.age = malloc(100 * sizeof(char));

    token = strtok(file_Content, "\n");

    UserData.first_name = strcpy(UserData.first_name, token);
    token = strtok(NULL, "\n");
    UserData.last_name = strcpy(UserData.last_name, token);
    token = strtok(NULL, "\n");
    UserData.age = strcpy(UserData.age, token);

    printf("%s\n", UserData.first_name);
    printf("%s\n", UserData.last_name);
    printf("%s\n", UserData.age);

    free(UserData.first_name);
    free(UserData.last_name);
    free(UserData.age);
    free(file_Content);
    fclose(fp);
    return 0;
}