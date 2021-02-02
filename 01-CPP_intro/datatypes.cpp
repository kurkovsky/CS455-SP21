// data types in C and C++

#include <iostream>
using namespace std;

int main(){
/*  primitive built-in data types:
    Boolean	                bool
    Character	            char
    Integer	                int
    Floating point	        float
    Double floating point	double
    Valueless	            void
    Wide character	        wchar_t -- platform specific */
    cout << "size of char: " << sizeof(char) << endl;
    cout << "size of int: " << sizeof(int) << endl;
    cout << "size of float: " << sizeof(float) << endl;
    cout << "size of double: " << sizeof(double) << endl;
    cout << "size of bool: " << sizeof(bool) << endl;
    cout << "size of wchar_t: " << sizeof(wchar_t) << endl;

/* type modifiers:
    signed
    unsigned
    short
    long */
    cout << "size of int: " << sizeof(int) << endl;
    cout << "size of short int: " << sizeof(short int) << endl;
    cout << "size of long int: " << sizeof(long int) << endl;

/* new type declaration with typedef */
    typedef unsigned char letter;
    letter letterA = 'A';
    cout << "Here's letter A: " << letterA << endl;

/* enumerated types */
    enum color {red, orange, yellow, green, blue, indigo, violet} c;
    c = blue;
    cout << "The value of c is " << c << endl;

    typedef enum {mon, tue, wed, thu, fri, sat, sun} day;
    day today = tue;

    int x = 5;
/* integer literals
    21      decimal
    0234    octal
    0x3A    hexidecimal
    51u     unsigned int
    9879879879875l     long
    30ul    unsigned long */

    return 0;
}