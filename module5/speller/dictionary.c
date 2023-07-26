// Implements a dictionary's functionality

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <strings.h>
#include <cs50.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node next;
}
node;

// Number of buckets in hash table
#define N 262626

// Hash table
nodetable[N];

// Number of total words
int total_words = 0;

// Returns true if word is in dictionary, else false
bool check(const char word)
{
    int index = hash(word);
    nodecursor = table[index];
    while (cursor != NULL)
    {
        // If word was found, return true
        if (strcasecmp(cursor->word, word) == 0)
        {
            return true;
        }
        // Or else, moves to next pointer
        cursor = cursor->next;
    }
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    int amount = 0;
    for (int i = 0; i < strlen(word); i++)
    {
        amount += tolower(word[i]);
    }
    return (amount % N);
}
[3:49 PM]
// Loads dictionary into memory, returning true if successful, else false
bool load(const char dictionary)
{
    // Open the file
    FILEdictionary_pointer = fopen(dictionary, "r");

    // Check if pointer is valid
    if (dictionary_pointer == NULL)
    {
        printf("Cannot open the file\n");
        return false;
    }

    // Variables
    char word_scan[LENGTH + 1];
    int hash_value = 0;

    // Loop through the file until the end
    while (fscanf(dictionary_pointer, "%s", word_scan) != EOF)
    {

        // Ask for memory with the size of a node
        node new_node = malloc(sizeof(node));

        // Check if is valid
        if (new_node == NULL)
        {
            printf("Cannot open the file\n");
            return false;
        }

        // Copy each word to file and set the pointer to NULL
        strcpy(new_node->word, word_scan);
        new_node->next = NULL;

        //Hash word
        hash_value = hash(word_scan);

        // If the pointer is NULL, set the new value
        if (table[hash_value] == NULL)
        {
            table[hash_value] = new_node;
            // Or else set the new_node first
        }
        else
        {
            new_node->next = table[hash_value];
            table[hash_value] = new_node;
        }
        total_words++;
    }
    // Close the file
    fclose(dictionary_pointer);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    return total_words;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    for (int i = 0; i < N; i++)
    {
        nodestart = table[i];
        node cursor = start;
        nodetemp = start;

        while (cursor != NULL)
        {
            cursor = cursor->next;
            free(temp);
            temp = cursor;
        }
    }
    return true;
}