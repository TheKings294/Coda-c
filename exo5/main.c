#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main()
{
    char **tab = malloc(3 * sizeof(*tab));
    tab[0] = "Goodnight\n";
    tab[1] = "And thanks !\n";
    tab[2] = "For all the fish!\n";

    char *fp = fopen("exo5.txt", "r+");

    fprintf(fp, "%s", tab[0]);
    fprintf(fp, "%s", tab[1]);
    fprintf(fp, "%s", tab[2]);

    free(tab);
    free(tab[0]);
    free(tab[1]);
    free(tab[2]);
    fclose(fp);
    return 0;
}