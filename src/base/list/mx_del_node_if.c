#include "list.h"
#include <stdbool.h>
#include <stdlib.h>

void
mx_del_node_if(t_list **list, void *del_data, bool(*cmp)(void *a, void *b)) {
    if (list == 0 || del_data == 0 || cmp == 0)
        return;

    t_list *node = *list;
    t_list *prev = *list;
    int i = 0;
    while (node) {
        if (cmp(node->data, del_data)) {
            if (i == 0) {
                *list = node->next;
            }
            prev->next = node->next;
            free(node);
            return;
        }
        prev = node;
        node = node->next;
        i++;
    }
}
