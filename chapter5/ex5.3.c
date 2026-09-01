
/* pstrcat: pointer version of strcat */
/* concatentates t to the end of s */
void pstrcat(char *s, char *t){
    while (*s) /* find end of s */   
        s++;   
    while (*s++ = *t++);  /* copy t */
}