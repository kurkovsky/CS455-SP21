// an example of integer overflow resulting from invoking an operator

#include <climits>
#include <stdio.h>

// This function implements a faulty integer overflow check
// If you add two positive numbers together and the result is smaller than either of the inputs,
// this indicates a malfunction 
bool IsValidAddition(signed short x, signed short y) {
    if(x + y < x) return false;
    else return true;
}

// fixes the problem by forcing an explicit typecasting
bool IsValidAddition2(signed short x, signed short y) {
    if((signed short)(x + y) < x) return false;
    else return true;
}

int main() {
    signed short a = 5, b = 10; // these alues should be always OK, but setting b = SHRT_MAX woudl be problematic
    signed short c = a + b;

    // this example will fail
    if(IsValidAddition(a, b)) printf("%d + %d = %d: valid\n", a, b, c);
    else printf("%d + %d = %d: invalid\n", a, b, c);

    // but this one should always work
    if(IsValidAddition2(a, b)) printf("%d + %d = %d: valid\n", a, b, c);
    else printf("%d + %d = %d: invalid\n", a, b, c);
}