#include<stdio.h>
#include<string.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>


#define NUM_THREADS 2
#define NUM_INCREMENTS 1000000000


pthread_mutex_t lock;



int counter = 0;  // shared variable

// Thread function
void *thread_func(void *arg) {

    pthread_mutex_lock(&lock);

    
    int * th_id = (int*) arg;

    pthread_t    self;
    //self = pthread_self();
    for (int i = 0; i < NUM_INCREMENTS; i++) {
        counter++;
        //printf("increment from thread id:%lu: \n",self);
    }

    pthread_mutex_unlock(&lock);

    pthread_exit(NULL);
}

int main() {
    pthread_t threads[NUM_THREADS];
    int rc;

     if (pthread_mutex_init(&lock, NULL) != 0)
    {
        printf("\n mutex init failed\n");
        return 1;
    }

    // Create threads
    for (int t = 0; t < NUM_THREADS; t++) {
        rc = pthread_create(&threads[t], NULL, thread_func, &t);
        if (rc) {
            printf("ERROR: return code from pthread_create() is %d\n", rc);
            exit(EXIT_FAILURE);
        }
    }

    // Wait for threads to finish
    for (int t = 0; t < NUM_THREADS; t++) {
        rc = pthread_join(threads[t], NULL);
        if (rc) {
            printf("ERROR: return code from pthread_join() is %d\n", rc);
            exit(EXIT_FAILURE);
        }
    }
    pthread_mutex_destroy(&lock);

    printf("Counter value: %d\n", counter);
    pthread_exit(NULL);
}
