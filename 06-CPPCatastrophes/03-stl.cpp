// STL is a part of the standard C/C++ library
// https://www.cplusplus.com/reference/stl/ is a good reference
// STL consists of containers, algorithms, and iterators
// While vectors aren’t completely safe, they do prevent a substantial number of problems

#include <iostream>
#include <vector>
#include <algorithm> // needed for reverse()

using namespace std;

typedef int Foo;

// factored out from main()
template <class T>
void printWithIndex(vector<T> const &myVec) {
    for(int i = 0; i < myVec.size(); i++) {
        cout << "value of vec [" << i << "] = " << myVec[i] << endl;
    }
}

// factored out from main()
template <class T>
void printWithIterator(vector<T> const &myVec) {
    typename vector<T>::const_iterator v;
    v = myVec.begin();
    while( v != myVec.end()) {
        //                            index of v              value of v
        cout << "value of vec [" << v - myVec.begin() << "] = " << *v  << endl;
        v++;
    }
}

int main() {
    // create a vector to store int
    vector<Foo> vec;
    const int maxFoo=5;

    // display the original size of vec
    cout << "Uninitialized vector size = " << vec.size() << endl;

    // push maxFoo values into the vector
    for(int i = 0; i < maxFoo; i++) {
        vec.push_back(i);
    }

    // display extended size of vec
    cout << "Initialized vector size = " << vec.size() << endl;

    // access maxFoo values from the vector using an index 
    cout << "Scan vec using an index..." << endl;
    // this code is factored out into printWithIndex()
    //for(int i = 0; i < maxFoo; i++) 
    //    cout << "value of vec [" << i << "] = " << vec[i] << endl;
    
    // the above code is factored out into this function
    printWithIndex(vec);


    // use iterator to access the values
    cout << "Scan vec using an iterator..." << endl;
    // this code is factored out into printWithIterator()
/*    vector<Foo>::iterator v = vec.begin();
    while( v != vec.end()) {
        //                            index of v              value of v
        cout << "value of vec [" << v - vec.begin() << "] = " << *v  << endl;
        v++;
    }
*/
    // the above code is factored out into this function
    printWithIterator(vec);

    // use an algorithm to reverse the vector
    // other algorithms: sort, max/min, count, find, binary search, u/l bound, etc
    cout << "Reverse with an algorithm..." << endl;
    reverse(vec.begin(), vec.end());
    printWithIterator(vec);

    return 0;
}
