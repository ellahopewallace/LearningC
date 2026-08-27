#include <stdio.h>
#include <ctype.h>
#include <string.h>

char *removedir(char *);

int main(int argc, char *argv[])
{
    int c;

    if (argc == 0){
       printf("%s\n", "error: unspecified conversion.\n");
    }

    if (strcmp(removedir(argv[0]), "lower") != 0 && strcmp(removedir(argv[0]), "upper") != 0){
        printf("%s\n", "invalid conversion.\n");
        return 1;
    }
    while ((c = getchar()) != EOF){
        strcmp(removedir(argv[0]), "lower") == 0 ? putchar(tolower(c)) : putchar(toupper(c));
    }
    return 0;
}

char *removedir(char *s)
{
    char *p;
    char *arg;

    for(arg = p = s; *p != '\0'; p++)
        if (*p == '/' || *p == '\\')
            arg = p +1;
    return arg;
}