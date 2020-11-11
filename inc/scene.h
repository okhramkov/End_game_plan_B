#pragma once

enum e_scene {
    SCENE_NONE,
    SCENE_ABOUT,
    SCENE_GAME,
    SCENE_MENU
};

typedef struct s_scene {
    enum e_scene type;
}              t_scene;
