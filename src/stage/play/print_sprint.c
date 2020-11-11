#include "header.h"

void print_sprint(App *app, t_sprint *note, int lives) {
    if (lives > 0) {
        SDL_RenderCopy(app->renderer, note->sprint.texture, NULL, &note->sprint.n_1);
        SDL_RenderCopy(app->renderer, note->fail.texture, NULL,
                       &note->fail.n_1);
        SDL_RenderCopy(app->renderer, note->sprint.texture, NULL, &note->sprint.n_2);
        SDL_RenderCopy(app->renderer, note->fail.texture, NULL,
                       &note->fail.n_2);
        SDL_RenderCopy(app->renderer, note->sprint.texture, NULL, &note->sprint.n_3);
        SDL_RenderCopy(app->renderer, note->fail.texture, NULL,
                       &note->fail.n_3);
    }
}
