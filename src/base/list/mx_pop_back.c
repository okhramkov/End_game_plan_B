#include "list.h"
#include <stdlib.h>

void mx_pop_back(t_list **list) {
    // Empty
    if (*list == 0)
        return;

    // One element
    if ((*(list))->next == 0) {
        free(*list);
        *list = 0;
        return;
    }

    // > 1 elements
    t_list *node = *list;
    t_list *prev = *list;
    while (1) {
        if (node->next == 0) {
            prev->next = 0;
            free(node);
            return;
        }
        prev = node;
        node = node->next;
    }
}
