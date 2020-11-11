#include "list.h"
#include <stdlib.h>

void mx_pop_index(t_list **list, int index) {
    if (list == 0 || *list == 0) {
        return;
    }
    t_list *node = *list;

    // 1
    if (node->next == 0 || index <= 0) {
        mx_pop_front(list);
        return;
    }

    t_list *prev = node;
    for (int i = 0; node; i++) {
        if (index == i) {
            prev->next = node->next;
            free(node);
            return;
        }
        prev = node;
        node = node->next;
    }

    mx_pop_back(list);
}
