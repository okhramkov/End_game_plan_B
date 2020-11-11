#include "header.h"

void load_music(t_entity *player) {
    //Initialize SDL mixer
    Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048);

    //Load audio files
    int n = 2;
    char *tracks[] = {
            "mp3/Gate_.mp3",
            "mp3/Candyland.mp3"};
    int i = rand() % n;
    const char *path = path_for_res(tracks[i]);

    player->grade_song = Mix_LoadMUS(path);
}
