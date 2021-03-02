// a simple example of exception handling in C++

#include <iostream>
using namespace std;

// this function checks for division by zero and throws an exception
double division(int a, int b) {
    if(b==0) {
        throw "Division by zero";
    }
    return (double) a/b;
}

int main() {
    int x, y;

    cout << "x = ";
    cin >> x;
    cout << "y = ";
    cin >> y;

    cout << "x = " << x << "; y = " << y << endl;

    double z;
    try {
        z = division(x, y);
        cout << x << " / " << y << " = " << z << endl;
    } catch (const char *msg) {
        cerr << "Exception: " << msg << endl;
    }
}