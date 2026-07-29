#include <stdio.h>

int main(){
    float fahr, celsius, step;
    int lower, upper;

    lower = 0;
    upper = 300;
    step = 20;

    celsius = lower;
    printf("Celsius to fahrenheit\n");
    while (celsius <= upper){
        fahr = (9.0/5.0)*(celsius+32);
        printf("%3.0f%6.1f\n", celsius, fahr);
        celsius += step;
    }
    return 0;
}