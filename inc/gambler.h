#pragma once
#include <stdbool.h>
#include <sdl_all.h>

enum e_direction {
    LEFT,
    RIGHT
};

typedef struct s_gambler {
    enum e_direction direction;
    bool is_moving;
    SDL_Rect rect;
    SDL_Texture *texture;
}              t_gambler;

t_gambler *create_gambler(SDL_Renderer *renderer);
void destroy_gambler(t_gambler **gambler);
