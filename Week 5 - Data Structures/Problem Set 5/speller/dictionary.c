// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
} node;

// TODO: Choose number of buckets in hash table
const unsigned int N = 65521;
// The choice of 65521 is a common practice to select a prime number that is close to but less than 2^16 (65536).
// Choosing 2^16 (65536) as the upper bound for the hash table size might be motivated by practical considerations.
// Historically, some systems and programming languages had limits on the size of arrays or data structures, and 2^16 is a value
// that falls within such limits. Additionally, it's a size that is comfortably handled by 16-bit systems.

// Hash table
node *table[N];
int wordcount = 0;

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // Hash the word to find the index
    unsigned int index = hash(word);

    // Traverse the linked list at that index
    for (node *cursor = table[index]; cursor != NULL; cursor = cursor->next)
    {
        // Compare the word with the current node's word
        if (strcasecmp(word, cursor->word) == 0)
        {
            // Word found in dictionary
            return true;
        }
    }

    // Word not found
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO: Improve this hash function
    unsigned int hash_value = 0;

    for (int i = 0; word[i] != '\0'; i++)
    {
        hash_value = (hash_value << 2) ^ tolower(word[i]);
    }
    return hash_value % N;
}
// The << is the left shift operator in C and many other programming languages.
// It performs a bitwise left shift operation on the left operand by the number of positions specified by the right operand.
// 'x << 2' means shifting the bits of x two positions to the left.

// The XOR (^) operation: This combines the two results. The XOR operation is commonly used in hash functions to create a good distribution of hash values.


// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    FILE *file = fopen(dictionary, "r");
    if (file == NULL)
    {
        fprintf(stderr, "Could not open %s.\n", dictionary);
        return false;
    }
    // Buffer to store each word
    char word[LENGTH + 1];

    // Read each word from the dictionary and add to hash table
    while (fscanf(file, "%s", word) != EOF)
    {
        // Create a new node
        node *new_node = malloc(sizeof(node));
        if (new_node == NULL)
        {
            fclose(file);
            return false;
        }

        // Copy the word into the node
        strcpy(new_node->word, word);

        // Hash the word to get the index
        unsigned int index = hash(word);

        // Insert the node at the beginning of the linked list at the index
        new_node->next = table[index];
        table[index] = new_node;

        // Increment word count
        wordcount++;
    }

    // Close dictionary file
    fclose(file);

    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    return wordcount;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    for (int i = 0; i < N; i++)
    {
        node *cursor = table[i];
        while (cursor != NULL)
        {
            node *temp = cursor;
            cursor = cursor->next;
            free(temp);
        }
    }
    return true;
}
