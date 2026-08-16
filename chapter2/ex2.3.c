#include <stdio.h>
#include <string.h>

void htois(char og[]){
    for (int i=0; i<og.length; i++){
        og[i] = og[i] - '0';
    }
}