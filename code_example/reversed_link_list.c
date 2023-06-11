#include <stdio.h>
#include <stdlib.h>

// Define a node structure for the linked list

struct Node {
    int data;
    struct Node* next;
};


// Function to reverse the linked list

void linkReverse(struct Node** head) {
    //define three pointers to Node parameters current = *head;=--
    struct Node* prev = NULL;
    struct Node* next = NULL;
    struct Node* current = NULL;

    current = *head;

    while(current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    *head = prev;

}
    

// Function to add a node to the head of the linked list


void addNode(struct Node** head,int data)
{
    struct Node* newNode;
    newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = *head;
    *head = newNode;

}




// Function to print the linked list
void printLinkedList(struct Node *head)
{

    struct Node* current;
    printf("\n");
    for(current = head;current !=NULL ; current = current->next )
    {
        printf("Node Data : %d \n",current->data);
    }


}

// Driver program to test the functions


int main() {
    struct Node* head = NULL;
    // Create a linked list 1 -> 2 -> 3 -> 4 -> 5
    addNode(&head, 5);
    addNode(&head, 4);
    addNode(&head, 3);
    addNode(&head, 2);
    addNode(&head, 1);

    printf("Original linked list: ");
    printLinkedList(head);

    linkReverse(&head);

    printf("Reversed linked list: ");
    printLinkedList(head);

    return 0;
}

