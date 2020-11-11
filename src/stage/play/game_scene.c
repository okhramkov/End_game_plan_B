#include <gambler.h>
#include <grade.h>
#include "header.h"

void motion_gambler(t_gambler *gambler);
void rend_life(SDL_Renderer *renderer, t_lifes *lifes, int lives);
void rend_score(SDL_Renderer *renderer, t_score *score, int current_score, bool free);
void rend_gambler(SDL_Renderer *renderer, SDL_Texture *texture, t_gambler *gambler);

void event_on_stage(App *app, t_entity *player, t_sprint *note) {
    SDL_Texture *back_texture = IMG_LoadTexture(app->renderer, MX_RES("background.png"));
    SDL_Rect bg = {0, 0, 800, 600};

// make gambler
    t_grade *grade = make_grade(app->renderer);
    t_gambler *gambler = grade->gambler;
    gambler->is_moving = 0;

//set to 1 when window close button is pressed
    int close_requested = 0;
    //Start the music
    load_music(player);
    Mix_PlayMusic(player->grade_song, -1);

    SDL_Surface *game_over = IMG_Load(MX_RES("game_over.png"));
    SDL_Texture *gameover = SDL_CreateTextureFromSurface(app->renderer, game_over);
    SDL_FreeSurface(game_over);
    SDL_Surface *winwin = IMG_Load(MX_RES("you_win.png"));
    SDL_Texture *win = SDL_CreateTextureFromSurface(app->renderer, winwin);
    SDL_FreeSurface(winwin);

    t_lifes lifes;
    add_gambler_lives_textures(app->renderer, &lifes);

    int lives = 6;
    int current_score = 0;
    int prev_score = 0;
    t_score score;
    show_score(app->renderer, &score);

    int ticks = 0;

    //animation loop
    while (!close_requested) {
        SDL_Event event;

        note_falling(note);
        prev_score = current_score;
        if (compare(gambler->rect, note->fail.n_1)) {
            if (lives > 0 && (note->fail.n_1.y = 518))
                lives--;
        }
        if (compare(gambler->rect, note->fail.n_2)) {
            if (lives > 0 && (note->fail.n_2.y = 518))
                lives--;
        }
        if (compare(gambler->rect, note->fail.n_3))  {
            if (lives > 0 && (note->fail.n_3.y = 518))
               lives--;
        }
        if (compare(gambler->rect, note->sprint.n_1)) {
            if ((note->sprint.n_1.y = 518))
                current_score++;
        }
        if (compare(gambler->rect, note->sprint.n_2)) {
            if ((note->sprint.n_2.y = 518))
                current_score++;
        }
        if (compare(gambler->rect, note->sprint.n_3))  {
            if ((note->sprint.n_3.y = 518))
                current_score++;
        }
        while (SDL_PollEvent(&event)) {
            switch (event.type) {
                case SDL_QUIT:
                    close_requested = 1;
                    break;
                case SDL_KEYDOWN:
                    switch (event.key.keysym.scancode) {
                        case SDL_SCANCODE_A:
                        case SDL_SCANCODE_LEFT:
                            gambler->is_moving = 1;
                            gambler->direction = LEFT;
                            break;
                        case SDL_SCANCODE_D:
                        case SDL_SCANCODE_RIGHT:
                            gambler->direction = RIGHT;
                            gambler->is_moving = 1;
                            break;
                        case SDL_SCANCODE_SPACE:
                            lives--;
                            break;
                        case SDL_SCANCODE_TAB:
                            current_score++;
                            break;
                        default:
                            break;
                    }
                    break;
                case SDL_KEYUP:
                    switch (event.key.keysym.scancode) {
                        case SDL_SCANCODE_A:
                        case SDL_SCANCODE_LEFT:
                            gambler->is_moving = 0;
                            break;
                        case SDL_SCANCODE_D:
                        case SDL_SCANCODE_RIGHT:
                            gambler->is_moving = 0;
                            break;
                        case SDL_SCANCODE_Q:
                            Mix_FreeMusic(player->grade_song);
                            return;
                        default:
                            break;
                    }
                    break;
            }
        }

        // MOVE
        //
        motion_gambler(gambler);

        // RENDER
        //
        //clear the window
        SDL_RenderClear(app->renderer);

        //draw the image to the window

        if (lives <= 0) {
            SDL_RenderCopy(app->renderer, gameover, NULL, NULL);
            close_requested = 1;
        } else if (current_score >= 100) {
            SDL_RenderCopy(app->renderer, win, NULL, NULL);
            close_requested = 1;
        } else {
            SDL_RenderCopy(app->renderer, back_texture, NULL, &bg);
            prev_score != current_score ? rend_score(app->renderer, &score, current_score, true)
                                        : rend_score(app->renderer, &score, current_score, false);
            rend_life(app->renderer, &lifes, lives);
            rend_gambler(app->renderer, gambler->texture, gambler); print_sprint(app, note, lives);
        }

        SDL_RenderPresent(app->renderer);

        ticks++;
        SDL_Delay(1000 / 60);
    }
    SDL_Delay(5000);
    destroy_grade(&grade);
    SDL_DestroyTexture(back_texture);
    SDL_DestroyTexture(score.texture1);
    SDL_DestroyTexture(score.texture2);
    SDL_DestroyTexture(gameover);
    SDL_DestroyTexture(win);
    menu_callback(app);
}

