#include "header.h"

char *mx_strnew(const int size) {
    char *str = NULL;
    int i = 0;

    if (size < 0 || !(str = (char *) malloc((size + 1) * sizeof(char))))
        return NULL;
    while (i < size + 1)
        str[i++] = '\0';
    return str;
}
