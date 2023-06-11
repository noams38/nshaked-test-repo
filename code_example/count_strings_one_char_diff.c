#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define HASH_TABLE_SIZE 10

typedef struct Node {
    char* value;
    struct Node* next;
} Node;

typedef struct HashTable {
    Node* buckets[HASH_TABLE_SIZE];
} HashTable;

int hash(char* str) {
    int hash = 0;
    for (int i = 0; i < strlen(str); i++) {
        hash = (hash * 31) + str[i];
    }
    return hash;
}

void addToHashTable(HashTable* ht, char* str) {
    int h = hash(str) % HASH_TABLE_SIZE;
    printf("hash str %s hash index %d \n",str, h);
    Node* node = (Node*)malloc(sizeof(Node));
    node->value = str;
    node->next = ht->buckets[h];
    ht->buckets[h] = node;
}

int countStrings(HashTable* ht) {
    int count = 0;
    for (int i = 0; i < HASH_TABLE_SIZE; i++) {
        Node* current = ht->buckets[i];
        while (current != NULL) {
            for (int j = i+1; i < HASH_TABLE_SIZE; j++) {
            Node* runner = ht->buckets[j];
            while (runner != NULL) {
                int diffCount = 0;
                for (int k = 0; k < strlen(current->value); k++) {
                    if (current->value[k] != runner->value[k]) {
                        diffCount++;
                        if (diffCount > 1) {
                            break;
                        }
                    }
                }
                if (diffCount == 1) {
                    count++;
                }
                
           }
            
        }
     }
   }

}
int main() {
    char* strings[] = {"cat", "cot", "cog", "dog", "dot"};
    int numStrings = 5;
    HashTable ht = {0};
    for (int i = 0; i < numStrings; i++) {
        addToHashTable(&ht, strings[i]);
    }
    int result = countStrings(&ht);
    printf("The largest amount of given strings that only one character is different among them is: %d", result);
    return 0;
}
