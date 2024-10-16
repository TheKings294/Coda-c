#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <stdio.h>

int main(void)
{
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS) < 0) {
        printf("Error SDL2 Init : %s\n", SDL_GetError());
        return 1;
    }

    SDL_Window* window = SDL_CreateWindow("Exo1 SDL", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 160, 160, SDL_WINDOW_OPENGL);
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
        return 1;
    }

    SDL_Surface* surface = IMG_Load("ball_1.png");
    if (surface == NULL) {
        printf("Error loading image %s\n", IMG_GetError());
        return 1;
    }
    SDL_Surface* surface1 = IMG_Load("ball_2.png");
    if (surface1 == NULL) {
        printf("Error loading image %s\n", IMG_GetError());
        return 1;
    }
    SDL_Surface* surface2 = IMG_Load("ball_3.png");
    if (surface2 == NULL) {
        printf("Error loading image %s\n", IMG_GetError());
        return 1;
    }
    SDL_Surface* surface3 = IMG_Load("ball_4.png");
    if (surface3 == NULL) {
        printf("Error loading image %s\n", IMG_GetError());
        return 1;
    }

    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface); // Libérer la surface après la création de la texture
    if (texture == NULL) {
        printf("Erreur à la création de la texture\n");
        return 1;
    }
    SDL_Texture* texture1 = SDL_CreateTextureFromSurface(renderer, surface1);
    SDL_FreeSurface(surface1); // Libérer la surface après la création de la texture
    if (texture1 == NULL) {
        printf("Erreur à la création de la texture\n");
        return 1;
    }
    SDL_Texture* texture2 = SDL_CreateTextureFromSurface(renderer, surface2);
    SDL_FreeSurface(surface2); // Libérer la surface après la création de la texture
    if (texture2 == NULL) {
        printf("Erreur à la création de la texture\n");
        return 1;
    }
    SDL_Texture* texture3 = SDL_CreateTextureFromSurface(renderer, surface3);
    SDL_FreeSurface(surface3); // Libérer la surface après la création de la texture
    if (texture3 == NULL) {
        printf("Erreur à la création de la texture\n");
        return 1;
    }

    SDL_Rect position;
    //SDL_MouseMotionEvent mouse_motion;
    position.x = 100;
    position.y = 100;
    position.w = 16; // Spécifiez la largeur de la texture
    position.h = 16;
    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer, texture, NULL, &position);
    SDL_RenderPresent(renderer);
    // Boucle principale
    while (1) {
        SDL_Event e;
        if (SDL_WaitEvent(&e)) {
            if (e.type == SDL_QUIT) {
                break;
            }else if (e.type == SDL_KEYDOWN) { //Pour motion utilier SDL_MOUSEMOTION
                if (e.key.keysym.scancode == SDL_SCANCODE_W) {
			        position.y = position.y - 4;
                    SDL_RenderClear(renderer);
                    SDL_RenderCopy(renderer, texture, NULL, &position);
                    SDL_RenderPresent(renderer);
                }
                else if (e.key.keysym.scancode == SDL_SCANCODE_A) {
			        position.x = position.x - 4;
                    SDL_RenderClear(renderer);
                    SDL_RenderCopy(renderer, texture3, NULL, &position);
                    SDL_RenderPresent(renderer);
                }
                else if (e.key.keysym.scancode == SDL_SCANCODE_S) {
			       position.y = position.y + 4;
                    SDL_RenderClear(renderer);
                    SDL_RenderCopy(renderer, texture2, NULL, &position);
                    SDL_RenderPresent(renderer);
                }
                else if (e.key.keysym.scancode == SDL_SCANCODE_D) {
			        position.x = position.x + 4;
                    SDL_RenderClear(renderer);
                    SDL_RenderCopy(renderer, texture1, NULL, &position);
                    SDL_RenderPresent(renderer);
                }
            }
        }
    }

    // Libérer les ressources
    SDL_DestroyTexture(texture);
    SDL_DestroyTexture(texture1);
    SDL_DestroyTexture(texture2);
    SDL_DestroyTexture(texture3);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    IMG_Quit();
    SDL_Quit();

    return 0;
}
