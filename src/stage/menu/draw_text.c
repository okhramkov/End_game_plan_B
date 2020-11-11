#include "header.h"

void draw_text(
    SDL_Color color, int x, int y, char *text, SDL_Renderer *renderer, TTF_Font *font) {
    SDL_Surface *text_surface = TTF_RenderText_Solid(font, text, color);
    SDL_Texture *textureGameName = SDL_CreateTextureFromSurface(renderer, text_surface);
    SDL_Rect text_rect = {x, y, 1, 1};
    SDL_QueryTexture(textureGameName, NULL, NULL, &text_rect.w, &text_rect.h);
    SDL_RenderCopy(renderer, textureGameName, NULL, &text_rect);
    SDL_FreeSurface(text_surface);
    text_surface = 0;
    SDL_DestroyTexture(textureGameName);
}
