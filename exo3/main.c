#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main()
{
    FILE *fp = fopen("exo3.txt", "r+");
    char **lines;
    int j = 0;

    if (fp == NULL)
    {
        printf("L'ouverture du fichier n'a pas réussi");
        return EXIT_FAILURE;
    }

    lines = malloc(5 * sizeof(char));

    for (int i = 0; i < 5; i++)
    {
        lines[i] = malloc(50 * sizeof(char));
    }

    while (j < 5 && fgets(lines[j], 50, fp))
    {
        j++;
    }

    for (int i = 0; i < 4; i++)
    {
        printf("%s", lines[i]);
        free(lines[i]);
    }

    free(lines);
    return 0;
}