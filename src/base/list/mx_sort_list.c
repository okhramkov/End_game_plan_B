#include "list.h"
#include <stdbool.h>

int mx_list_size(t_list *list);
t_list *node_at(t_list *list, int index);
void swap(t_list **list, int i, t_list *node_i, int j, t_list *node_j);

t_list *mx_sort_list(t_list *list, bool(*cmp)(void *a, void *b)) {
    if (cmp == 0 || list == 0) {
        return 0;
    }

    int size = mx_list_size(list);
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            t_list *node_i = node_at(list, i);
            t_list *node_j = node_at(list, j);
            if (cmp(node_i->data, node_j->data)) {
                swap(&list, i, node_i, j, node_j);
            }
        }
    }

    return list;
}

t_list *node_at(t_list *list, int index) {
    for (int i = 0; list; i++) {
        if (i == index) {
            return list;
        }
        list = list->next;
    }
    return 0;
}

void swap(t_list **list, int i, t_list *node_i, int j, t_list *node_j) {
    list++;
    i++;
    j++;
    node_j++;
    node_i++;
//    t_list *prev_i = 0;
//    if (i != 0)
//        prev_i = node_at(*list, i - 1);
//    t_list *prev_j = 0;
//    if (j != 0)
//        prev_j = node_at(*list, j - 1);
//
//    void *temp_next = node_i->next;
//    node_i->next = node_j->next;
//    node_j->next = temp_next;
//
//    if (prev_i != 0)
//
//    if (i == 0)
//        *list = node_j;
}
