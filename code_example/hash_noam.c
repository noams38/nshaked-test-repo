#include<stdio.h>
#include<stdlib.h>
#include<string.h>




#define SIZEOF_HASH 15
//create a Node 
typedef struct Node{
    char Name[10];
    int age;
    struct Node * next;

}person;


// create hash table 

struct Node hash_table[SIZEOF_HASH];


// calculate hash Index 

int hash_function(char* key) {
    int sum = 0;
    for (int i = 0; i < strlen(key); i++) {
        sum += key[i];
    }
    return sum % SIZEOF_HASH;
}

void hash_insert_node (char * name,int value )
{
    unsigned int index,n;
    person * node;
    person * node_to_iter;
    
    n = strlen(name);
    index = hash_function(name);
    printf(" %s =  %d \n",name , index);

    node = malloc(sizeof(person));
    node->age = value;
    strncpy (node->Name,name,n);

    //insert node based on index to the hash table 

    if (hash_table[index].next == NULL)
        hash_table[index].next = node;
    
    else
    {
        node_to_iter = hash_table[index].next;
        while(node_to_iter->next != NULL)
            node_to_iter = node_to_iter->next;
        node_to_iter->next = node;

    }





    return;

}


void print_hash_table() {
    for (int i = 0; i < SIZEOF_HASH; i++) {
        printf("%d: ", i);
        struct Node* current_node = hash_table[i].next;
        while (current_node != NULL) {
            printf("(%s, %d) ", current_node->Name, current_node->age);
            current_node = current_node->next;
        }
        printf("\n");
    }
}






void main (int argc, char** argv)
{

    // set hash table to all zero
    
    //alocate person
    hash_insert_node("Noam",10);    
    hash_insert_node("Liat",11);    
    hash_insert_node("Yoav",11);    
    hash_insert_node("Noya",11);    
    hash_insert_node("Mirit",11);    
    hash_insert_node("Itzhak",11);    

    print_hash_table();

}
