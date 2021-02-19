// an example illustrating teh basics of integer overflows

#include <climits>
#include <stdio.h>

int main(){
    int i;
    i = INT_MAX;
    printf("i = %d\n", i);
    i++;
    printf("i = %d\n", i);

    unsigned int uintj; // Hungarian notation might help spotting potential problems later https://en.wikipedia.org/wiki/Hungarian_notation
    uintj = UINT_MAX;
    printf("j = %u\n", uintj);
    uintj++;
    printf("j = %u\n", uintj);

    i = INT_MIN;
    printf("i = %d\n", i);
    i--;
    printf("i = %d\n", i);

    // It is very difficult to spot a problem, outside of the context where the variables are declared
    // Using variable names with prefixes (Hungarian notation) may help
    uintj = 0;
    printf("j = %u\n", uintj);
    uintj--;
    printf("j = %u\n", uintj);
}