#include "list.h"

void mx_push_back(t_list **list, void *data) {
    if (list == 0)
        return;

    if (*list == 0) {
        *list = mx_create_node(data);
        return;
    }

    t_list *node = *list;
    while (1) {
        if (node->next == 0) {
            node->next = mx_create_node(data);
            return;
        }
        node = node->next;
    }
}
