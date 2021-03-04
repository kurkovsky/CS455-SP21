// several example of possibly improper exception handling in C++

#include <iostream>
using namespace std;

// this version illustrates the proper exception handling when running out of memory
void memoryTest1(size_t memSize) {
    try {
        char *tmp = new char[memSize];
        cout << "Allocating " << memSize << " bytes of memory..." << endl;
        // some logic goes here...
        delete[] tmp;
    }
    catch(...) {    // catch-all handler catches ALL exceptions
        throw "Out of memory";
    }
}

// this version illustrates the dangers of using nothrow
void memoryTest2(size_t memSize) {
    try {
        char *tmp = new (std::nothrow) char[memSize]; // nothrow prevents the new operator from raising an exception
                                                      // catch() no longer catches the exception
        cout << "Allocating " << memSize << " bytes of memory at " << (void*) tmp << endl;
        // some logic goes here...
        delete[] tmp;
    }
    catch(...) {    // no excetions thrown by new() will be caught due to nothrow
        throw "Out of memory";
    }
}

// copied from the previous example and adjusted data types
size_t division(size_t a, int b) {
    if(b==0) {
        throw std::runtime_error("Division by zero");
    }
    return a/b;
}

// this verision illustrates the proper way to catch mutliple kinds of exceptions
// try memsize=100000000000000000 to get the out-of-memory exception
void memoryTest3(size_t memSize, int factor) {
    try {
        size_t properMemSize = division(memSize, factor);
        char *tmp = new char[memSize];
        cout << "Allocating " << memSize << " bytes of memory at " << (void*) tmp << endl;
        // some logic goes here...
        delete[] tmp;
    }
    catch(std::bad_alloc& err) {
        throw "Out of memory";
    }catch(std::runtime_error& err) {
        throw err.what();
    }
    catch(...) {
        throw "Some bad stuff just happened!";
    }
}


int main() {
    size_t size = 0;
    int factor = 0;
    cout << "memory size = ";
    cin >> size;
    cout << "factor = ";
    cin >> factor;

    cout << "size_t is " << sizeof(size) << endl;

    try {
        // memoryTest1(size);
        // memoryTest2(size);
        memoryTest3(size, factor);
    } catch (const char* msg) {
        cerr << "Exception: " << msg << endl;
    }
}