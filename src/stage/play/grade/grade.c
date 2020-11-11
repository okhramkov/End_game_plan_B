#include <grade.h>
#include <stdlib.h>

t_grade *make_grade(SDL_Renderer *renderer) {
    t_grade *grade = (t_grade *) malloc(sizeof(t_grade));
    grade->renderer = renderer;
    grade->gambler = create_gambler(renderer);
    return grade;
}

void destroy_grade(t_grade **grade) {
    destroy_gambler(&((*grade)->gambler));
    free(*grade);
    *grade = 0;
}
