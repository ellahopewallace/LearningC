#include <stdio.h>
#include <stdbool.h>

void squeeze(char s1[], char s2[]){
    int index,i;
    bool delete;
    for (i=index=0; s1[i]!='\0'; i++){
        delete = false;
        for (int j=0; s2[j]!='\0'; j++){
            if (s1[i] == s2[j]){
                delete = true;
                break;
            }
        }
        if (!delete){
            s1[index++] = s1[i];
        }
    }
    s1[index] = '\0';
}