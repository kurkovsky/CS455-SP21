/* Many security risks are possible when developers do not handle an error condition correctly.
Possibilities:
* Ignoring errors--e.g. printf() return value is never checked (-1==error);
    erors in open()/fopen() will result in failing read()/fread()
    Java forces your code to catch exceptions that many funciton throw--except NullPointerException!
    Even then, many programmers only create empty exception hanlders or just abort the program.
* Using useless return values--some library functions are not well-designed
        e.g. strncpy() returns a ptr to the destination buffer, even if it overflows
* Misinterpreting errors
    Different functions return the same value with different semantics.
    e.g. malloc(size) returns 0 if it runs out of memory
                            a valid ptr if size==0
        realloc(ptr, new_size) returns 0 if new_size==0
                               returns 0 if it runs out of memory
        fgets() returns 0 if there's an IO error
                returns 0 if at EOF (must use feof()/ferror() to tell the difference)
* Using non-error return values
    e.g. 'special value': negative==error, positive results all valid
*/

#include <stdio.h>
#include <string.h>
#include <iostream>
using namespace std;

int main() {
    const int numChars=10;
    char dest[numChars];
    char src[]="0123456789";

/*  this is amuch better way: avoid the vulnerability instead of mitigating the results
    if(strlen(src)>=numChars)
        cerr << "dest too small for src" << endl;
    else{. */
        char *test=strncpy(dest, src, numChars);  // strncpy does NOT return a 0 in case of overflows or other errors
        if(test) {                                // therefore, this condition will NEVER fail
            cout << "test string: " << test << endl;
        }
 /*   } */
}