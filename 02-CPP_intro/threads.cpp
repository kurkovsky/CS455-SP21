// a simple multi-threaded program
// compile: g++ threads.cpp -lpthread

#include <iostream>
#include <string.h>
#include <pthread.h>

using namespace std;

#define NUM_THREADS 5

void *PrintHello(void *threadid) {
   long tid;
   tid = (long)threadid;
   cout << "Hello World! Thread ID, " << tid << endl;
   pthread_exit(NULL);
}

struct thread_data {  // used to illustrate how to pass larger amounts of data into a thread
   int  thread_id;
   char message[100];
};
void *PrintHello2(void *threadarg) {
   struct thread_data *my_data;
   my_data = (struct thread_data *) threadarg;

   cout << "Thread ID : " << my_data->thread_id ;
   cout << " Message : " << my_data->message << endl;

   pthread_exit(NULL);
}


int main () {
    pthread_t threads[NUM_THREADS];
    int rc;
    long i;

    struct thread_data td[NUM_THREADS];

    for( i = 0; i < NUM_THREADS; i++ ) {
        cout << "main() : creating thread, " << i << endl;

        // a simple example when we pass only a single number into a thread
        //rc = pthread_create(&threads[i], NULL, PrintHello, (void *)i);
        

        td[i].thread_id = i;
        sprintf(td[i].message,"This is message # %ld", i);
        // a more complex example when we pass a record into a thread
        rc = pthread_create(&threads[i], NULL, PrintHello2, (void *)&td[i]);

        if (rc) {
            cout << "Error:unable to create thread," << rc << endl;
            exit(-1);
        }
    }
    pthread_exit(NULL);
    return 0;
}
