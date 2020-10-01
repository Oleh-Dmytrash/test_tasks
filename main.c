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
    if (str1 == NULL) {
        return NULL;
    }
    str1 = (char*)realloc(str1, (strlen(str1) + strlen(str) + 2) * sizeof(char));
    if (str1 == NULL) {
        return NULL;
    }

    strcat(str1, str);
    strcat(str1, "!");

    free(str);

    return str1;
}

char* const hello1(char* const input) {
    char* str = (char*)malloc((strlen("Hello, ") + strlen(
        (input == NULL || strcmp(input, "") == 0)? "World" : input) + 2) * sizeof(char));
    strcpy(str, "Hello, ");
    strcat(str, (input == NULL || strcmp(input, "") == 0)? "World" : input);
    str[strlen("Hello, ")] = (char)toupper(str[strlen("Hello, ")]);
    for (int i = strlen("Hello, ") + 1; i < strlen(str); ++i) {
        str[i] = (char)tolower(str[i]);
    }
    return strcat(str, "!");
}


int main(void) {
    char* message = "oleh";
    printf( "%s", hello1(message));
    return 0;
}