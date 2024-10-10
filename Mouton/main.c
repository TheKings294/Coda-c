#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main()
{
    FILE *fp = fopen("mouton.txt", "r+");

    fprintf(fp, "                                    @@@@@                                       \n");
    fprintf(fp, "                      @@@@@@     @#        *@@     @@@@@/    @   @@@.           \n");
    fprintf(fp, "                 @@@@@       @@@                     @                @         \n");
    fprintf(fp, "            @@@@.                                  .@                 @         \n");
    fprintf(fp, "          @                                         @@@@@@@@@@@@*@@@@           \n");
    fprintf(fp, "          @                                   #@@@@@@@@  @@     @@  @@@@@@@     \n");
    fprintf(fp, "        @@                                     @@@@  @  #@@     @@@  @@@@@@@    \n");
    fprintf(fp, "       @                                            @                @          \n");
    fprintf(fp, "       @                                            @                 @         \n");
    fprintf(fp, "      @@@                                           @                 @         \n");
    fprintf(fp, "   @@@@@                                            @                @          \n");
    fprintf(fp, "   @@@@(@                                            @    %%    @    %%@          \n");
    fprintf(fp, "         @@                                           @@    @     (@            \n");
    fprintf(fp, "           @                                               @@@@@                \n");
    fprintf(fp, "           @@                                                 @                 \n");
    fprintf(fp, "               @                                          @@                    \n");
    fprintf(fp, "                @(   @@@                                 @                      \n");
    fprintf(fp, "                   @   *@@               @      @@  @                           \n");
    fprintf(fp, "                   @   @  @  @   @@  @@@  @  @, @  @                            \n");
    fprintf(fp, "                   @   @ @   @            @  @  @  @                            \n");
    fprintf(fp, "                   @@,@@ @@@@@*           @@ @@ @@@@@                           \n");
    fprintf(fp, "                   @@@@@# @@@@            @@@@@  @@*                            \n");

    fprintf(fp, "Voici le Mouton de CODA\n");

    fclose(fp);
}