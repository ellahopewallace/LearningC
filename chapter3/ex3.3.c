
void expand(char s1[], char s2[]){
    int i, j, start, end;
    j = 0;
    start = end = '\0';
    for (i=0; s1[i] != '\0'; i++){
        start = s1[i];
        if ('A' <= start && start <= 'Z'
            || 'a' <= start && start <= 'z'
            || '0' <= start && start <= '9'){
            if (s1[++i] == '-'){
                end = s1[++i];
            }
            else {
                end = start;
            }
        }
        else {
            end = start;
        }
        if (end == '\0'){
            s2[j++] = start;
            s2[j++] = '-';
        }
        else for (; start<=end; start++){
            s2[j++] = start;
        }
    }
    s2[j] = '\0';
}