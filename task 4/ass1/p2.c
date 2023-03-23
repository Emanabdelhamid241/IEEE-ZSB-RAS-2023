// c code to add 2 complex numbers
#include <stdio.h>
typedef struct complex {
    float real;
    float imag;
} complex;
// function to add two complex numbers
complex add(complex n1, complex n2) {
    complex t;
    t.real = n1.real + n2.real;
    t.imag = n1.imag + n2.imag;
    return (t);
}

int main() {
    // define 2 complex numbers and result
    complex n1, n2, result;
// get two complex numbers from user
    printf("For 1st complex number \n");
    printf("Enter the real and imaginary parts: ");
    scanf("%f %f", &n1.real, &n1.imag);
    printf("\nFor 2nd complex number \n");
    printf("Enter the real and imaginary parts: ");
    scanf("%f %f", &n2.real, &n2.imag);

    result = add(n1, n2);
// print the result 
    printf("Sum = %.1f + %.1fi", result.real, result.imag);
    return 0;
}

