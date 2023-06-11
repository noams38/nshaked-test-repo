#include <stdio.h>
#include <stdlib.h>


// define the Node data structure 

typedef struct Node {

    int data;
    struct Node * next;
}Node;


//define Top pointer to the top of the stack 

Node* top = NULL;


// define the fuction push to the stack 

void push(int value)
{
    Node* newNode = (Node*)malloc(sizeof(Node));

    if(newNode == NULL)
    {
        printf("new Node allocation failed");
        return;

    }

    newNode->data = value;
    newNode->next = top;
    top = newNode;

}


//define the function pop () to pull from the stack 

int pop(void)
{

    int element;
    Node * temp;

    if(top == NULL)
    {
        printf("stack is empty \n");
        return;

    }
    else
    {
        element = top->data;
        temp = top;
        top = top->next;
        free(temp);
        return element;
    }
    

}




int peek() {
  if (top == NULL) {
    printf("Error: stack is empty\n");
    return -1;
  } else {
    return top->data;
  }
}

int main() {
  push(1);
  push(2);
  push(3);

  printf("%d\n", pop());
  printf("%d\n", pop());
  printf("%d\n", peek());
  printf("%d\n", pop());
  printf("%d\n", pop());

  return 0;
}
