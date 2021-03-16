// an example of a race condition in a multithreaded application based on 
// https://thispointer.com/c11-multithreading-part-4-data-sharing-and-race-conditions/

// compile with g++ wallet.cpp -pthread

#include <iostream>
#include <thread>
#include <vector>
#include <mutex>
using namespace std;

class Wallet{
private:
    int mMoney;
    mutex myMutex;  // a mutual exclusion will help us fix a race condition
public:
    Wallet(): mMoney(0) {}
    int getMoney() { return mMoney; }
    void addMoney(int money) {
        // race condition fix v1: use mutex lock/unlock
        // myMutex.lock();
 
        // race condition fix v2: use a lockguard
        // If a mutex is not unlocked at the end of function, 
        // a thread will exit without releasing the lock and other threads will keep waiting.
        // This can happen if an exception is thrown after locking the mutex.
        // std::lock_guard is a class template that implements the RAII for mutex, which avoids the above scenario.
        // RAII: Resource Acquisition Is Initialization, see https://en.cppreference.com/w/cpp/language/raii
        // lockGuard destructor will be called due to stack unwinding if an exception is thrown.
        lock_guard<mutex> lockGuard(myMutex);

        for(int i=0; i<money; i++) mMoney++;
        // Each thread increments the same “mMoney” member variable in parallel.
        // “mMoney++” is actually converted into three separate CPU commands:
        //      Load “mMoney” variable value M in register R
        //      Increment register’s value
        //      Update variable “mMoney” with register’s value
        //
        //      e.g. order of execution
        //      -------------------------
        //      thread 1      thread 2
        //      load M to R
        //                    load M to R
        //      inc R
        //                    inc R
        //      load R to M
        //                    load R to M

        // race condition fix v1
        // myMutex.unlock(); 

        // race condition fix v2: lockGuard destructor is called when lockGuard goes out of scope here
    }
};

int testMultithreadedWallet(){
    Wallet walletObject;        // we will work with a single Wallet object
    vector<thread> threads;     // using several threads running in parallel

    for(int i=0; i<5; i++)      // 5 threads are created; each will add 1000 to walletObject
        threads.push_back(thread(&Wallet::addMoney, &walletObject, 1000));
    
    for(int i=0; i<threads.size(); i++) 
        threads[i].join();      // ensure that all threads are done before returning from this function
    
    return walletObject.getMoney();
}

int main() {
    // run an experiment 100 times trying to add 5000 to the wallet
    for(int i=0; i < 100; i++) { 
        int value=testMultithreadedWallet();
        //cout << "Wallet: " << value << endl;
        if(value != 5000)  // the experiment may fail due to a race condition (without a mutex fix in place)
            cout << "Error at count " << i << " Wallet: " << value << endl;
    }
}