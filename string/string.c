#include "string/include/string.h"
#include <stdlib.h>
#include <ctype.h >
char *to_lower_case(char *s) {
    int i = 0;
    while(s[i]) {
        s[i] = tolower(s[i]);
        i++;
    }
    return s;
}

char *to_upper_case(char *s){
     int i = 0;
    while(s[i]) {
        s[i] = toupper(s[i]);
        i++;
    }
    return s;
}