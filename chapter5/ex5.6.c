#include <stdio.h>
#include <ctype.h>

/* pgetline: pointer version of getline */
/* read a line into s, return a pointer to it */
char * pgetline(char *s, int linemax)
{
    int c;
    char *linestart = s;

    while ((c=getchar()) != EOF && c != '\n' && --linemax >0){
        *s++ = c;
    }
    if (c == '\n'){
        *s++ = c;
    }
    *s = '\0';

    return linestart;
}

/* patoi: pointer version of atoi */
/* convert s to integer */
int patoi(char *s)
{
    int sign, n = 0;

    while (isspace(*s)){
        s++;
    }

    sign = (*s == '-') ? -1:1;
    if (*s =='+' || *s=='-'){
        s++;
    }

    while (*s >= '0' && *s <= '9'){
        n = 10 * n + (*s++ - '0');
    }
    return sign * n;
}

/* preverse: pointer version of reverse */
/* reverse string s in place */
void preverse(char *s)
{
    char *start = s;
    char *end = s;
    int len = 0;
    while (*s != '\0'){
        end = s++;
        len++;
    }
    int mid = len/2;
    while (mid-- > 0){
        char temp = *start;
        *start++ = *end;
        *end-- = temp;
    }
}


/* pitoa: pointer version of itoa */
/* convert n to characters in s and return s */
char * pitoa(int n, char *s)
{
    int sign;
    char *start = s;

    if ((sign = n) < 0)     /* record sign */
        n = -n;

    do{
        *s++ = n % 10 + '0';
    } while ((n /= 10)>0);
    if (sign < 0)
        *s++ = '-';
    *s ='\0';
    preverse(start);
    return start;
}

/* pstrindex: pointer version of strindex */
/* return pointer to t in s, null if does not exist */
char * pstrindex(char *s, char *t)
{
    char *tstart = t;
    char *match = s;
    while (*s != '\0' && *t != '\0'){
        if (*s == *t){
            t++;
            s++;
        }
        else {
            t = tstart;
            if (*++match == '\0') return NULL;
            s = match;
            if (*s != '\0' && *s != *t){
                s++;
            }
            match = s;
        }
    }
    if (*t == '\0') return match;
    return NULL;
}

/* pgetop: pointer version of getop */
/* get next operator or numeric operand */
char * getop(char *s)
{
    int c;
    char *t = s;

    while ((*s = c = getch()) == ' ' || c == '\t'){
    }
    *++s = '\0';
    if (!isdigit(c) && c != '.'){
        return t;       /* not a number */
    }
    if (isdigit(c)){    /* collect integer part */
        while (isdigit(*s++ = c = getch()))
            ;
    }
    if (c == '.')       /* collect fraction part */
        while (isdigit(*s++ = c = getch()))
            ;
    *--s = '\0';
    if (c != EOF)
        ungetch(c);
    return t;
}