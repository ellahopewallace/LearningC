#include <stdio.h>

int main(){
    int length, c;
    length=0;
    while ((c=getchar()) != EOF){
        if (c == ' ' || c == '\t' || c == '\n'){
            for (int i=0; i<length; i++){
                putchar('-');
            }
            putchar('\n');
            length = 0;
        }
        else{
            length++;
        }
    }
    return 0;
}