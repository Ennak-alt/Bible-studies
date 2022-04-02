// Exercise 1-4: Write a program to print the corresponding Celsius to 
// Fahrenheit
#include <stdio.h>

int main() {
    float fahr, celsius;
    int lower, upper, step;

    lower = 0; /* lower limit of temperature table */
    upper = 300; /* upper limit */
    step = 20; /* step size */

    celsius = lower;
    printf("Conversion table between fahrenheit and celsius: \n");
    printf("\t%3c \t %6c\n", 'C', 'F');
    while (celsius <= upper) {
        fahr = celsius / (5.0/9.0) + 32;
        printf("\t%3.0f \t %6.1f\n", celsius, fahr);
        celsius = celsius + step;
    }
    return 0;
}