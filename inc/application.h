#pragma once
#include <sdl_all.h>

typedef struct Application {
    SDL_Renderer *renderer;
    SDL_Window *window;
} App;

App *applying();
void erode_applying();
