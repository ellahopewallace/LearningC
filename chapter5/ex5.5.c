#include <stdio.h>
#include <string.h>

char * mystrncpy(char *, char *, int);
char * mystrncat(char *, char *, int);
int mystrncmp(char *, char *, int);

#define MAXWORD 100

int main(){
    char str1[] = "ella";
    char *p1 = str1;
    char str2[] = "wallace";
    char *p2 = str2;
    char str3[MAXWORD];
    char *p3 = str3;
    mystrncpy(p3, p1, 2);
    printf("%s %s\n", "Should be el:", str3);
    printf("Comparing %s and %s: %d\n", p3, p1, mystrncmp(p3,p1,100));
    char str4[] = "la";
    char *p4 = str4;
    mystrncat(p3,p4,2);
    printf("%s\n", p3);
    printf("comparing %s and %s: %d\n", p3, p1, mystrncmp(p3,p1,5));
    mystrncat(p1, p2, 7);
    printf("%s\n", p1);
    return 0;
}

/* strncpy: copies at most n characters of t to s */
char * mystrncpy(char *s, char *t, int n){
    char *start = s;
    while (n-- > 0){
        if (*t) *s++ = *t++;
        else *s++ = '\0';
    }
    return start;
}

/* strncat: concatenate at most n characters of t to s */
char * mystrncat(char *s, char *t, int n){
    char *start = s;
    while (*s){
        s++;
    }
    while (n-- > 0){
        if (!*t){
            break;
        }
        *s++ = *t++;
    }
    *s = '\0';
    return start;
}

/* compare at most n charaters of string s to string t 
return 0 is equal, >0 if s>t, <0 if s<t*/
int mystrncmp(char *s, char*t, int n){
    while (n-- >0){
        if (!*s && *t) return -1;
        if (!*t && *s) return 1;
        if (*s++ != *t++){
            return *--s - *--t;
        }
    }
    return 0;
}