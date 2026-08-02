#include <stdio.h>
#include <stdbool.h>

int main(){
    int c;
    bool lastOneWasBlank = false;
    while ((c=getchar()) != EOF){
        if (lastOneWasBlank && c == ' '){
            continue;
        }
        else{
            putchar(c);
        }
        if (c == ' '){
            lastOneWasBlank = true;
        }
        else{
            lastOneWasBlank = false;
        }
    }
    return 0;
}