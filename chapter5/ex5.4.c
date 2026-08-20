#include <stdio.h>

int strend(char *s, char *t){
    char *startT = t;
    int lenT = 0;
    while (*t++ != '\0'){
        lenT++;
    }
    lenT++;
    t = startT;
    char *startS = s;
    int lenS = 0;
    while (*s++ != '\0'){
        lenS++;
    }
    lenS++;
    s = startS;
    for (int i=0; i<lenS-lenT; i++){
        s++;
    }
    while (*s != '\0'){
        if (*s != *t){
            return 0;
        }
        s++;
        t++;
    }
    return 1;
}

int main(){
    char *s = "eee";
    char *t = "ee";
    printf("should be 1: %d\n", strend(s,t));
    t = "el";
    printf("should be 0: %d\n", strend(s,t));
}