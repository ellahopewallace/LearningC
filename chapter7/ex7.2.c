#include <stdio.h>
#include <ctype.h>

#define FORMAT "%X"     /* hexadecimal, switch here to "%o" for octal */ 
#define MAXLINELEN 50

int main()
{
    int c;
    int count = 0;

    while ((c = getchar()) != EOF){
        if (c == '\n')
            count = 0;
        if (count>MAXLINELEN){
            putchar('\n');
            count = 0;
        }
        if (isgraph(c) || isspace(c)){
            putchar(c);
            count++;
        }
        else{
            count += printf(FORMAT, c);
        }
    }
    return 0;
}