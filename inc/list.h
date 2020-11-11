#pragma once

#include <stdbool.h>

typedef struct s_list {
    void *data;
    struct s_list *next;
}              t_list;

t_list *mx_create_node(void *data);
void mx_push_back(t_list **list, void *data);
void mx_push_front(t_list **list, void *data);
void mx_pop_back(t_list **list);
void mx_pop_front(t_list **list);
int mx_list_size(t_list *list);
void mx_push_index(t_list **list, void *data, int index);
void mx_pop_index(t_list **list, int index);
void mx_clear_list(t_list **list);
void mx_foreach_list(t_list *list, void(*f)(t_list *node));
t_list *mx_sort_list(t_list *list, bool(*cmp)(void *a, void *b));
void
mx_del_node_if(t_list **list, void *del_data, bool(*cmp)(void *a, void *b));
