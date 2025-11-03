#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#define LARGEURSPRITE 80
#define HAUTEURSPRITE 16

char * get_file(FILE * fp)
{
    char * content;
    char buffer[10];

    content = malloc(sizeof(char));
    content[0] = '\0';

    while(fgets(buffer, 10, fp) != NULL)
    {
        content = realloc(content, (strlen(buffer) * sizeof(char)) + strlen(content) * sizeof(char));
        content = strcat(content, buffer);
    }

    return content;
}

int count_lines(char *str)
{
    int i = 0;
    int lines = 0;

    while(str[i] != '\0')
    {
        if(str[i] == '\n')
        {
            lines++;
        }

        i++;
    }

    return lines;
}

void display_tab(char **tab, int lines)
{
    int i = 0;

    while(i < lines)
    {
        printf("%s\n", tab[i]);
        i++;
    }
}

int main()
{
    FILE *fp = fopen("map.txt", "r");
    char * file_content;
    char **tab;
    int lines;
    char * line;
    int i = 0;
    int j = 0;

    if (fp == NULL)
    {
        printf("Le fichier map.txt n'a pas pu être ouvert\n");
        return EXIT_FAILURE;
    }

    file_content = get_file(fp);

    lines = count_lines(file_content);

    tab = malloc(lines * sizeof(*tab));

    line = strtok(file_content, "\n");
    while((line != NULL) && (i < lines))
    {
        tab[i] = malloc(strlen(line) * sizeof(char));
        tab[i] = strcpy(tab[i], line);
        i++;

        line = strtok(NULL, "\n");
    }

    display_tab(tab, lines);

    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS) < 0) {
        printf("Error SDL2 Init : %s\n", SDL_GetError());
        return 1;
    }
    SDL_Window* window = SDL_CreateWindow("Exercice 4", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 260, 117, SDL_WINDOW_OPENGL);
    if (window == NULL) {
        printf("Error while creating a window : %s\n", SDL_GetError());
        return 1;
    }

    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (renderer == NULL)
    {
        printf("Erreur à la création du renderer\n");
        return 1;
    }
    SDL_Surface* surface = IMG_Load("levels.png");
    if (surface == NULL)
    {
        printf("Error loading image %s\n", IMG_GetError());
        return 1;
    }
    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
    if (texture == NULL)
    {
        printf("Error creating texture\n");
        return 1;
    }

    SDL_FreeSurface(surface);

    SDL_Rect srcBleu;
    srcBleu.x = 32; // Position x de la région à découper
    srcBleu.y = 0; // Position y de la région à découper
    srcBleu.w = 16; // Largeur de la région à découper
    srcBleu.h = 16; // Hauteur de la région à découper

    // Définir la position où afficher la région découpée
    SDL_Rect destBleu;
    destBleu.x = (48 - srcBleu.w) / 2; // Centrer horizontalement
    destBleu.y = (16 - srcBleu.h) / 2; // Centrer verticalement
    destBleu.w = srcBleu.w; // Garder la même largeur
    destBleu.h = srcBleu.h; // Garder la même hauteur

    SDL_Rect srcR;
    srcR.x = 0; // Position x de la région à découper
    srcR.y = 0; // Position y de la région à découper
    srcR.w = 16; // Largeur de la région à découper
    srcR.h = 16; // Hauteur de la région à découper

    // Définir la position où afficher la région découpée
    SDL_Rect destR;
    destR.x = (16 - srcR.w) / 2; // Centrer horizontalement
    destR.y = (16 - srcR.h) / 2; // Centrer verticalement
    destR.w = srcR.w; // Garder la même largeur
    destR.h = srcR.h; // Garder la même hauteur

    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer, texture, &srcR, &destR);
    SDL_RenderCopy(renderer, texture, &srcBleu, &destBleu);
    SDL_RenderPresent(renderer);

    while(1) {
        SDL_Event e;
        if (SDL_WaitEvent(&e)) {
            if (e.type == SDL_QUIT) {
                break;
            }
          }
      }
    SDL_Quit();
    return 0;
}