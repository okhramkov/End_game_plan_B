#include "header.h"

static void mx_printerror(char *str) {
    write(2, "endgame: ", 9);
    for (int i = 0; str[i] != '\0'; i++)
        write(2, &str[i], 1);
    write(2, "\n", 1);
}

static void sdlerror(void) {
    mx_printerror((char *) SDL_GetError());
    exit(2);
}

void sprint(App *app, t_sprint *sprint) {
    if ((sprint->sprint.srf = IMG_Load(MX_RES("sprint.png"))) == NULL)
        sdlerror();
    if ((sprint->fail.srf = IMG_Load(MX_RES("fail.png"))) == NULL)
        sdlerror();
    sprint->sprint.texture = SDL_CreateTextureFromSurface(app->renderer, sprint->sprint.srf);
    sprint->fail.texture = SDL_CreateTextureFromSurface(app->renderer, sprint->fail.srf);
    SDL_FreeSurface(sprint->sprint.srf);
    SDL_FreeSurface(sprint->fail.srf);
    SDL_QueryTexture(sprint->sprint.texture, NULL, NULL, &(sprint->sprint.n_1.w), &(sprint->sprint.n_1.h));
    SDL_QueryTexture(sprint->fail.texture, NULL, NULL, &(sprint->fail.n_1.w), &sprint->fail.n_1.h);
    SDL_QueryTexture(sprint->sprint.texture, NULL, NULL, &sprint->sprint.n_2.w, &sprint->sprint.n_2.h);
    SDL_QueryTexture(sprint->fail.texture, NULL, NULL, &sprint->fail.n_2.w, &sprint->fail.n_2.h);
    SDL_QueryTexture(sprint->sprint.texture, NULL, NULL, &sprint->sprint.n_3.w, &sprint->sprint.n_3.h);
    SDL_QueryTexture(sprint->fail.texture, NULL, NULL, &sprint->fail.n_3.w, &sprint->fail.n_3.h);
}
