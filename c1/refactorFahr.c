#include <stdio.h>
// Exercise 1-15: Refactor cesliusFahr

#define LOWER 0 /* lower limit of temperature table */
#define UPPER 300 /* upper limit */
#define STEP 20 /* step size */

// Convert fahreheit to celsius
float F2C(float fahr) {
    return (5.0/9.0) * (fahr - 32.0);
}

/*  print Farhenheit-Celsius table
    for fahr = 0, 20, ..., 300  */
int main() {
    float fahr, celsius;
    fahr = LOWER;
    printf("Conversion table between fahrenheit and celsius: \n");
    printf("%6c \t\t %6c\n", 'F', 'C');
    while (fahr <= UPPER) {
        celsius = F2C(fahr);
        printf("%6.1f \t\t %6.1f\n", fahr, celsius);
        fahr = fahr + STEP;
    }
    return 0;
}