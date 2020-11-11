#include "list.h"
#include <stdlib.h>

void mx_push_front(t_list **list, void *data) {
    if (list == 0)
        return;

    t_list *front = mx_create_node(data);
    front->next = *list;
    *list = front;
}
