#include <stdio.h>

int binsearch(int x, int v[], int n){
    int lo, mid, hi;
    lo = 0;
    hi = n-1;
    mid = lo + (hi-lo) / 2;
    while (lo <= hi && mid != x){
        mid = lo + (hi-lo) / 2;
        if (x < v[mid]){
            hi = mid-1;
        }
        else {
            lo = mid +1;
        }
    }
    if (mid == x){
        return mid;
    }
    return -1;
}