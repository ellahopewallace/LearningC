#include <stdio.h>

int main(){
    int c;
    while ((c = getchar()) != EOF){
        if (c == '\t' || c == '\b' || c == '\\'){
            putchar('\\');
            if (c=='\t'){
                putchar('t');
            }
            else if (c=='\b'){
                putchar('b');
            }
            else if (c == '\\'){
                putchar('\\');
            }
        }
        else{
            putchar(c);
        }
    }
    return 0;
}