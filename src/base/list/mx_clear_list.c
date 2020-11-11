#include "list.h"
#include <stdlib.h>

void mx_clear_list(t_list **list) {
    if (list == 0)
        return;
    t_list *node = *list;
    while (1) {
        if (node == 0) {
            *list = 0;
            return;
        }
        t_list *old = node;
        node = node->next;
        free(old);
    }
}
