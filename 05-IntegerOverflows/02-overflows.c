// a practical example of integer overflows 

#include <stdio.h>

int main(){
    short  sintExample = 0x0100; // 256;
    const long MAX_LEN = 0x7fff; // 32767 
    long lintExample = (long) sintExample;

    printf("short (%d bytes): %#06x; long (%d bytes): %#010lx\n", 
        (int)sizeof(sintExample), sintExample, (int)sizeof(lintExample), lintExample);

    if(sintExample < MAX_LEN) // comparing long to int results in implicit typecasting
                              // i.e. upcasting sintExample from a signed 16-bit integer to a signed 32-bit integer
        printf("PASSED: %#06x (%d)\n", sintExample, sintExample);
    else 
        printf("FAILED: %#06x (%d)\n", sintExample, sintExample); 
    
    sintExample = 0xffff;  // 65535
    lintExample = (long) sintExample;    
    printf("short (%d bytes): %#06x; long (%d bytes): %#010lx\n", 
        (int)sizeof(sintExample), sintExample, (int)sizeof(lintExample), lintExample);

    if(sintExample < MAX_LEN) // ERROR result!!!!
        printf("PASSED: %#06x (%d)\n", sintExample, sintExample);
    else 
        printf("FAILED: %#06x (%d)\n", sintExample, sintExample); 
}