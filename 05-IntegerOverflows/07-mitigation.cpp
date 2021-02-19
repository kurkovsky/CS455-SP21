/*
1.
use unsigned whenever possible for variables
use size_t type for sizes
    sizeof() always returns size_t
    number of bytes is implementation-specific
*/

/*
2.
figure out the max number of elements that can be allocated in a buffer:
    size = (elements * sizeof (element)) + sizeof (header)
But size must be <= MAX_INT, so:
    MAX_INT <= (elements * sizeof (element)) + sizeof (header)
or:
    MAX_INT – sizeof (header) <= elements * sizeof (element)
and then:
    elements >= (MAX_INT – sizeof (header)) / sizeof (element)
*/

/*
3. do not use 'tricks' for checking

int a, b, c;
c = a + b;
if(a ^ b ^ c < 0) return BAD_INPUT;

// or
int a, b, c;
c = a * b;
if(c < 0) return BAD_INPUT;
*/

/*
4. write-out casts as they happen: annotate the code with the exact casts that happen, depending
on the various operations in play

unsigned int x;
short a, b;

if( a + b < x) DoSomething();
==>
if( (int)(a + b) < x ) DoSomething();  // because of the addition operator
==>
if( (unsigned int)(int)(a + b) < x ) DoSomething();  // because of comparison with unsigned int x
==>
the results of the addition aren’t a
problem, because anything you can fit into two shorts can be added and fit into an int.
The cast to unsigned may be a problem if the intermediate result is negative.
*/


void foo();

int main (){
    unsigned int x;
    short a, b;
    if((unsigned int)(int)(a + b) < x) foo();
}