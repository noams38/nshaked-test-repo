#include <stdio.h>
#include <stdlib.h>


struct Queue {
    int *arr; //int array that will be allocated dynamically 
    int front; // fornt index of teh Queue 
    int rear; // rear  index of teh Queue 
    int size; // current size of teh Queue 
    int capacity; // tottal allocated size 
};





// function to create a new queue

struct Queue* create_queue(int Capacity)
{
    struct Queue* queue = (struct Queue*) malloc(sizeof(struct Queue));
    queue->arr = (int*) malloc (sizeof(int)* Capacity );
    queue->front = 0;
    queue->rear = -1;
    queue->size = 0;
    queue->capacity = Capacity;

    return queue;
}


// function to check if the queue is full

int is_full(struct Queue* queue)
{
    return (queue->size == queue->capacity);
        
}

int is_empty(struct Queue* queue)
{
    return queue->size == 0;     
}

// function to add an element to the rear of the queue

void enqueue(struct Queue* queue,int val)
{
    //check if queue is full
    if(is_full(queue)){
        printf("queue is full , cant enqueue new elements\n");
        return;

    }
        
    queue->rear = (queue->rear + 1) % queue->capacity;
    queue->arr[queue->rear] = val;
    queue->size++;
    

}

// function to remove an element from the front of the queue

int  dequeue(struct Queue* queue)
{
    int val;


    if(is_empty(queue))
    {
        printf("queue is empty nothing to dequeue\n");
        return -1;

    }
    val = queue->arr[queue->front];
    queue->front= (queue->front+1) % queue->capacity;
    queue->size--;

    return val;

}


// function to print the elements of the queue

int print_queue(struct Queue* queue)
{
    if(is_empty(queue))
    {
        printf("queue is empty nothing to print\n");
        return -1;

    }

    for (size_t i = (queue->front % queue->capacity) ; i <= (queue->rear % queue->capacity) ; i++)
    {
        printf(" %d ",queue->arr[i]);

        /* code */
    }
    printf("\n");
    

}








// main function to test the queue implementation
int main() {
    struct Queue* queue = create_queue(5);
    enqueue(queue, 1);
    enqueue(queue, 2);
    enqueue(queue, 3);
    enqueue(queue, 4);
    enqueue(queue, 5);

    print_queue(queue); // Queue: 1 2 3
    //printf("Front: %d\n", front(queue)); // Front: 1
    //printf("Rear: %d\n", rear(queue)); // Rear: 3
    dequeue(queue);
    dequeue(queue);
    dequeue(queue);
    print_queue(queue); // Queue: 2 3
    //printf("Front: %d\n", front(queue)); // Front: 2
    //printf("Rear: %d\n", rear(queue)); // Rear: 3
}
