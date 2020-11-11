#include <application.h>
#include "header.h"

int main() {
    srand(time(0));

    App *app = applying();
    sdl_initiation(app);

    menu_callback(app);

    TTF_Quit();
    SDL_Quit();
    erode_applying();

    return 0;
}

void menu_callback(App *app) {
    int scene = 6;
    while (scene == 3 || scene == 6 || scene == 5)
        scene = show_menu(app->renderer);
    if (scene == 1) {
        t_entity *player = malloc(sizeof(t_entity));
        t_sprint *note = (t_sprint *) malloc(sizeof(t_sprint));
        sprint(app, note);
        note->sprint.n_1.x = init_random(0, 700);
        note->fail.n_1.x = init_random(0, 700);

        note->sprint.n_2.x = init_random(0, 700);
        note->fail.n_2.x = init_random(0, 700);

        note->sprint.n_3.x = init_random(0, 700);
        note->fail.n_3.x = init_random(0, 700);

        note->step = 1;
        event_on_stage(app, player, note);
    }
}
