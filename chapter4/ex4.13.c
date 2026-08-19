#include <stdio.h>
#include <string.h>

/* recRev: recursively reverse string s in place */
void reverse (char s[], int left, int right){
    if (left < right){
        int temp = s[left];
        s[left++] = s[right];
        s[right--] = temp;
        reverse(s, left, right);
    }
}

int main(){
    char word[] = "ella";
    printf("%s\n", word);
    reverse(word,0,strlen(word)-1);
    printf("%s\n", word);
    return 0;
}