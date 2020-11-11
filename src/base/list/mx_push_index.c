#include "list.h"

void mx_push_index(t_list **list, void *data, int index) {
    if (list == 0)
        return;

    if (*list == 0 || index <= 0) {
        mx_push_front(list, data);
        return;
    }

    t_list *node = *list;
    for (int i = 1; node; i++) {
        if (i == index) {
            t_list *new_node = mx_create_node(data);
            new_node->next = node->next;
            node->next = new_node;
            return;
        }
        node = node->next;
    }

    mx_push_back(list, data);
}
