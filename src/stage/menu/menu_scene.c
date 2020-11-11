#include "header.h"
#include <stdbool.h>


int show_menu(SDL_Renderer *renderer) {
    bool running = true;
    SDL_Event event;
    int index_menu = 1;
    TTF_Init();
    if (TTF_Init() == -1) {
        printf("TTF_Init: %s\n", TTF_GetError());
        exit(1);
    }
    TTF_Font *font = TTF_OpenFont(MX_RES("ARIAL.TTF"), 25);
    SDL_Color color = {0, 0, 0, 0};
    int grey = 100;
    SDL_Color color_selected = {grey, grey, grey, 0};

    //Customize panels
    SDL_Rect button1 = {280, 180, 240, 100};
    SDL_Texture *button11 = IMG_LoadTexture(renderer, MX_RES("empty.png"));
    SDL_Rect button2 = {280, 245, 240, 100};
    SDL_Texture *button22 = IMG_LoadTexture(renderer, MX_RES("empty.png"));

    //background
    SDL_Rect backgroundRect = {0, 0, WINDOW_WIDTH, WINDOW_HEIGHT};
    SDL_Texture *imgBackground = IMG_LoadTexture(renderer, MX_RES("empty_back.png"));

    while (running) {
        color.r = 0;
        color.g = 255;
        color.b = 255;
        color.a = 0;
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_KEYUP) {
                if (event.key.keysym.sym == SDLK_ESCAPE) {
                    return 0;
                }
                if (event.key.keysym.sym == SDLK_UP) {
                    if (index_menu == 2) index_menu = 1;
                }
                if (event.key.keysym.sym == SDLK_DOWN) {
                    if (index_menu == 1) index_menu = 2;
                }
                if (event.key.keysym.sym == SDLK_RETURN) {
                    SDL_DestroyTexture(button11);
                    SDL_DestroyTexture(button22);
                    SDL_DestroyTexture(imgBackground);
                    TTF_CloseFont(font);
                    return index_menu;
                }
            }
        }
        SDL_RenderCopy(renderer, imgBackground, NULL, &backgroundRect);
        SDL_RenderCopy(renderer, button11, NULL, &button1);
        SDL_RenderCopy(renderer, button22, NULL, &button2);
        if (index_menu == 1) {
            color.r = 0;
            draw_text(color_selected, 360, 210, "START", renderer, font);
            color.r = 255;
            draw_text(color, 363, 275, "QUIT", renderer, font);

        } 
        else if (index_menu == 2) {
            color.r = 0;
            draw_text(color_selected, 363, 275, "QUIT", renderer, font);
            color.r = 255;
            draw_text(color, 360, 210, "START", renderer, font);
         }
        usleep(100);
        SDL_RenderPresent(renderer);
    }
    SDL_DestroyTexture(imgBackground);

    return 1;
}
