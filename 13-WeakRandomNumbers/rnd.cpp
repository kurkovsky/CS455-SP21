// this example illustrates three different ways of generating pseudo-random number sequences
#include <climits>
#include <cstdlib>
#include <ios>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <random>
using namespace std;

// Non-cryptographic pseudo-random number generators (non-cryptographic PRNG)
// can be used for statistical simulation because such experiments were designed to be repeatable
// Security applications require that attackers can’t guess numbers
// Guessing the seed is the source of vulnerability
void test_rand() {
    unsigned int rndNumber = 0;
    
    // add a source of entropy
    time_t t;
    srand((unsigned)time(&t));

    cout.setf(ios_base::hex, ios_base::basefield);
    for(int i = 0; i < 100; i++) {
        rndNumber = rand();
        cout << setw(8) << setfill('0') << rndNumber << " ";
        if( (i+1) % 10 == 0) cout << endl;
    }
}

// Cryptographic pseudo-random number generators (CRNGs)
// Key: securing the seed
// This CRNG implementaiton is based on UNIX urandom device supported by the kernel
void test_urandom() {
    ifstream urandom;
    urandom.open("/dev/urandom", std::ifstream::binary);
    if(!urandom.is_open()) {
        cout << "Could not open /dev/urandom" << endl;
        return;
    }

    unsigned int rndNumber = 0;
    cout.setf(ios_base::hex, ios_base::basefield);
    for(int i = 0; i < 100; i++) {
        urandom.read((char*)(&rndNumber), sizeof(rndNumber));
        cout << setw(8) << setfill('0') << rndNumber << " ";
        if( (i+1) % 10 == 0) cout << endl;
    }
    urandom.close();    
}

// This CRNG implementaiton is based on a C++ library
// https://en.cppreference.com/w/cpp/numeric/random
void test_random(){
    // create source of randomness, and initialize it with non-deterministic seed
    random_device r;
    seed_seq seed {r(), r(), r(), r(), r(), r(), r(), r(), r(), r()};
    mt19937 engine{seed};
            
    // a distribution that takes randomness and produces values in specified range
    uniform_int_distribution<> dist(0, INT_MAX);
    cout.setf(ios_base::hex, ios_base::basefield);
    for(int i = 0; i < 100; i++) {
        cout << setw(8) << setfill('0') << dist(engine) << " ";
        if( (i+1) % 10 == 0) cout << endl;
    }  
}

int main(){
    // test_rand();
    // test_urandom();
    test_random();
    return 0;
}