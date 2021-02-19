// more examples of integer overflows

#include <stdio.h>

int main() {
// Truncation occurs when the value is assigned to a type that is too small to represent the resulting value
// Integers smaller than int are promoted to int or unsigned int before being operated on
    char a, b, c;
    a = 100;
    b = 90;
    c = a + b;  // Adding a and b exceeds the max size of signed char (+127)
    printf("Truncation: %d + %d = %d\n", a, b, c);

// A sign error is illustrated here
    int i = -5;
    unsigned short u;
    u = i; // Implicit conversion to smaller unsigned integer
    printf("u = %u\n", u); // There are sufficient bits to represent the value so no truncation occurs 
                           // The two’s complement representation is interpreted as a large signed value, so u = 65531
}