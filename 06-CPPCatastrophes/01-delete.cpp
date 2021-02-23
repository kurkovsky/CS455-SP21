/*
This example illustrates a situation when new[]/new is not matched correctly with delete[]/delete

In C++, you have two ways to allocate memory: new (for single objects) and new[] (for arrays).
When it's time to free up the memory, these need to be matched with proper calls to delete or delete[].

new[] adds a prefix to the allocated memory that stores the count of allocated objects
new does not do that. The count will be stored right before the returned pointer!

delete[] looks for the count to see how many times the destructor shoudl be called
delete does not need the count because teh destructor will be called just once

exploit:
manipulating the count of allocated objects leads to either overwriting correct data or
not deleting the  data that needed to be deleted
*/

#include <string.h>
#include <iostream>
using namespace std;

// this class is a setup for the second example in main()
class DummyClass {
    public:
        DummyClass();
        ~DummyClass();
    private:
        int data;
};

DummyClass::DummyClass() {
    data = 0;
    cout << "constructor" << endl;
}

DummyClass::~DummyClass() {
    cout << "destructor" << endl;
}

int main() {
// this example will work without a problem because we are using a POD (Plain Old Datatype)
// where no constructors are needed or called
    const int bufSize = 100;
    char* pChars = new char[bufSize];
    strncpy(pChars, "Hello there!", bufSize);
    cout << pChars << endl;
    delete pChars; // mismatched new[]/delete -- shoudl be using delete[] instead

// this example will lead to a crash because we are using a class
// which requires calling a destructor for every instance created with new
    const int testSize = 5;
    DummyClass *testData = new DummyClass[testSize];
    // some code goes here
    delete testData;
}