#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <stdio.h>

int main(void)
{
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS) < 0) {
        printf("Error SDL2 Init : %s\n", SDL_GetError());
        return 1;
    }

    SDL_Window* window = SDL_CreateWindow("Exo1 SDL", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 320, 320, SDL_WINDOW_OPENGL);
    if (window == NULL) {
        printf("Error Window Creation\n");
        SDL_Quit();
        return 3;
    }

    if (IMG_Init(IMG_INIT_PNG) == 0) {
        printf("Erreur d'initialisation de la SDL_Image\n");
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 1;
    }

    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (renderer == NULL) {
        printf("Erreur à la création du renderer\n");
        //IMG_Quit();
        //SDL_DestroyWindow(window);
        //SDL_Quit();
        return 1;
    }

    SDL_Surface* surface = IMG_Load("bottle.png");
    if (surface == NULL) {
        printf("Error loading image %s\n", IMG_GetError());
        //SDL_DestroyRenderer(renderer);
        //IMG_Quit();
        //SDL_DestroyWindow(window);
        //SDL_Quit();
        return 1;
    }

    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface); // Libérer la surface après la création de la texture
    if (texture == NULL) {
        printf("Erreur à la création de la texture\n");
        //SDL_DestroyRenderer(renderer);
        //IMG_Quit();
        //SDL_DestroyWindow(window);
        //SDL_Quit();
        return 1;
    }
    SDL_Rect position;
    //SDL_MouseMotionEvent mouse_motion;
    position.x = 100;
    position.y = 100;
    position.w = 16; // Spécifiez la largeur de la texture
    position.h = 16;
    // Boucle principale
    while (1) {
        SDL_RenderClear(renderer);
        SDL_RenderCopy(renderer, texture, NULL, &position);
        SDL_RenderPresent(renderer);
        SDL_Event e;
        if (SDL_WaitEvent(&e)) {
            if (e.type == SDL_QUIT) {
                break;
            }else if (e.type == SDL_MOUSEBUTTONDOWN) { //Pour motion utilier SDL_MOUSEMOTION
                position.x = e.button.x; // e.motion.x
                position.y = e.button.y; // e.motion.y
                }
        }
    }

    // Libérer les ressources
    SDL_DestroyTexture(texture);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    IMG_Quit();
    SDL_Quit();

    return 0;
}
