#include "list.h"

int mx_list_size(t_list *list) {
    if (list == 0)
        return 0;

    int i = 0;
    for (; list; i++) {
        list = list->next;
    }

    return i;
}
