#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STRING_LENGTH 30

int find_length_array_pointers(char **str);
char **sub_string(char *orig, char *sep);

int main()
{
    char str[7] = "123";
    char **result = sub_string(str, "");
    while (*result != NULL) {
        printf("%s\n", *result);
        result++;
    }
    return 0;
}

int find_length_array_pointers(char **str) {
    int n  = 0;
    while(*str != NULL) {
        n++;
        str++;
    }
    return n+1;
}

char **sub_string(char *orig, char *sep) {
    char **str;
    //printf("Origin: %s with sep: %s\n", orig, sep);
    if (strlen(orig) == 0) {
        str = malloc(sizeof(char *) * 3);
        str[0] = malloc(sizeof(char) * STRING_LENGTH);
        strcpy(str[0], "");
        str[1] = malloc(sizeof(char) * STRING_LENGTH);
        strcpy(str[1], sep);
        str[2] = NULL;

    } else {
        char *new_origin = (char *) malloc(sizeof(char) * STRING_LENGTH);
        char *new_sep = (char *) malloc(sizeof(char) * 2);
        strcpy(new_origin, orig);
        *(new_sep) = *(new_origin + strlen(orig)-1);
        *(new_sep+1) = '\0';
        *(new_origin + strlen(orig)-1)='\0';
        str = sub_string(new_origin, new_sep);
        if (strlen(sep) == 1) {
            int n = find_length_array_pointers(str);
            char **new_str = malloc(sizeof(char *) * (2*(n-1)+1));
            char **mark = new_str;
            //printf("-----\n");
            while(*str != NULL) {
                *new_str = malloc(sizeof(char) * STRING_LENGTH);
                strcpy(*new_str, *str);
                //printf("nS: %s\n", *new_str);
                new_str++;
                *new_str = malloc(sizeof(char) * STRING_LENGTH);
                strcpy(*new_str, *str);
                strcat(*new_str, sep);
                //printf("nS: %s\n", *new_str);
                str++;
                new_str++;
            }
            *new_str = NULL;
            str = mark;
        }
    }
    return str;
}
