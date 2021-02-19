// an example illustrating the results of integer overflows on malloc()

#include <cstring>
#include <stdlib.h>
#include <stdio.h>

typedef char THING;

// an intentinally convoluted function that calculates the buffer size without any checks
// cryptic variable names and signed data types makes the problem more difficult to locate
int GetBufSize(int x, int y, int z) {
    short int temp = x * y * z;
    printf("temp = %d\n", temp);
    return temp;
}

THING * AllocThings(int a, int b, int c){
    THING *ptr;
    int bufsize = GetBufSize(a,b,c);
    ptr = (THING*)malloc(bufsize);
    return ptr;
}

int main(){
    //GetBufSize(110,220,330);

    //     THING *x = AllocThings(4,21,32); // this shoudl work just fine    
    THING *x = AllocThings(100,200,300);    // but these values result in an integer overflow
    printf("Allocated adress is %p\n", x);
    strcpy(x, "This is a long string");
    free(x);
}