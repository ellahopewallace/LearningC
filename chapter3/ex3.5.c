#include <stdio.h>

void itob(int n, char s[], int b){
    int i, sign;
    if ((sign=n)<0){
        n = -n;
    }
    i=0;
    do {
        int digit = n % b;
        if (digit<10){
            s[i++] = digit + '0';
        }
        else s[i++] = digit - 10 + 'a';
    }
    while ((n/=b)>0);
    if (sign < 0){
        s[i++] = '-';
    }
    s[i] = '\0';
    reverse(s);
}