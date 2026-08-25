#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAXWORD 100
#define MAXNUM 5
int pos;
struct tnode *addtree(struct tnode *, char *);
void treeToArray(struct tnode *, struct tnode *[]);
int getword(char *, int);
int mycmp(char *, char *, int);
int getnumfirsts(int);

struct tnode {              /* the tree node: */
    char *word;             /* points to the text */
    int count;              /* number of occurances */
    struct tnode *left;     /* left child */
    struct tnode *right;    /* right child */
};

int main(){
    struct tnode *root;
    char word[MAXWORD];
    struct tnode *words[MAXWORD];
    int numfirsts = getnumfirsts(MAXNUM);
    root = NULL;
    while (getword(word, MAXWORD) != EOF)
        if (isalpha(word[0]))
            root = addtree(root,word);
    pos = 0;
    treeToArray(root, words);
    if (pos < 2) return 0;
    if (mycmp(words[0]->word, words[1]->word, numfirsts) == 1)
        printf("%s\n", words[0]->word);
    for (int i=1; i<pos-1; i++){
        if (mycmp(words[i]->word, words[i-1]->word, numfirsts)==1 || mycmp(words[i]->word, words[i+1]->word, numfirsts)==1)
                printf("%s\n", words[i]->word);
    }
    if (mycmp(words[pos-1]->word,words[pos-2]->word, numfirsts)==1)
        printf("%s\n", words[pos-1]->word);
    return 0;
}

struct tnode *talloc(void);
char *mystrdup(char *);

/* addtree: add a node with w, at or below p */
struct tnode *addtree(struct tnode *p, char *w){
    
    int cond;

    if (p == NULL){     /* a new word has arrived */
        p = talloc();   /* make a new node */
        p->word = mystrdup(w);
        p->count = 1;
        p->left = p->right = NULL;
    }
    else if ((cond = strcmp(w, p->word)) == 0)
        p->count++;     /* repeated word */
    else if (cond < 0)  /* less than into left subtree */
        p->left = addtree(p->left, w);
    else
        p->right = addtree(p->right, w);
    return p;
}

/* treeToArray: in-order array of tree p */
void treeToArray(struct tnode *p, struct tnode *words[]){
    if (p != NULL){
        treeToArray(p->left, words);
        words[pos] = p;
        pos++;
        treeToArray(p->right, words);
    }
}

/* talloc: make a tnode */
struct tnode *talloc(void){
    return (struct tnode *) malloc(sizeof(struct tnode));
}

char *mystrdup(char *s){   /* make a duplicate of s */

    char *p;

    p = (char *) malloc(strlen(s)+1);   /* +1 for '\0' */
    if (p != NULL)
        strcpy(p, s);
    return p;
}

/* getword: get next word or character from input */
int getword(char *word, int lim)
{
    int c, getch(void);
    void ungetch(int);
    char *w = word;

    while (isspace(c = getch()))
        ;
    if (c != EOF)
        *w++ = c;
    if(!isalpha(c)){
        *w = '\0';
        return c;
    }
    for ( ; --lim > 0; w++){
        if (!isalnum(*w = getch())){
            ungetch(*w);
            break;
        }
    }
    *w = '\0';
    return word[0];
}

#define BUFSIZE 100
char buf[BUFSIZE];  /* buffer for ungetch */
int bufp = 0;       /* next free position in buff */

int getch(void){    /* get a (possibly pushed back) character */
    return (bufp > 0) ? buf[--bufp]: getchar();
}

void ungetch(int c){    /* push character back on input */
    if (bufp >= BUFSIZE)
        printf("ungetch: too many characters\n");
    else 
        buf[bufp++] = c;
}

int mycmp(char *s, char *t, int firsts){

    if (strlen(s) <= firsts || strlen(t) <= firsts){
        return 0;
    }

    for (int i=0; i<firsts; i++){
        if (s[i] != t[i]){
            return 0;
        }
    }
    if (strcmp(s,t) == 0){
        return 0;
    }
    return 1;
}

int getnumfirsts(int lim){
    char w[lim];
    char *wp = w;

    for ( ; --lim > 0; wp++){
        if (!isalnum(*wp = getch())){
            ungetch(*wp);
            break;
        }
    }
    *wp = '\0';
    return atoi(w);

}