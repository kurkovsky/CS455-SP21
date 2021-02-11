/*
The following is an excerpt from "24 Deadly Sins..."

In C/C++, a function can be declared to take a variable number of arguments by specifying
an ellipsis (…) as the last argument. The problem is that the function being called
has no way to know—even at run time—just how many arguments are being passed in.
The most common set of functions to take variable-length arguments is the printf family:
printf, sprintf, snprintf, fprintf, vprintf, and so on.

The root cause of format string bugs is trusting user-supplied input without validation. 
In C/C++, format string bugs can be used to write to arbitrary memory locations, 
and the most dangerous aspect is that this can happen without tampering with adjoining memory blocks. 
This fine-grained capability allows an attacker to bypass stack protections and even modify very small portions of
memory. The problem can also occur when the format strings are read from an untrusted location the attacker controls.
*/

#include <stdio.h>

int main(int ac, char *av[]){
    // This is the proper way of using printf where every % placeholder is matched with a parameter:
    // printf("Hello world, my name is %s\n", av[0]);

    // An attacker could supply the format string from the command line:
    printf(av[1]); 
    /* try these examples:
    ./a.out Hello
    ./a.out Hello world
    ./a.out "Hello world"
    ./a.out %x              // Unsigned hexadecimal integer, read the stack, four bytes at a time, as far as you’d like
    ./a.out "%x %x"
    ./a.out %p              // pointer address, also can see if 32 or 64 bit system
                            // run again and see if Address Space Layout Randomization (ASLR) is used for this app
    */

    // %n: Nothing printed. The corresponding argument must be a pointer to a signed int.
    // The number of characters written so far is stored in the pointed location
    // An attacker could use the %n placeholder to write data into memory by manipulating the number of bytes in the format string
    unsigned int bytes;
    printf("%s%n\n", av[1], &bytes);
    printf("Your input was %d charaters\n", bytes);


    // mitigaiton strategies at code review
    /*
    printf(user_input);         // a missing parameter--format string may be replaced with the user input
    
    printf(msg_format, arg1, arg2);    // verify where msg_format is stored and how well it is protected:
    if(verify msg_format) {
        printf(msg_format, arg1, arg2);
    }
    */

    return 0;
}