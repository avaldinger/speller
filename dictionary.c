// Implements a dictionary's functionality
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

#include "dictionary.h"

// size of the array
#define HASHTABLE 5000

// Represents a node in a Linked list
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;


unsigned long hash(char *word);
void init_table();

// Number of buckets in hash table
const unsigned int N = HASHTABLE;

// Hash table
node *table[N];


// Buffer to store 1 byte
char buffer[1];

int numberOfWords = 0;
bool loaded =   true;

// Returns true if word is in dictionary else false
bool check(char *word)
{
    bool found =  false;
    // Convert the word to be lowercase
    for (int i =0; word[i]; i++) {
        word[i] = tolower(word[i]);
    }
    // hash the word
    int id = hash(word);
        node *tmp = table[id];
    // Checks if there are any entry with that hash Id
    if (tmp != NULL) {
        // printf("Word in hash table: %s\n", tmp->word);
        if (strcmp(tmp->word, word) == 0) {
                found = true;
                return found;
        } else {
            while (tmp->next != NULL) {
                tmp = tmp->next;
                if (strcmp(tmp->word, word) == 0) {
                found = true;
                return found;
            }

        }
    }
        }
    return found;
}

// Hashes word to a number
unsigned long hash(char *word)
{
    unsigned long hash = 5381;
    int c;

    while ((c = *word++)) {
        hash = ((hash << 5) + hash) + c;
    }
    return hash % HASHTABLE;
}

// Loads dictionary into memory, returning true if successful else false
// char *dictionary is the name of the dictionary
bool load(const char *dictionary)
{
    // TODO
    char temp[LENGTH + 1];
    char *word = "";
    int character = 0;
    int byte = 0;
    int read = 0;
    init_table();
    //Open the file
    FILE *file = fopen(dictionary, "r");
    if (file == NULL)
    {
        loaded = false;
    }
    while (fread(buffer, 1, 1, file) == 1) {
        read++;
        // printf("Buffer 0: %c\n", buffer[0]);
        // printf("Reading...\n");
        // End of a word \0
        if (buffer[0] == 10) {
            // printf("\n");
            // printf("End of a word\n");
            numberOfWords++;
            temp[character] = '\0';
            // create a node
            node *n = malloc(sizeof(node));
            if (n != NULL) {
                for (int i = 0; i <= character; i++) {
                n->word[i] = temp[i];
                }
                n->next = NULL;
            }
            int key = hash(n->word);
            // printf("Key: %i\n", key);
            // printf("Word: %s\n", n->word);
            character = 0;
            // Add the node to the list
            if (table[key] == NULL) {
            table[key] = n;
            } else {
                node *tmp = table[key];
                while (tmp->next != NULL) {
                    tmp = tmp->next;
                }
                tmp->next = n;
            }
        // Start of a new word
        } else {
            temp[character] = buffer[0];
            byte = buffer[0];
            character++;
        }
    }
    printf("Read bytes: %i\n", read);
    /*for(int i = 0; i < HASHTABLE; i++){
        for (node *fasz = table[i]; fasz != NULL; fasz = fasz->next) {
            printf("Position in table:%i, %s\n", i, fasz->word);
            printf("Next element:%p\n", fasz->next);
        }
    }*/
    fclose(file);
    printf("Number of words loaded: %i\n", numberOfWords);
    return loaded;
}

// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    if (loaded) {
        return numberOfWords;
    } else {
    return 0;
    }
}

// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{
    // TODO
    // Go through all linked list inside the hash table
    for (int i =0; i<HASHTABLE; i++) {
        node *current = table[i];
        node *tmp = NULL;
    // checking that the linked list is not empty
    while (current != NULL) {

            tmp = current;
            current = current->next;
            free(tmp);
            }

    }
    return true;
}

// Initialize the hash table, not sure if actually needed?
void init_table() {
    printf("Initiate table\n");
    for(int i = 0; i<HASHTABLE; i++) {
    table[i] = NULL;
    //printf("Element of table: %i %p\n",i, table[i]);

}

}
