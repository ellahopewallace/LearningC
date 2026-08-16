
void setbits(x,p,n,y){
    unsigned bitsFromY = getbits(y, p, n);
    x = x & 2
    x = x | bitsFromY;
}

unsigned getbits(unsigned x, int p, int n){
    return (x >> (p+1-n)) & ~(~0 << n);
}