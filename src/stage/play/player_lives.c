#include "header.h"

void add_gambler_lives_textures(SDL_Renderer *renderer, t_lifes *lifes) {
    lifes->full = IMG_LoadTexture(renderer, MX_RES("fulltambourine.png"));
    lifes->half = IMG_LoadTexture(renderer, MX_RES("halftambourine.png"));
    lifes->empty = IMG_LoadTexture(renderer, MX_RES("emptytambourine.png"));

    lifes->tambourine_pos1 = (SDL_Rect) {410, 25, 40, 40};
    lifes->tambourine_pos2 = (SDL_Rect) {360, 25, 40, 40};
    lifes->tambourine_pos3 = (SDL_Rect) {310, 25, 40, 40};
}
