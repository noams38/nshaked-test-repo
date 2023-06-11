#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>

#define NUM_THREADS 4
#define NUM_COMMANDS 5

// Define the command structure

typedef struct {
    char * name ;
    int duration;
}Command;



// Define the worker function


void *worker (void *arg)
{
    clock_t start, end;
    Command * command = (Command *)arg;
    int durtation;

    // Start the clock
    start = clock();


    printf("worker stareted for command %s \n",command->name);
    sleep(command->duration);
    printf("worker enddded  for command %s \n",command->name);


    
    end = clock();
    //update command DURATION 
    durtation = (end - start) / CLOCKS_PER_SEC;
    printf("worker command %s  worker Duration %d \n",command->name,durtation);
    free(command);
    pthread_exit((void *)&durtation);

}



int main() {
    pthread_t threads[NUM_THREADS];
    Command* commands[NUM_COMMANDS];
    int durations[NUM_COMMANDS] = {2, 4, 1, 3, 5};
    int i, rc;
    clock_t start, end;
    double cpu_time_used;
    void * duration_sec;

    // Initialize the commands
    for (i = 0; i < NUM_COMMANDS; i++) {
        commands[i] = (Command*) malloc(sizeof(Command));
        commands[i]->name = (char*) malloc(sizeof(char) * 10);
        sprintf(commands[i]->name, "Command%d", i+1);
        commands[i]->duration = durations[i];
    }

    
    // Start the worker threads
    for (i = 0; i < NUM_COMMANDS; i++) {
        rc = pthread_create(&threads[i % NUM_THREADS], NULL, worker, (void*) commands[i]);
        if (rc) {
            printf("Error: return code from pthread_create() is %d\n", rc);
            exit(-1);
        }
    }

    // Wait for all worker threads to complete
    for (i = 0; i < NUM_THREADS; i++) {
        rc = pthread_join(threads[i], &duration_sec);
        printf(" Duration from pthread_join() is %d\n", *(int *)duration_sec );
        if (rc) {
            printf("Error: return code from pthread_join() is %d\n", rc);
            exit(-1);
        }
    }

    // Stop the clock and calculate the time
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Time taken: %f seconds\n", cpu_time_used);

    return 0;
}
