#include <ctype.h>
#include <string.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

char* hello(char* const input) {
    char* str = NULL;
    if (input == NULL || strcmp(input, "") == 0) {
        return "Hello, World!";
    } else {
        str = strdup(input);
        if(str == NULL) {
            return NULL;
        }
    }

    for (int i = 0; i < strlen(str); ++i) {
        *(str + i) = (char)tolower(*(str + i));
    }
    *str = (char)toupper(*str);

    char* str1 = strdup("Hello, ");
    if(str1 == NULL) {
        return NULL;
    }
    str1 = (char*)realloc(str1, (strlen(str1) + strlen(str) + 2) * sizeof(char));
    if(str1 == NULL) {
        return NULL;
    }

    strcat(str1, str);
    strcat(str1, "!");

    free(str);

    return str1;
}


int main(void) {
    static char* message = "usErFJFKjkljFj";
    printf( "%s", hello(message));
    return 0;
}