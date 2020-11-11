#pragma once

#include <SDL2/SDL.h>

#ifdef CMAKE

#include <SDL_image.h>
#include <SDL_ttf.h>
#include <SDL_mixer.h>
#include "application.h"

#else

#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>
#include <SDL2_ttf/SDL_ttf.h>
#include <SDL2_mixer/SDL_mixer.h>

#endif
