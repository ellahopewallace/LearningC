#include <stdio.h>

#define lim 10

int main(){
    char c;
    for (int i=0; i<lim-1; i++){
        c = getchar();
        if (c == EOF){
            break;
        }
        else if (c== '\n'){
            break;
        }
    }
    return 0;
}