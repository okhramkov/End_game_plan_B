#pragma once

#include <gambler.h>
#include "header.h"

typedef struct s_grade {
    t_gambler *gambler;
    Mix_Music *current_song;
    SDL_Renderer *renderer;
    t_sprite background;
}              t_grade;

t_grade *make_grade(SDL_Renderer *renderer);
void destroy_grade(t_grade **grade);
