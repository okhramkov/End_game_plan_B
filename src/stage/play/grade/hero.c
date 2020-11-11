#include <gambler.h>
#include <header.h>

t_gambler *create_gambler(SDL_Renderer *renderer) {
    t_gambler *gambler = (t_gambler *) malloc(sizeof(t_gambler));
    gambler->is_moving = 0;
    gambler->texture = IMG_LoadTexture(renderer, MX_RES("player.png"));

    SDL_QueryTexture(gambler->texture, NULL, NULL, &gambler->rect.w, &gambler->rect.h);
    gambler->rect.w /= 4;
    gambler->rect.h /= 4;
    gambler->rect.x = (WINDOW_WIDTH - gambler->rect.w) / 2;
    gambler->rect.y = (WINDOW_WIDTH - gambler->rect.w) * 2;
    return gambler;
}

void destroy_gambler(t_gambler **gambler) {
    SDL_DestroyTexture((*gambler)->texture);
    free(*gambler);
    *gambler = 0;
}
