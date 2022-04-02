#include <stdio.h>
// Exercise 1-3: Modify to print heading


/* print Farhenheit-Celsius table
    for fahr = 0, 20, ..., 300 */
int main() {
    float fahr, celsius;
    int lower, upper, step;

    lower = 0; /* lower limit of temperature table */
    upper = 300; /* upper limit */
    step = 20; /* step size */

    fahr = lower;
    printf("Conversion table between fahrenheit and celsius: \n");
    printf("\t%3c \t %6c\n", 'F', 'C');
    while (fahr <= upper) {
        celsius = (5.0/9.0) * (fahr - 32.0);
        printf("\t%3.0f \t %6.1f\n", fahr, celsius);
        fahr = fahr + step;
    }
    return 0;
}