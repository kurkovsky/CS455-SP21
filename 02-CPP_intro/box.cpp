// a simple illustration of some object-oriented features of C++
// also: exception handling

#include <iostream>
#include <ctime>
#include <stdexcept>

using namespace std;

class Box{
    private:
        int length, width, depth;
        int id;
    public:
        Box();
        Box(int l, int w, int d);
        ~Box();
        void Hi();
        int getVolume();
        void Shrink(int factor);
};

Box::Box(){
    length=width=depth=0;
    id = std::rand() % 100;     // a unique id in teh range 0..99
}

Box::Box(int l, int w, int d) {
    length=l;
    width=w;
    depth=d;
    id = std::rand() % 100;
}

Box::~Box(){
    cout << id << ": You are killing me..." << endl;
}

void Box::Hi(){
    cout << id << ": Hi, I'm a box (" << length << "x" << width << "x" << depth << ")" << endl;
}

int Box::getVolume(){
    return length * width * depth;
}

void Box::Shrink(int factor){   // divides all dimensions of the box by teh value of factor
    if(factor==0) {     // exclude teh possibility of division by zero
        throw runtime_error("Attempted to divide by zero");
    }
    length = length / factor;
    width /= factor;
    depth /= factor;
}

void scopeTest() {  // illustrate how constructors/destructors work with local objects
    Box c(4,5,6);
    c.Hi();
}

Box* dynamicTest() {    // illustrate how constructors/destructors work with dynamically allocated objects
    Box *d = new Box(1,2,3);
    d->Hi();
    return d;
}

int main() {
    std::srand(std::time(nullptr));     // seed teh random number generator

    scopeTest();

    Box a, b(3,4,5);
    a.Hi();
    b.Hi();
    cout << "Volume of a is " << a.getVolume() << endl;
    cout << "Volume of b is " << b.getVolume() << endl;

    b.Shrink(2);
    b.Hi();

    try {
        b.Shrink(0);
    } catch (runtime_error &e) {
        cout << "Exception occurred: " << e.what() << endl;
    }
    b.Hi();


    Box *x = dynamicTest();
    cout << "Volume of x is " << x->getVolume() << endl;
    delete x;

    return 0;
}