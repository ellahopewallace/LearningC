#include <stdio.h>
#include <ctype.h>

int getch(void);
int ungetch(int);

/* getfloat: get next float from input into *pn */
int getfloat(float *pn){
    int c, sign;
    float decimal, decimalPoint;
    while (isspace(c=getch()))     /* skip white space*/
        ;
    if (!isdigit(c) && c != EOF && c!='+' && c!='-' && c!='.'){
        ungetch(c);     /* invalid */
        return 0;
    }
    sign = (c == '-') ? -1:1;
    if (c == '+' || c == '-'){
        if (!isdigit(c=getch()) && c!= '.' && c!=EOF){
            ungetch(c);
            ungetch(sign==-1 ? '-':'+');
            return 0;
        }
    }
    for (*pn = 0; isdigit(c); c=getch()){
        *pn = 10.0 * *pn + (c-'0');
    }
    if (c == EOF){      /* being lenient with implied float as dec */
        *pn *= sign;
        return c;
    }
    if (c != '.'){      /* invalid float if first non-dig isnt '.'*/
        ungetch(c);        
        *pn *= sign;    /* invalid, but try make pn as useful as possible */
        return 0;
    }
    if ((c = getch())== EOF){
        *pn *= sign;
        return 0;
    }
    if (!isdigit(c)){
        ungetch(c);
        ungetch('.');
        *pn *= sign;    /* invalid, but try make pn as useful as possible */
        return 0;
    }
    decimalPoint = 0.1;
    decimal = decimalPoint * (c-'0');
    decimalPoint *= 0.1;
    c = getch();
    for ( ; isdigit(c); c=getch()){
        decimal = decimal + (c-'0')*decimalPoint;
        decimalPoint *= 0.1;
    }
    *pn += decimal;
    *pn *= sign;
    if (c != EOF){
        ungetch(c);
    }
    return c;
}