#include "header.h"

void show_score(SDL_Renderer *renderer, t_score *score) {
    score->font = TTF_OpenFont(MX_RES("ARIAL.TTF"), 20);
    score->color.r = 255;
    score->color.g = 255;
    score->color.b = 255;
    score->color.a = 0;
    SDL_Surface *message = TTF_RenderText_Solid(
            score->font, "Score", score->color);
    score->texture1 = SDL_CreateTextureFromSurface(renderer, message);
    SDL_FreeSurface(message);
    score->score_rect.x = 20;
    score->score_rect.y = 20;
    score->score_rect.w = 100;
    score->score_rect.h = 50;
    score->current_score_rect.x = 150;
    score->current_score_rect.y = 20;
    score->current_score_rect.w = 45;
    score->current_score_rect.h = 50;
}
