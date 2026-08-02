#include <stdio.h>

float fahrToCelsius(float fahr);

float celsiustoFahr(float celsius);

int main(){
    printf("celsius to fahrenheit\n");
    int lower, upper, step;
    float fahr;
    lower = 0;
    upper = 300;
    step = 20;
    fahr = lower;
    while (fahr <= upper){
        printf("%3.0f%6.1f\n", fahr, fahrToCelsius(fahr));
        fahr += step;
    }
    return 0;
}

float fahrToCelsius(float fahr){
    return (5.0/9.0)*(fahr-32);
}

float celsiusToFahr(float cel){
    return (9.0/5.0)*(cel+32);
}