void rend_gambler(SDL_Renderer *renderer, SDL_Texture *texture, t_gambler *gambler) {
    if ((*gambler).direction == RIGHT) {
        SDL_RenderCopy(renderer, texture, NULL, &(*gambler).rect);
    } else {
        SDL_RenderCopyEx(renderer, texture, NULL, &(*gambler).rect, 180.0f, NULL, SDL_FLIP_VERTICAL);
    }
}

void rend_score(SDL_Renderer *renderer, t_score *score, int current_score,
                  bool free) {
    if (free)
        SDL_DestroyTexture(score->texture2);

    char print[100];
    sprintf(print, "%d", current_score);
    TTF_Font *font = TTF_OpenFont(MX_RES("E.TTF"), 30);
    SDL_Surface *to_print = TTF_RenderText_Solid(font, print, score->color);
    score->texture2 = SDL_CreateTextureFromSurface(renderer, to_print);
    SDL_FreeSurface(to_print);
    SDL_RenderCopy(renderer, score->texture1, NULL, &score->score_rect);
    SDL_RenderCopy(renderer, score->texture2, NULL, &score->current_score_rect);
}

void rend_life(SDL_Renderer *renderer, t_lifes *lifes, int lives) {
    switch (lives) {
        case 6:
            SDL_RenderCopy(renderer, lifes->full, NULL, &lifes->tambourine_pos1);
            SDL_RenderCopy(renderer, lifes->full, NULL, &lifes->tambourine_pos2);
            SDL_RenderCopy(renderer, lifes->full, NULL, &lifes->tambourine_pos3);
            break;
        case 5:
            SDL_RenderCopy(renderer, lifes->half, NULL, &lifes->tambourine_pos1);
            SDL_RenderCopy(renderer, lifes->full, NULL, &lifes->tambourine_pos2);
            SDL_RenderCopy(renderer, lifes->full, NULL, &lifes->tambourine_pos3);
            break;
        case 4:
            SDL_RenderCopy(renderer, lifes->empty, NULL, &lifes->tambourine_pos1);
            SDL_RenderCopy(renderer, lifes->full, NULL, &lifes->tambourine_pos2);
            SDL_RenderCopy(renderer, lifes->full, NULL, &lifes->tambourine_pos3);
            break;
        case 3:
            SDL_RenderCopy(renderer, lifes->empty, NULL, &lifes->tambourine_pos1);
            SDL_RenderCopy(renderer, lifes->half, NULL, &lifes->tambourine_pos2);
            SDL_RenderCopy(renderer, lifes->full, NULL, &lifes->tambourine_pos3);
            break;
        case 2:
            SDL_RenderCopy(renderer, lifes->empty, NULL, &lifes->tambourine_pos1);
            SDL_RenderCopy(renderer, lifes->empty, NULL, &lifes->tambourine_pos2);
            SDL_RenderCopy(renderer, lifes->full, NULL, &lifes->tambourine_pos3);
            break;
        case 1:
            SDL_RenderCopy(renderer, lifes->empty, NULL, &lifes->tambourine_pos1);
            SDL_RenderCopy(renderer, lifes->empty, NULL, &lifes->tambourine_pos2);
            SDL_RenderCopy(renderer, lifes->half, NULL, &lifes->tambourine_pos3);
            break;
        case 0: //Game over
            SDL_RenderCopy(renderer, lifes->empty, NULL, &lifes->tambourine_pos1);
            SDL_RenderCopy(renderer, lifes->empty, NULL, &lifes->tambourine_pos2);
            SDL_RenderCopy(renderer, lifes->empty, NULL, &lifes->tambourine_pos3);
            break;
        default:
            break;
    }
}

void motion_gambler(t_gambler *gambler) {
    //give sprite initial velocity
    float x_vel = 0;
    if (gambler->is_moving != 0)
        x_vel = gambler->direction == LEFT ? -SCROLL_SPEED : SCROLL_SPEED;

    //update positions;
    gambler->rect.x += x_vel / 60;

    //collision detection with bounds
    if (gambler->rect.x <= 0) gambler->rect.x = 0;
    if (gambler->rect.y <= 0) gambler->rect.y = 0;
    if (gambler->rect.x >= WINDOW_WIDTH - gambler->rect.w)
        gambler->rect.x = WINDOW_WIDTH - gambler->rect.w;
    if (gambler->rect.y >= WINDOW_HEIGHT - gambler->rect.h)
        gambler->rect.y = WINDOW_HEIGHT - gambler->rect.h - 20;
}
