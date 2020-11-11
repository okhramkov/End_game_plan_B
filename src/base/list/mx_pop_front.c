#include "list.h"
#include <stdlib.h>

void mx_pop_front(t_list **list) {
    if (*list == 0) {
        return;
    }
    t_list *node = *list;
    *list = node->next;
    free(node);
}
