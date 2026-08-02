#include <stdio.h>
#define MAXLINE 1000

int getLine(char line[], int maxline);
void reverse(char s[], int length);

int main(){
    int len;
    char line[MAXLINE];

    while ((len = getLine(line, MAXLINE))>0){
        reverse(line, len);
        printf("%s", line);
    }
}

int getLine(char s[], int lim){
    int c, i;
    for (i=0; i<lim-1 && (c=getchar()) != EOF && c!='\n'; ++i){
        s[i] = c;
    }
    if (c == '\n'){
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}

void reverse(char s[], int length){
    int i = 0;
    int j = length-2;
    while (i<j){
        char temp = s[i];
        s[i] = s[j];
        s[j] = temp;
        i++;
        j--;
    }
    s[length-1] = '\n';
}