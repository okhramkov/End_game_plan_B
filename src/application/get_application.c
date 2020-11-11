#include <application.h>
#include <stdlib.h>

App *applying() {
    static App *application = 0;
    if (application == 0) {
        application = (App *) malloc(sizeof(App));
    }
    return application;
}

void erode_applying() {
    App *application = applying();
    SDL_DestroyRenderer(application->renderer);
    SDL_DestroyWindow(application->window);
    free(application);
}
