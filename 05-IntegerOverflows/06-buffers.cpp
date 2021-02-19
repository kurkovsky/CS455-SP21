// an exampel of integer overflows and their efects of improper buffer sizing
#include <climits>
#include <stdio.h>
#include <string.h>

// We need to ensure that any writes into buffers (both stack and heap buffers) 
// are safe by bounding to the destination buffer size
int ConcatBuffers(char *buf1, char *buf2, unsigned len1, unsigned len2) {
    const int bufsize = 255;  // this is where the two incoming buffers will be copied
    char buf[bufsize];
    if(len1 + len2 > bufsize) {
        printf("Buffer is too short!\n");
        return -1;
    }
    memcpy(buf, buf1, len1);
    memcpy(buf + len1, buf2, len2);
    // some app logic goes here
    return 0;
}

int main(){
    //unsigned l1 = 100, l2 = 150;
    //unsigned l1 = 100, l2 = 160;
    unsigned l1 = 100, l2 = 150;
    char b1[l1], b2[l2];

    for(int i=0; i<l1; i++) b1[i]=i;
    for(int i=0; i<l2; i++) b2[i]=i;

    l1 = UINT_MAX-10;
    ConcatBuffers(b1, b2, l1, l2);
}