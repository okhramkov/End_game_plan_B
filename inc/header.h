#ifndef HEADER_H
#define HEADER_H

#define WINDOW_WIDTH (800)
#define WINDOW_HEIGHT (600)
#define SCROLL_SPEED (1000)

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <time.h>
#include <sdl_all.h>
#include <application.h>
#include <gambler.h>

typedef struct s_entity {
    SDL_Rect *rect;
    SDL_Texture *background;
    Mix_Music *grade_song;
}              t_entity;

typedef struct s_lifes {
    SDL_Texture *full;
    SDL_Texture *half;
    SDL_Texture *empty;
    SDL_Rect tambourine_pos1;
    SDL_Rect tambourine_pos2;
    SDL_Rect tambourine_pos3;
}              t_lifes;


typedef struct s_img {
    SDL_Surface *srf;
    SDL_Texture *texture;
    SDL_Rect n_1;
    SDL_Rect n_2;
    SDL_Rect n_3;
}              t_img;

typedef struct s_notes {
    // SDL_Surface *txt;  // для подсчета чисел
    // // SDL_Surface *game_over;  // для game over

    // int hp;
    // int score;
    int step;

    t_img sprint;
    t_img fail;
}              t_sprint;

int init_random(int low, int high);

typedef struct s_score {
    SDL_Texture *texture1;
    SDL_Texture *texture2;
    SDL_Color color;
    TTF_Font *font;
    SDL_Rect score_rect;
    SDL_Rect current_score_rect;
}              t_score;

typedef struct s_sprite {
    SDL_Texture *texture;
    SDL_Rect rect;
}              t_sprite;

#define MX_RES(a) path_for_res(a)

void sdl_initiation(App *app);
void load_music(t_entity *player);
void cleanup(App *app);
const char *path_for_res(const char *file_name);
void menu_callback(App *app);
void
draw_text(SDL_Color color, int x, int y, char *text, SDL_Renderer *renderer,
          TTF_Font *font);

// Scenes
int scoreboard(SDL_Renderer *renderer);
bool compare(SDL_Rect a, SDL_Rect b);
void event_on_stage(App *app, t_entity *player, t_sprint *note);
int show_menu(SDL_Renderer *renderer);
void add_gambler_lives_textures(SDL_Renderer *renderer, t_lifes *lifes);
void rend_life(SDL_Renderer *renderer, t_lifes *lifes, int lives);
void print_sprint(App *app, t_sprint *note, int lives);
void sprint(App *app, t_sprint *note);
SDL_Rect set_coordinate(SDL_Rect rct, int speed);
void note_falling(t_sprint *note);
void show_score(SDL_Renderer *renderer, t_score *score);
int show_about(SDL_Renderer *renderer);
int show_players(SDL_Renderer *renderer);

//Count parameters of gambler
int gambler_hp(t_sprint *note, t_gambler gambler, int lives);
int gambler_score(t_sprint *note, t_gambler gambler, int current_score);

//Other
char *mx_strnew(const int size);

#endif
