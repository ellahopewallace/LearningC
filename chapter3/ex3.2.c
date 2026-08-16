#include <stdio.h>

void escape(char s[], char t[]){
    int i, j;
    i = j = 0;
    while (s[i] != '\0'){
        switch(s[i]){
            case '\n':
                t[j++] = '\\';
                t[j] = 'n';
                break;
            case '\t':
                t[j++] = '\\';
                t[j] = 't';
                break;
            default:
                t[j] = s[i];
        }
        i++;
        j++;
    }
    t[j] = s[i];
        
}