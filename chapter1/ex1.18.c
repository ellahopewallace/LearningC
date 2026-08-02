#include <stdio.h>

#define MAXLINE 1000

int getLine(char line[], int maxline);
void removeTrailing(char before[], char after[], int len);

int main(){
    int len;
    char line[MAXLINE];
    char stripped[MAXLINE];

    while ((len = getLine(line, MAXLINE)) > 0){
        removeTrailing(line, stripped, len);
        printf("%s", stripped);
    }
    return 0;
}


int getLine(char s[], int lim){
    int c, i;
    for (i=0; i<lim-1 && (c=getchar()) != EOF && c!= '\n'; ++i){
        s[i] = c;
    }
    if (c == '\n'){
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}

void removeTrailing(char before[], char after[], int len){
    int i = len-1;
    while (i > 0 && (before[i] == '\t' || before[i] == ' ')){
        --i;
    }
    for (; i>=0; i--){
        after[i] = before[i];
    }
}