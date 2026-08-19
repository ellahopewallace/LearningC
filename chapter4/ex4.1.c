#include <stdio.h>
#include <string.h>

int strrindex(char s[], char t[]);

int main(){
    char wholeName[] = "bella";
    char aMatch[] = "el";
    char noMatch[] = "els";
    printf("Should be a match %d\n", strrindex(wholeName, aMatch));
    printf("Isn't a match %d\n", strrindex(wholeName, noMatch));
}

int strrindex(char s[], char t[]){
    int i, pointerS, pointerT;
    for (i=strlen(s)-1; i>=0; i--){
        for (pointerS=i, pointerT=strlen(t)-1; pointerT>=0 && s[pointerS]==t[pointerT]; pointerS--,pointerT--){
        }
        if (pointerT<0){
            return pointerS+1;
        }
    }
    return -1;
}