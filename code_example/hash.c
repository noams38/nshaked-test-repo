#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 10

struct node {
    char key[50];
    int value;
    struct node* next;
};

struct node* hash_table[SIZE];

int hash_function(char* key) {
    int sum = 0;
    for (int i = 0; i < strlen(key); i++) {
        sum += key[i];
    }
    return sum % SIZE;
}

void insert(char* key, int value) {
    int index = hash_function(key);
    struct node* new_node = (struct node*) malloc(sizeof(struct node));
    strcpy(new_node->key, key);
    new_node->value = value;
    new_node->next = NULL;

    if (hash_table[index] == NULL) {
        hash_table[index] = new_node;
    } else {
        struct node* current_node = hash_table[index];
        while (current_node->next != NULL) {
            current_node = current_node->next;
        }
        current_node->next = new_node;
    }
}

void print_hash_table() {
    for (int i = 0; i < SIZE; i++) {
        printf("%d: ", i);
        struct node* current_node = hash_table[i];
        while (current_node != NULL) {
            printf("(%s, %d) ", current_node->key, current_node->value);
            current_node = current_node->next;
        }
        printf("\n");
    }
}

int main() {
    insert("apple", 1);
    insert("banana", 2);
    insert("cherry", 3);
    insert("date", 4);
    insert("elderberry", 5);
    insert("fig", 6);
    insert("grape", 7);
    insert("honeydew", 8);
    insert("apple", 9); // This should overwrite the previous "apple" entry

    print_hash_table();

    return 0;
}
