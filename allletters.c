
#include "string.h"
#include <stdio.h>
int all_letters(char *s) {
    if((*s) == '\0')
        return 0;
    while (*s != '\0') {
        if(*s < 'A' || *s > 'z' || (*s > 'Z' && *s < 'a' ))
        return 0;
        s++;
    }
    return 1;
}