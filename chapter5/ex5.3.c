
void pstrcat(char *s, char *t){
    while (*s != '\0') /* find end of s */        
        s++;
    while ((*s = *t) != '\0'){ /* copy t */
        s++;
        t++;
    }
}